/*
 *
 * FocalTech ft5x06 TouchScreen driver header file.
 *
 * Copyright (c) 2010  Focal tech Ltd.
 * Copyright (c) 2012, The Linux Foundation. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef __LINUX_FT5X06_TS_H__
#define __LINUX_FT5X06_TS_H__

/*[PLATFORM]-Add-BEGIN by TCTNB.WPL, 2013/08/08, add for TP gesture detection function.*/
#ifdef CONFIG_8X30_TP_GESTURE
#define  GESTURE_V 0x14
#define  GESTURE_DB 0x16
#define  GESTURE_C 0x18

//#define DEBUG_TP_GESTURE

#define TPWAKEUP_IOCTL_MAGIC    'Z'
#define TPWAKEUP_IOCTL_OFF    _IO(TPWAKEUP_IOCTL_MAGIC, 0)
#define TPWAKEUP_IOCTL_ON    _IO(TPWAKEUP_IOCTL_MAGIC, 1)
#endif
/*[PLATFORM]-Add-END by TCTNB.WPL*/

/*[PLATFORM]-Add-BEGIN by TCTNB.WPL, 2013/01/10, add the TP ft5316 firmware upgrade function, refer to bug386588*/
#ifdef CONFIG_TOUCHSCREEN_FT5X06_FIRMWARE
#define IC_FT5X06	0
#define IC_FT5606	1
#define IC_FT5316	2

#define FT_UPGRADE_AA	0xAA
#define FT_UPGRADE_55 	0x55
#define FT_UPGRADE_EARSE_DELAY		2000

/*upgrade config of FT5606*/
#define FT5606_UPGRADE_AA_DELAY 		50
#define FT5606_UPGRADE_55_DELAY 		10
#define FT5606_UPGRADE_ID_1			0x79
#define FT5606_UPGRADE_ID_2			0x06
#define FT5606_UPGRADE_READID_DELAY 	100

/*upgrade config of FT5316*/
#define FT5316_UPGRADE_AA_DELAY 		50
#define FT5316_UPGRADE_55_DELAY 		40
#define FT5316_UPGRADE_ID_1			0x79
#define FT5316_UPGRADE_ID_2			0x07
#define FT5316_UPGRADE_READID_DELAY 	1

/*upgrade config of FT5x06(x=2,3,4)*/
#define FT5X06_UPGRADE_AA_DELAY 		50
#define FT5X06_UPGRADE_55_DELAY 		30
#define FT5X06_UPGRADE_ID_1			0x79
#define FT5X06_UPGRADE_ID_2			0x03
#define FT5X06_UPGRADE_READID_DELAY 	1


#define DEVICE_IC_TYPE	IC_FT5316

#define FTS_PACKET_LENGTH        128
#define FTS_SETTING_BUF_LEN        128

#define FTS_TX_MAX				40
#define FTS_RX_MAX				40
#define FTS_DEVICE_MODE_REG	0x00
#define FTS_TXNUM_REG			0x03
#define FTS_RXNUM_REG			0x04
#define FTS_RAW_READ_REG		0x01
#define FTS_RAW_BEGIN_REG		0x10
#define FTS_VOLTAGE_REG		0x05

#define FTS_FACTORYMODE_VALUE		0x40
#define FTS_WORKMODE_VALUE		0x00

/*register address*/
#define FT5x0x_REG_FW_VER		0xA6
#define FT5x0x_REG_POINT_RATE	0x88
#define FT5X0X_REG_THGROUP	0x80

#define AUTO_CLB
#define SYSFS_DEBUG

/*[PLATFORM]-Add-BEGIN by TCTNB.WPL, 2013/01/17, refer to bug390597*/
#define IS_JUNDA_TP 0x85
#define IS_MUTTO_TP 0x53
#define IS_OGS_TP   0x5a // for diabloLTE 1st
#define IS_TDT_TP   0x55 // for diabloLTE 2rd
int fts_ctpm_update_project_setting(struct i2c_client *client);
/*[PLATFORM]-Add-END by TCTNB.WPL*/

int ft5x06_i2c_read(struct i2c_client *client, char *writebuf, int writelen, char *readbuf, int readlen);
int ft5x06_i2c_write(struct i2c_client *client, char *writebuf, int writelen);

int fts_ctpm_fw_upgrade_with_i_file(struct i2c_client *client);
int fts_ctpm_auto_clb(struct i2c_client *client);

/*create sysfs for debug*/
int ft5x0x_create_sysfs(struct i2c_client * client);
void ft5x0x_release_mutex(void);
/*[PLATFORM]-Mod-BEGIN by TCTNB.YJ, 2013/07/19, refer to PR-490701 */
void ft5x06_ts_reset(void);
/*[PLATFORM]-Mod-END by TCTNB.YJ*/

#endif
/*[PLATFORM]-Mod-END by TCTNB.WPL*/

/*[PLATFORM]-Mod-BEGIN by TCTNB.YJ, 2013/07/19, refer to PR-490701 */
#ifdef CONFIG_TCT_8X30_COMMON
void ft5x06_ts_enable_irq_by_lcd(void);
#endif
/*[PLATFORM]-Mod-END by TCTNB.YJ*/

struct ft5x06_ts_platform_data {
	unsigned long irqflags;
	u32 x_max;
	u32 y_max;
	u32 irq_gpio;
	u32 reset_gpio;
/*[PLATFORM]-Mod-BEGIN by TCTNB.WPL, 2013/01/10, Add the wakeup control for viper/spyder, refer to bug386588 */
#ifdef CONFIG_TCT_8X30_COMMON
	u32 wakeup_gpio;
#endif
/*[PLATFORM]-Mod-END by TCTNB.WPL*/
	int (*power_init) (bool);
	int (*power_on) (bool);
};

#endif
