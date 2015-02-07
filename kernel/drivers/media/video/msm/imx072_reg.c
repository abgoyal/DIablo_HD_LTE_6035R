/* Copyright (c) 2011, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include "imx072.h"

struct imx072_i2c_reg_conf imx072_prev_settings[] = {
	{0x0340, 0x03},/*frame_length*/
	{0x0341, 0xF7},/*frame_length*/
	{0x0342, 0x0A},/*line_length*/
	{0x0343, 0xE0},/*line_length*/
	{0x0344, 0x00},/*x_addr_start*/
	{0x0345, 0x00},/*x_addr_start*/
	{0x0346, 0x00},/*y_addr_start*/
	{0x0347, 0x00},/*y_addr_start*/
	{0x0348, 0x0A},/*x_addr_end*/
	{0x0349, 0x2F},/*x_addr_end*/
	{0x034A, 0x07},/*y_addr_end*/
	{0x034B, 0xA7},/*y_addr_end*/
	{0x034C, 0x05},/*x_out_size*/
	{0x034D, 0x18},/*x_out_size*/
	{0x034E, 0x03},/*y_out_size*/
	{0x034F, 0xD4},/*y_out_size*/
	{0x0381, 0x01},/*x_even_inc*/
	{0x0383, 0x03},/*x_odd_inc*/
	{0x0385, 0x01},/*y_even_inc*/
	{0x0387, 0x03},/*y_odd_inc*/
	{0x3016, 0x06},/*VMODEADD*/
	{0x3017, 0x40},
	{0x3069, 0x24},
	{0x306A, 0x00},
	{0x306B, 0xCB},
	{0x306C, 0x07},
	{0x30E8, 0x86},
	{0x3304, 0x03},
	{0x3305, 0x02},
	{0x3306, 0x0A},
	{0x3307, 0x02},
	{0x3308, 0x11},
	{0x3309, 0x04},
	{0x330A, 0x05},
	{0x330B, 0x04},
	{0x330C, 0x05},
	{0x330D, 0x04},
	{0x330E, 0x01},
	{0x3301, 0x80},
};

struct imx072_i2c_reg_conf imx072_snap_settings[] = {
	{0x0340, 0x07},/*frame_length*/
	{0x0341, 0xEE},/*frame_length*/
	{0x0342, 0x0A},/*line_length*/
	{0x0343, 0xE0},/*line_length*/
	{0x0344, 0x00},/*x_addr_start*/
	{0x0345, 0x00},/*x_addr_start*/
	{0x0346, 0x00},/*y_addr_start*/
	{0x0347, 0x00},/*y_addr_start*/
	{0x0348, 0x0A},/*x_addr_end*/
	{0x0349, 0x2F},/*x_addr_end*/
	{0x034A, 0x07},/*y_addr_end*/
	{0x034B, 0xA7},/*y_addr_end*/
	{0x034C, 0x0A},/*x_out_size*/
	{0x034D, 0x30},/*x_out_size*/
	{0x034E, 0x07},/*y_out_size*/
	{0x034F, 0xA8},/*y_out_size*/
	{0x0381, 0x01},/*x_even_inc*/
	{0x0383, 0x01},/*x_odd_inc*/
	{0x0385, 0x01},/*y_even_inc*/
	{0x0387, 0x01},/*y_odd_inc*/
	{0x3016, 0x06},/*VMODEADD*/
	{0x3017, 0x40},
	{0x3069, 0x24},
	{0x306A, 0x00},
	{0x306B, 0xCB},
	{0x306C, 0x07},
	{0x30E8, 0x06},
	{0x3304, 0x05},
	{0x3305, 0x04},
	{0x3306, 0x15},
	{0x3307, 0x02},
	{0x3308, 0x11},
	{0x3309, 0x07},
	{0x330A, 0x05},
	{0x330B, 0x04},
	{0x330C, 0x05},
	{0x330D, 0x04},
	{0x330E, 0x01},
	{0x3301, 0x00},
};

struct imx072_i2c_reg_conf imx072_recommend_settings[] = {
	{0x0307, 0x12},
	{0x302B, 0x4B},
	{0x0101, 0x03},
	{0x300A, 0x80},
	{0x3014, 0x08},
	{0x3015, 0x37},
	{0x3017, 0x40},
	{0x301C, 0x01},
	{0x3031, 0x28},
	{0x3040, 0x00},
	{0x3041, 0x60},
	{0x3051, 0x24},
	{0x3053, 0x34},
	{0x3055, 0x3B},
	{0x3057, 0xC0},
	{0x3060, 0x30},
	{0x3065, 0x00},
	{0x30AA, 0x88},
	{0x30AB, 0x1C},
	{0x30B0, 0x32},
	{0x30B2, 0x83},
	{0x30D3, 0x04},
	{0x310E, 0xDD},
	{0x31A4, 0xD8},
	{0x31A6, 0x17},
	{0x31AC, 0xCF},
	{0x31AE, 0xF1},
	{0x31B4, 0xD8},
	{0x31B6, 0x17},
	{0x3304, 0x05},
	{0x3305, 0x04},
	{0x3306, 0x15},
	{0x3307, 0x02},
	{0x3308, 0x11},
	{0x3309, 0x07},
	{0x330A, 0x05},
	{0x330B, 0x04},
	{0x330C, 0x05},
	{0x330D, 0x04},
	{0x330E, 0x01},
	{0x30d8, 0x20},
};

struct imx072_i2c_conf_array imx072_confs[] = {
	{&imx072_prev_settings[0], ARRAY_SIZE(imx072_prev_settings)},
	{&imx072_snap_settings[0], ARRAY_SIZE(imx072_snap_settings)},
};

struct imx072_reg imx072_regs = {
	.rec_settings = &imx072_recommend_settings[0],
	.rec_size = ARRAY_SIZE(imx072_recommend_settings),
	.conf_array = &imx072_confs[0],
};
