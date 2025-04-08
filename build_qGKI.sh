#!/bin/bash

echo -e "\n[INFO]: BUILD STARTED..!\n"

#init submodules
git submodule init && git submodule update

export KERNEL_ROOT="$(pwd)"
export ARCH=arm64
export KBUILD_BUILD_USER="@ravindu644"

#setting up localversion
if [ -z "$BUILD_KERNEL_VERSION" ]; then
    export BUILD_KERNEL_VERSION="dev"
fi

echo -e "CONFIG_LOCALVERSION_AUTO=n\nCONFIG_LOCALVERSION=\"-ravindu644-${BUILD_KERNEL_VERSION}\"\n" > "${KERNEL_ROOT}/arch/arm64/configs/version.config"

# Install the requirements for building the kernel when running the script for the first time
if [ ! -f ".requirements" ]; then
    sudo apt update && sudo apt install -y git device-tree-compiler lz4 xz-utils zlib1g-dev openjdk-17-jdk gcc g++ python3 python-is-python3 p7zip-full android-sdk-libsparse-utils erofs-utils \
        default-jdk git gnupg flex bison gperf build-essential zip curl libc6-dev libncurses-dev libx11-dev libreadline-dev libgl1 libgl1-mesa-dev \
        python3 make sudo gcc g++ bc grep tofrodos python3-markdown libxml2-utils xsltproc zlib1g-dev python-is-python3 libc6-dev libtinfo6 \
        make repo cpio kmod openssl libelf-dev pahole libssl-dev libarchive-tools zstd --fix-missing && wget http://security.ubuntu.com/ubuntu/pool/universe/n/ncurses/libtinfo5_6.3-2ubuntu0.1_amd64.deb && sudo dpkg -i libtinfo5_6.3-2ubuntu0.1_amd64.deb && touch .requirements
fi

# Create necessary directories
mkdir -p "${KERNEL_ROOT}/out" "${KERNEL_ROOT}/build" "${HOME}/toolchains"

# init snapdragon llvm
if [ ! -d "${HOME}/toolchains/llvm-arm-toolchain-ship" ]; then
    echo -e "\n[INFO] Cloning Snapdragon LLVM...\n"
    cd "${HOME}/toolchains" && curl -LO "https://github.com/ravindu644/Android-Kernel-Tutorials/releases/download/toolchains/llvm-arm-toolchain-ship-10.0.9.tar.gz"
    tar -xf llvm-arm-toolchain-ship-10.0.9.tar.gz && rm llvm-arm-toolchain-ship-10.0.9.tar.gz
    cd "${KERNEL_ROOT}"
fi

# init arm gnu toolchain
if [ ! -d "${HOME}/toolchains/gcc" ]; then
    echo -e "\n[INFO] Cloning ARM GNU Toolchain\n"
    mkdir -p "${HOME}/toolchains/gcc" && cd "${HOME}/toolchains/gcc"
    curl -LO "https://developer.arm.com/-/media/Files/downloads/gnu/14.2.rel1/binrel/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu.tar.xz"
    tar -xf arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu.tar.xz
    cd "${KERNEL_ROOT}"
fi

# Export toolchain paths
export PATH="${PATH}:${HOME}/toolchains/llvm-arm-toolchain-ship/10.0.9/bin"
export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${HOME}/toolchains/llvm-arm-toolchain-ship/10.0.9/lib"

# Set cross-compile environment variables
export BUILD_CROSS_COMPILE="${HOME}/toolchains/gcc/arm-gnu-toolchain-14.2.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-"
export BUILD_CC="${HOME}/toolchains/llvm-arm-toolchain-ship/10.0.9/bin/clang"

# Build options for the kernel
export BUILD_OPTIONS="
-C ${KERNEL_ROOT} \
O=${KERNEL_ROOT}/out \
-j$(nproc) \
ARCH=arm64 \
CROSS_COMPILE=${BUILD_CROSS_COMPILE} \
CC=${BUILD_CC} \
CLANG_TRIPLE=aarch64-linux-gnu- \
"

build_kernel(){
    set -e
    # Make default configuration.
    # Replace 'your_defconfig' with the name of your kernel's defconfig
    make ${BUILD_OPTIONS} vendor/gta9p_eur_openx_defconfig custom.config version.config

    # Configure the kernel (GUI)
    make ${BUILD_OPTIONS} menuconfig

    # Build the kernel
    make ${BUILD_OPTIONS} Image

    # Copy the built kernel to the build directory
    cp "${KERNEL_ROOT}/out/arch/arm64/boot/Image" "${KERNEL_ROOT}/build"

    echo -e "\n[INFO]: BUILD FINISHED..!"
    set +e
}

build_boot(){
    set -e
    cp "${KERNEL_ROOT}/prebuilt_images/"* "${KERNEL_ROOT}/Android_boot_image_editor"
    cd "${KERNEL_ROOT}/Android_boot_image_editor" && ./gradlew unpack
    cp "${KERNEL_ROOT}/build/Image" "build/unzip_boot/kernel" && ./gradlew pack
    cp "${KERNEL_ROOT}/Android_boot_image_editor/boot.img.signed" "${KERNEL_ROOT}/build/boot.img"
    cp "${KERNEL_ROOT}"
    set +e
}

build_tar(){
    echo -e "\n[INFO] Creating an Odin flashable tar..\n"

    cd "${KERNEL_ROOT}/build"
    tar -cvf "KernelSU-Next-SM-X216B-${BUILD_KERNEL_VERSION}.tar" boot.img && rm boot.img
    echo -e "\n[INFO] Build Finished..!\n" && cd ${KERNEL_ROOT}
}

build_kernel
build_boot
build_tar
