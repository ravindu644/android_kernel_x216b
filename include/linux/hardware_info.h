#ifndef __HARDWARE_H__
#define __HARDWARE_H__

#define HARDWARE_MAX_ITEM_LONGTH		64

enum{
	HARDWARE_LCD = 0,
	HARDWARE_TP,
	HARDWARE_FLASH,
 	HARDWARE_FRONT_CAM,
 	HARDWARE_BACK_CAM,
 	HARDWARE_BACK_WIDE_CAM,
 	HARDWARE_BACK_SUBCAM,     //this camera is back depth
 	HARDWARE_BACK_MACRO_CAM,
 	HARDWARE_BT,
 	HARDWARE_WIFI,
 	HARDWARE_ACCELEROMETER,
 	HARDWARE_ALSPS,
 	HARDWARE_GYROSCOPE,
 	HARDWARE_MAGNETOMETER,
 	HARDWARE_SAR,//bug 417945 , add sar info, chenrongli.wt, 20181218
 	HARDWARE_GPS,
 	HARDWARE_FM,
         HARDWARE_NFC,//bug 494418 ,chenyuxiang.wt,2019.10.24,add nfc info
     HARDWARE_SMARTPA,//bug 504721,20191107,baoshulin,add smartpa in hardwareInfo
 	HARDWARE_BATTERY_ID,
 	HARDWARE_BACK_CAM_MOUDULE_ID,
 	HARDWARE_BACK_WIDE_CAM_MOUDULE_ID,
 	HARDWARE_BACK_SUBCAM_MODULEID,
 	HARDWARE_FRONT_CAM_MOUDULE_ID,
 	HARDWARE_BACK_MACRO_CAM_MOUDULE_ID,
 	HARDWARE_BOARD_ID,
 	//bug438403,wuyuexiu_wt,add,2019/4/16,add hardware id
 	HARDWARE_HARDWARE_ID,
 	HARDWARE_CHARGER_IC,//Bug489541 gudi.wt,MODIFIY,20191107,S89730 add charge ic info
 	HARDWARE_BMS_GAUGE,//Bug489541 gudi.wt,MODIFIY,20191107,S89730 add QG info
 	HARDWARE_MCU,//P86801AA1-1797, caoxin2.wt, add, 20230525, add mcu info
	#ifdef CONFIG_QGKI_BUILD
	HARDWARE_LCD_SERIALNUM,/*P86801AA1, wangcong.wt, ADD, 2023/08/25, add lcm_serialnum */
	#endif
	//+P86801AA1, caoxin2.wt, add, 20230829, add mcu info
	HARDWARE_PAD_MCU,
	HARDWARE_KB_MCU,
	//-P86801AA1, caoxin2.wt, add, 20230829, add mcu info
 	HARDWARE_MAX_ITEM
 };
 
 
 #define HARDWARE_ID                               'H'
 #define HARDWARE_LCD_GET                          _IOWR(HARDWARE_ID, 0x01, char[HARDWARE_MAX_ITEM_LONGTH])      //  LCD
 #define HARDWARE_TP_GET                           _IOWR(HARDWARE_ID, 0x02, char[HARDWARE_MAX_ITEM_LONGTH])      //  TP
 #define HARDWARE_FLASH_GET                        _IOWR(HARDWARE_ID, 0x03, char[HARDWARE_MAX_ITEM_LONGTH])      //  FLASH
 #define HARDWARE_FRONT_CAM_GET                    _IOWR(HARDWARE_ID, 0x04, char[HARDWARE_MAX_ITEM_LONGTH])      //  前摄
 #define HARDWARE_BACK_CAM_GET                     _IOWR(HARDWARE_ID, 0x05, char[HARDWARE_MAX_ITEM_LONGTH])      //  后摄
 #define HARDWARE_ACCELEROMETER_GET                _IOWR(HARDWARE_ID, 0x06, char[HARDWARE_MAX_ITEM_LONGTH])      //  加速度传感器
 #define HARDWARE_ALSPS_GET                        _IOWR(HARDWARE_ID, 0x07, char[HARDWARE_MAX_ITEM_LONGTH])      //  距离光感
 #define HARDWARE_GYROSCOPE_GET                    _IOWR(HARDWARE_ID, 0x08, char[HARDWARE_MAX_ITEM_LONGTH])      //  陀螺仪
 #define HARDWARE_MAGNETOMETER_GET                 _IOWR(HARDWARE_ID, 0x09, char[HARDWARE_MAX_ITEM_LONGTH])      //  地磁
 #define HARDWARE_BT_GET                           _IOWR(HARDWARE_ID, 0x10, char[HARDWARE_MAX_ITEM_LONGTH])      //  蓝牙
 #define HARDWARE_WIFI_GET                         _IOWR(HARDWARE_ID, 0x11, char[HARDWARE_MAX_ITEM_LONGTH])      //  WIFI
 #define HARDWARE_GPS_GET                          _IOWR(HARDWARE_ID, 0x12, char[HARDWARE_MAX_ITEM_LONGTH])      //  GPS
 #define HARDWARE_FM_GET                           _IOWR(HARDWARE_ID, 0x13, char[HARDWARE_MAX_ITEM_LONGTH])      //  FM
 #define HARDWARE_BATTERY_ID_GET                   _IOWR(HARDWARE_ID, 0x15, char[HARDWARE_MAX_ITEM_LONGTH])      //  电池
 #define HARDWARE_BACK_CAM_MOUDULE_ID_GET          _IOWR(HARDWARE_ID, 0x16, char[HARDWARE_MAX_ITEM_LONGTH])      //  后摄模组厂
 #define HARDWARE_FRONT_CAM_MODULE_ID_GET          _IOWR(HARDWARE_ID, 0x17, char[HARDWARE_MAX_ITEM_LONGTH])      //  前摄模组厂
 #define HARDWARE_BOARD_ID_GET                     _IOWR(HARDWARE_ID, 0x18, char[HARDWARE_MAX_ITEM_LONGTH])      //  board id
 #define HARDWARE_FRONT_FISH_CAM_GET               _IOWR(HARDWARE_ID, 0x19, char[HARDWARE_MAX_ITEM_LONGTH])      // 前鱼眼
 #define HARDWARE_BACK_FISH_CAM_GET                _IOWR(HARDWARE_ID, 0x1A, char[HARDWARE_MAX_ITEM_LONGTH])      //  后鱼眼
 #define HARDWARE_HALL_GET                         _IOWR(HARDWARE_ID, 0x1B, char[HARDWARE_MAX_ITEM_LONGTH])      //  hall sensor
 #define HARDWARE_PRESSURE_GET                     _IOWR(HARDWARE_ID, 0x1C, char[HARDWARE_MAX_ITEM_LONGTH])      //  气压传感器
 #define HARDWARE_NFC_GET                          _IOWR(HARDWARE_ID, 0x1D, char[HARDWARE_MAX_ITEM_LONGTH])      //  NFC
 #define HARDWARE_FRONT_SUBCAM_GET                 _IOWR(HARDWARE_ID, 0x1E, char[HARDWARE_MAX_ITEM_LONGTH])      //  前摄是双摄，前副摄像头
 #define HARDWARE_BACK_SUBCAM_GET                  _IOWR(HARDWARE_ID, 0x1F, char[HARDWARE_MAX_ITEM_LONGTH])      //  后摄是双摄，后副摄像头
 #define HARDWARE_FRONT_FISH_CAM_MOUDULE_ID_GET    _IOWR(HARDWARE_ID, 0x20, char[HARDWARE_MAX_ITEM_LONGTH])      //  前鱼眼模组厂
 #define HARDWARE_BACK_FISH_CAM_MOUDULE_ID_GET     _IOWR(HARDWARE_ID, 0x21, char[HARDWARE_MAX_ITEM_LONGTH])      // 后鱼眼模组厂
 #define HARDWARE_HARDWARE_ID_GET                  _IOWR(HARDWARE_ID, 0x22, char[HARDWARE_MAX_ITEM_LONGTH])      //hardwareid
 
 #define HARDWARE_FRONT_SUBCAM_MODULEID_GET        _IOWR(HARDWARE_ID, 0x23, char[HARDWARE_MAX_ITEM_LONGTH])      //  前摄是双摄，前副摄像头
 #define HARDWARE_BACK_SUBCAM_MODULEID_GET         _IOWR(HARDWARE_ID, 0x24, char[HARDWARE_MAX_ITEM_LONGTH])      //  后摄是双摄，后副摄像头
 #define HARDWARE_BACK_CAM_EFUSEID_GET             _IOWR(HARDWARE_ID, 0x25, char[HARDWARE_MAX_ITEM_LONGTH])      //  后摄efuseId
 #define HARDWARE_BCAK_SUBCAM_EFUSEID_GET          _IOWR(HARDWARE_ID, 0x26, char[HARDWARE_MAX_ITEM_LONGTH])      //  后副摄efuseId
 #define HARDWARE_FRONT_CAME_EFUSEID_GET           _IOWR(HARDWARE_ID, 0x27, char[HARDWARE_MAX_ITEM_LONGTH])      //  前摄efuseId
 #define HARDWARE_FRONT_SUBCAME_EFUSEID_GET        _IOWR(HARDWARE_ID, 0x28, char[HARDWARE_MAX_ITEM_LONGTH])      //  前副摄efuseId
 #define HARDWARE_BACK_CAM_SENSORID_GET            _IOWR(HARDWARE_ID, 0x29, char[HARDWARE_MAX_ITEM_LONGTH])      //  后摄sensorId
 #define HARDWARE_BACK_SUBCAM_SENSORID_GET         _IOWR(HARDWARE_ID, 0x30, char[HARDWARE_MAX_ITEM_LONGTH])      //  后副摄sensorId
 #define HARDWARE_FRONT_CAM_SENSORID_GET           _IOWR(HARDWARE_ID, 0x31, char[HARDWARE_MAX_ITEM_LONGTH])      //  前摄sensorId
 #define HARDWARE_FRONT_SUBCAM_SENSORID_GET        _IOWR(HARDWARE_ID, 0x32, char[HARDWARE_MAX_ITEM_LONGTH])      //  前副摄sensorId
 //bug 349613,20180409,huwei2,add Sar in hardwareInfo
 #define HARDWARE_SAR_GET                          _IOWR(HARDWARE_ID, 0x33, char[HARDWARE_MAX_ITEM_LONGTH])      //sar
 
 #define HARDWARE_BACK_WIDE_CAM_GET                                _IOWR(HARDWARE_ID, 0x34, char[HARDWARE_MAX_ITEM_LONGTH])   //add for N9 wide camera
 #define HARDWARE_BACK_WIDE_CAM_MOUDULE_ID_GET          _IOWR(HARDWARE_ID, 0x35, char[HARDWARE_MAX_ITEM_LONGTH])
 #define HARDWARE_BACK_WIDE_CAM_EFUSEID_GET                  _IOWR(HARDWARE_ID, 0x36, char[HARDWARE_MAX_ITEM_LONGTH])
 #define HARDWARE_BACK_WIDE_CAM_SENSORID_GET               _IOWR(HARDWARE_ID, 0x37, char[HARDWARE_MAX_ITEM_LONGTH])
 
 #define HARDWARE_BACK_MACRO_CAM_GET                _IOWR(HARDWARE_ID, 0x3C, char[HARDWARE_MAX_ITEM_LONGTH])   //add for N30 macro camera
 #define HARDWARE_BACK_MACRO_CAM_MOUDULE_ID_GET     _IOWR(HARDWARE_ID, 0x3D, char[HARDWARE_MAX_ITEM_LONGTH])
 #define HARDWARE_BACK_MACRO_CAM_EFUSEID_GET        _IOWR(HARDWARE_ID, 0x3E, char[HARDWARE_MAX_ITEM_LONGTH])
 #define HARDWARE_BACK_MACRO_CAM_SENSORID_GET       _IOWR(HARDWARE_ID, 0x3F, char[HARDWARE_MAX_ITEM_LONGTH])
 //bug 504721,20191107,baoshulin,add smartpa in hardwareInfo
 #define HARDWARE_SMARTPA_IC_GET                    _IOWR(HARDWARE_ID, 0x40, char[HARDWARE_MAX_ITEM_LONGTH])
 /* Bug 538123, zhangbin2.wt, 20200311, Add for battery info */
 #define HARDWARE_BMS_GAUGE_GET     	     		  _IOWR(HARDWARE_ID, 0x41, char[HARDWARE_MAX_ITEM_LONGTH])
 /*+P86801AA1-1797, caoxin2.wt, add, 20230525, add for mcu */
 #define HARDWARE_MCU_GET                          _IOWR(HARDWARE_ID, 0x49, char[HARDWARE_MAX_ITEM_LONGTH])
 /*-P86801AA1-1797, caoxin2.wt, add, 20230525, add for mcu */
 #define HARDWARE_BACK_CAM_MOUDULE_ID_SET          _IOWR(HARDWARE_ID, 0x81, char[HARDWARE_MAX_ITEM_LONGTH])
 #define HARDWARE_FRONT_CAM_MODULE_ID_SET          _IOWR(HARDWARE_ID, 0x82, char[HARDWARE_MAX_ITEM_LONGTH])
 #define HARDWARE_SDCARD_STATUS                    _IOWR(HARDWARE_ID, 0x83, char[HARDWARE_MAX_ITEM_LONGTH])
  #define HARDWARE_FINGER_GET                       _IOWR(HARDWARE_ID, 0x84, char[HARDWARE_MAX_ITEM_LONGTH])
  
  
  /*+Bug 313110 -  guojunbo.wt;add;20171026;add for lg sku */
  #define HARDWARE_SKU_INFO_GET                     _IOWR(HARDWARE_ID, 0x85, char[HARDWARE_MAX_ITEM_LONGTH])
  #define HARDWARE_CHARGER_IC_INFO_GET              _IOWR(HARDWARE_ID, 0x86, char[HARDWARE_MAX_ITEM_LONGTH])
  /*-Bug 313110 -  guojunbo.wt;add;20171026;add for lg sku */
  
  #define HARDWARE_SECURE_INFO_GET                  _IOWR(HARDWARE_ID, 0x87, char[HARDWARE_MAX_ITEM_LONGTH])
  #define SOFTWARE_SECURE_INFO_GET                  _IOWR(HARDWARE_ID, 0x88, char[HARDWARE_MAX_ITEM_LONGTH])
  /*+P86801AA1, wangcong.wt, ADD, 2023/08/25, add lcm_serialnum*/
  #ifdef CONFIG_QGKI_BUILD
  #define HARDWARE_LCD_SERIALNUM_GET                _IOWR(HARDWARE_ID, 0x89, char[HARDWARE_MAX_ITEM_LONGTH])
  #endif
  /*-P86801AA1, wangcong.wt, ADD, 2023/08/25, add lcm_serialnum*/
  /*+P86801AA1, caoxin2.wt, add, 20230829, add 2 mcu version*/
  #define HARDWARE_PAD_MCU_GET                _IOWR(HARDWARE_ID, 0x8C, char[HARDWARE_MAX_ITEM_LONGTH])
  #define HARDWARE_KB_MCU_GET                _IOWR(HARDWARE_ID, 0x8D, char[HARDWARE_MAX_ITEM_LONGTH])
  /*-P86801AA1, caoxin2.wt, add, 20230829, add mcu 2 mcu version*/
//+P86801AA1, daisiqing.wt, ADD, 2022/04/28, add smartpa info for mmitest
int snd_soc_set_smartpa_type(const char * name,int pa_type);
//-P86801AA1, daisiqing.wt, ADD, 2022/04/28, add smartpa info for mmitest

  int hardwareinfo_set_prop(int cmd, const char *name);
  
  #endif //__HARDWARE_H__
  