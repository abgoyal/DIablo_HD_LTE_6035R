/* Copyright (c) 2011-2012, The Linux Foundation. All rights reserved.
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

#include <linux/gpio.h>
#include <asm/mach-types.h>
#include <mach/gpiomux.h>
#include <mach/socinfo.h>
#include "devices.h"
#include "board-8930.h"

/* [PLATFORM]-Del-BEGIN by TCTNB.Alvin, 2012/10/12, SPI configuration is not used on Viper */
#if 0
/* The SPI configurations apply to GSBI 1*/
static struct gpiomux_setting spi_active = {
	.func = GPIOMUX_FUNC_1,
	.drv = GPIOMUX_DRV_12MA,
	.pull = GPIOMUX_PULL_NONE,
};

static struct gpiomux_setting spi_suspended_config = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_DOWN,
};
#endif
/* [PLATFORM]-Del-END by TCTNB.Alvin */

/* [PLATFORM]-Add-BEGIN by TCTNB.Alvin, 2012/10/12, GSBI1&GSBI2 are used as I2C on Viper */
static struct gpiomux_setting gsbi1 = {
    .func = GPIOMUX_FUNC_2,
    .drv = GPIOMUX_DRV_8MA,
    .pull = GPIOMUX_PULL_NONE,
};

static struct gpiomux_setting gsbi2 = {
    .func = GPIOMUX_FUNC_2,
    .drv = GPIOMUX_DRV_8MA,
    .pull = GPIOMUX_PULL_NONE,
};
/* [PLATFORM]-Add-END by TCTNB.Alvin */

static struct gpiomux_setting gsbi3_suspended_cfg = {
	.func = GPIOMUX_FUNC_1,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_KEEPER,
};

static struct gpiomux_setting gsbi3_active_cfg = {
	.func = GPIOMUX_FUNC_1,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
};

/* [PLATFORM]-Del-BEGIN by TCTNB.Alvin, 2012/10/12, GSBI5 is not used on Viper */
#if 0
static struct gpiomux_setting gsbi5 = {
	.func = GPIOMUX_FUNC_1,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
};
#endif
/* [PLATFORM]-Del-END by TCTNB.Alvin */

static struct gpiomux_setting gsbi9 = {
	.func = GPIOMUX_FUNC_2,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
};

/* [PLATFORM]-Del-BEGIN by TCTNB.Alvin, 2012/10/12, GSBI10 is not used on Viper */
#if 0
static struct gpiomux_setting gsbi10 = {
	.func = GPIOMUX_FUNC_2,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
};
#endif
/* [PLATFORM]-Del-END by TCTNB.Alvin */
//[BUGFIX]-Add-BEGIN by Miao FR-403494, 2013/02/02
static struct gpiomux_setting gsbi11 = {
    .func = GPIOMUX_FUNC_1,
    .drv = GPIOMUX_DRV_2MA,
    .pull = GPIOMUX_PULL_DOWN,
};
//[BUGFIX]-Add-END

static struct gpiomux_setting gsbi12 = {
	.func = GPIOMUX_FUNC_1,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
};

static struct gpiomux_setting cdc_mclk = {
	.func = GPIOMUX_FUNC_1,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
};

static struct gpiomux_setting audio_auxpcm[] = {
	/* Suspended state */
	{
		.func = GPIOMUX_FUNC_GPIO,
		.drv = GPIOMUX_DRV_2MA,
		.pull = GPIOMUX_PULL_NONE,
	},
	/* Active state */
	{
		.func = GPIOMUX_FUNC_1,
		.drv = GPIOMUX_DRV_2MA,
		.pull = GPIOMUX_PULL_NONE,
	},
};

/* [PLATFORM]-Add-BEGIN by TCTNB.YJ, 2013/2/23, lcd id pin on viper */
static struct gpiomux_setting lcd_id_pin[] = {
	/* Suspended state */
	{
		.func = GPIOMUX_FUNC_GPIO,
		.drv = GPIOMUX_DRV_2MA,
		.pull = GPIOMUX_PULL_DOWN,
	},
	/* Active state */
	{
		.func = GPIOMUX_FUNC_GPIO,
		.drv = GPIOMUX_DRV_2MA,
		.pull = GPIOMUX_PULL_DOWN,
	},
};
/* [PLATFORM]-add-END by TCTNB.YJ */

static struct gpiomux_setting audio_mbhc = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
};

/* [PLATFORM]-Del-BEGIN by TCTNB.Alvin, 2012/10/12, audio spkr boost is not used on Viper */
#if 0
static struct gpiomux_setting audio_spkr_boost = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_DOWN,
};
#endif
/* [PLATFORM]-Del-END by TCTNB.Alvin */

#if defined(CONFIG_KS8851) || defined(CONFIG_KS8851_MODULE)
static struct gpiomux_setting gpio_eth_config = {
	.pull = GPIOMUX_PULL_NONE,
	.drv = GPIOMUX_DRV_8MA,
	.func = GPIOMUX_FUNC_GPIO,
};
#endif

static struct gpiomux_setting slimbus = {
	.func = GPIOMUX_FUNC_1,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_KEEPER,
};

static struct gpiomux_setting wcnss_5wire_suspend_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv  = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_UP,
};

static struct gpiomux_setting wcnss_5wire_active_cfg = {
	.func = GPIOMUX_FUNC_1,
	.drv  = GPIOMUX_DRV_6MA,
	.pull = GPIOMUX_PULL_DOWN,
};

/* [PLATFORM]-Del-BEGIN by TCTNB.Alvin, 2012/10/12, Atmel TS is not used on Viper */
#if 0
static struct gpiomux_setting atmel_resout_sus_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_6MA,
	.pull = GPIOMUX_PULL_DOWN,
};

static struct gpiomux_setting atmel_resout_act_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_6MA,
	.pull = GPIOMUX_PULL_UP,
};

static struct gpiomux_setting atmel_ldo_en_sus_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_6MA,
	.pull = GPIOMUX_PULL_DOWN,
};

static struct gpiomux_setting atmel_ldo_en_act_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_6MA,
	.pull = GPIOMUX_PULL_DOWN,
};

static struct gpiomux_setting atmel_int_act_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_UP,
};

static struct gpiomux_setting atmel_int_sus_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_DOWN,
};
#endif
/* [PLATFORM]-Del-END by TCTNB.Alvin */

/* [PLATFORM]-Add-BEGIN by TCTNB.Alvin, 2012/10/12, GPIO configruation for touch screen */
static struct gpiomux_setting ts_int_act_cfg = {
    .func = GPIOMUX_FUNC_GPIO,
    .drv = GPIOMUX_DRV_8MA,
    .pull = GPIOMUX_PULL_UP,
};

static struct gpiomux_setting ts_int_sus_cfg = {
    .func = GPIOMUX_FUNC_GPIO,
    .drv = GPIOMUX_DRV_2MA,
    .pull = GPIOMUX_PULL_DOWN,
};

static struct gpiomux_setting ts_wakeup_act_cfg = {
    .func = GPIOMUX_FUNC_GPIO,
    .drv = GPIOMUX_DRV_2MA,
    .pull = GPIOMUX_PULL_NONE,
};
    
static struct gpiomux_setting ts_wakeup_sus_cfg = {
    .func = GPIOMUX_FUNC_GPIO,
    .drv = GPIOMUX_DRV_2MA,
    .pull = GPIOMUX_PULL_NONE,
};

static struct gpiomux_setting ts_reset_sus_cfg = {
    .func = GPIOMUX_FUNC_GPIO,
    .drv = GPIOMUX_DRV_6MA,
    .pull = GPIOMUX_PULL_DOWN,
};

static struct gpiomux_setting ts_reset_act_cfg = {
    .func = GPIOMUX_FUNC_GPIO,
    .drv = GPIOMUX_DRV_6MA,
    .pull = GPIOMUX_PULL_UP,
};
/* [PLATFORM]-Add-END by TCTNB.Alvin */

#ifdef MSM8930_PHASE_2
static struct gpiomux_setting hsusb_sus_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct msm_gpiomux_config msm8930_hsusb_configs[] = {
	{
		.gpio = 63,     /* HSUSB_EXTERNAL_5V_LDO_EN */
		.settings = {
			[GPIOMUX_SUSPENDED] = &hsusb_sus_cfg,
		},
	},
	{
		.gpio = 97,     /* HSUSB_5V_EN */
		.settings = {
			[GPIOMUX_SUSPENDED] = &hsusb_sus_cfg,
		},
	},
};
#endif

static struct gpiomux_setting hap_lvl_shft_suspended_config = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_DOWN,
};

static struct gpiomux_setting hap_lvl_shft_active_config = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_UP,
};

static struct gpiomux_setting ap2mdm_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_DOWN,
};

static struct gpiomux_setting mdm2ap_status_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
};

static struct gpiomux_setting mdm2ap_errfatal_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_16MA,
	.pull = GPIOMUX_PULL_DOWN,
};

static struct gpiomux_setting ap2mdm_kpdpwr_n_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_NONE,
};

static struct gpiomux_setting mdp_vsync_suspend_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_DOWN,
};

static struct gpiomux_setting mdp_vsync_active_cfg = {
	.func = GPIOMUX_FUNC_1,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_DOWN,
};

#ifdef CONFIG_FB_MSM_HDMI_MSM_PANEL
static struct gpiomux_setting hdmi_suspend_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_DOWN,
};

static struct gpiomux_setting hdmi_active_1_cfg = {
	.func = GPIOMUX_FUNC_1,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_UP,
};

static struct gpiomux_setting hdmi_active_2_cfg = {
	.func = GPIOMUX_FUNC_1,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_DOWN,
};

static struct gpiomux_setting hdmi_active_3_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_UP,
	.dir = GPIOMUX_IN,
};

static struct gpiomux_setting hdmi_active_4_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_UP,
	.dir = GPIOMUX_OUT_HIGH,
};

static struct gpiomux_setting hdmi_active_5_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_UP,
	.dir = GPIOMUX_OUT_HIGH,
};

#endif

static struct gpiomux_setting sitar_reset = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_6MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};

#if defined(CONFIG_KS8851) || defined(CONFIG_KS8851_MODULE)
static struct msm_gpiomux_config msm8960_ethernet_configs[] = {
	{
		.gpio = 90,
		.settings = {
			[GPIOMUX_SUSPENDED] = &gpio_eth_config,
		}
	},
	{
		.gpio = 89,
		.settings = {
			[GPIOMUX_SUSPENDED] = &gpio_eth_config,
		}
	},
};
#endif

static struct msm_gpiomux_config msm8960_gsbi_configs[] __initdata = {
/* [PLATFORM]-Mod-BEGIN by TCTNB.Alvin, 2012/10/12, GSBI1&GSBI2 are used as I2C on Viper */
#if 0
	{
		.gpio      = 6,		/* GSBI1 QUP SPI_DATA_MOSI */
		.settings = {
			[GPIOMUX_SUSPENDED] = &spi_suspended_config,
			[GPIOMUX_ACTIVE] = &spi_active,
		},
	},
	{
		.gpio      = 7,		/* GSBI1 QUP SPI_DATA_MISO */
		.settings = {
			[GPIOMUX_SUSPENDED] = &spi_suspended_config,
			[GPIOMUX_ACTIVE] = &spi_active,
		},
	},
	{
		.gpio      = 8,		/* GSBI1 QUP SPI_CS_N */
		.settings = {
			[GPIOMUX_SUSPENDED] = &spi_suspended_config,
			[GPIOMUX_ACTIVE] = &spi_active,
		},
	},
	{
		.gpio      = 9,		/* GSBI1 QUP SPI_CLK */
		.settings = {
			[GPIOMUX_SUSPENDED] = &spi_suspended_config,
			[GPIOMUX_ACTIVE] = &spi_active,
		},
	},
#endif
    {
        .gpio       = 8, /* GSBI1 QUP SDA */
        .settings   = {
            [GPIOMUX_SUSPENDED] = &gsbi1,
        },
    },
    {
        .gpio       = 9, /* GSBI1 QUP SCL */
        .settings   = {
            [GPIOMUX_SUSPENDED] = &gsbi1,
        },
    },
    {
        .gpio       = 12, /* GSBI2 QUP SDA */
        .settings   = {
            [GPIOMUX_SUSPENDED] = &gsbi2,
        },
    },
    {
        .gpio       = 13, /* GSBI2 QUP SCL */
        .settings   = {
            [GPIOMUX_SUSPENDED] = &gsbi2,
        },
    },
/* [PLATFORM]-Mod-End by TCTNB.Alvin */
	{
		.gpio      = 16,	/* GSBI3 I2C QUP SDA */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gsbi3_suspended_cfg,
			[GPIOMUX_ACTIVE] = &gsbi3_active_cfg,
		},
	},
	{
		.gpio      = 17,	/* GSBI3 I2C QUP SCL */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gsbi3_suspended_cfg,
			[GPIOMUX_ACTIVE] = &gsbi3_active_cfg,
		},
	},
/* [PLATFORM]-Del-BEGIN by TCTNB.Alvin, 2012/10/12, GSBI5 is not used on Viper */
#if 0
	{
		.gpio      = 22,	/* GSBI5 UART2 */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gsbi5,
		},
	},
	{
		.gpio      = 23,	/* GSBI5 UART2 */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gsbi5,
		},
	},
#endif
/* [PLATFORM]-Del-END by TCTNB.Alvin */
//[BUGFIX]-Add-BEGIN by Miao FR-403494, 2013/02/02
    {
        .gpio      = 38,  /* GSBI11 UART2 */
        .settings = {
            [GPIOMUX_SUSPENDED] = &gsbi11,
        },
    },
    {
        .gpio      =39,/* GSBI11 UART2 */
        .settings = {
            [GPIOMUX_SUSPENDED] = &gsbi11,
        },
    },
//[BUGFIX]-Add-END
	{
		.gpio      = 44,	/* GSBI12 I2C QUP SDA */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gsbi12,
		},
	},
	{
		.gpio      = 95,	/* GSBI9 I2C QUP SDA */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gsbi9,
		},
	},
	{
		.gpio      = 96,	/* GSBI12 I2C QUP SCL */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gsbi9,
		},
	},
	{
		.gpio      = 45,	/* GSBI12 I2C QUP SCL */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gsbi12,
		},
	},
/* [PLATFORM]-Del-BEGIN by TCTNB.Alvin, 2012/10/12, GSBI10 is not used on Viper */
#if 0
	{
		.gpio      = 73,	/* GSBI10 I2C QUP SDA */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gsbi10,
		},
	},
	{
		.gpio      = 74,	/* GSBI10 I2C QUP SCL */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gsbi10,
		},
	},
#endif
/* [PLATFORM]-Del-END by TCTNB.Alvin */
};

static struct msm_gpiomux_config msm8960_slimbus_config[] __initdata = {
	{
		.gpio	= 60,		/* slimbus data */
		.settings = {
			[GPIOMUX_SUSPENDED] = &slimbus,
		},
	},
	{
		.gpio	= 61,		/* slimbus clk */
		.settings = {
			[GPIOMUX_SUSPENDED] = &slimbus,
		},
	},
};

static struct msm_gpiomux_config msm8960_audio_codec_configs[] __initdata = {
	{
		.gpio = 59,
		.settings = {
			[GPIOMUX_SUSPENDED] = &cdc_mclk,
		},
	},
};

static struct msm_gpiomux_config msm8960_audio_mbhc_configs[] __initdata = {
	{
		.gpio = 37,
		.settings = {
			[GPIOMUX_SUSPENDED] = &audio_mbhc,
		},
	},
};
/* [PLATFORM]-Del-BEGIN by TCTNB.Alvin, 2012/10/12, audio spkr boost is not used on Viper */
#if 0
static struct msm_gpiomux_config msm8960_audio_spkr_configs[] __initdata = {
	{
		.gpio = 15,
		.settings = {
			[GPIOMUX_SUSPENDED] = &audio_spkr_boost,
		},
	},
};
#endif
/* [PLATFORM]-Del-END by TCTNB.Alvin */

/* [PLATFORM]-Add-BEGIN by TCTNB.YJ, 2013/2/23, lcd id pin on viper */
static struct msm_gpiomux_config msm8960_lcd_id_pin_configs[] __initdata = {
	{
		.gpio = 64,
		.settings = {
			[GPIOMUX_SUSPENDED] = &lcd_id_pin[0],
			[GPIOMUX_ACTIVE] = &lcd_id_pin[1],
		},
	},
};
/* [PLATFORM]-Add-END by TCTNB.YJ */

static struct msm_gpiomux_config msm8960_audio_auxpcm_configs[] __initdata = {
	{
		.gpio = 63,
		.settings = {
			[GPIOMUX_SUSPENDED] = &audio_auxpcm[0],
			[GPIOMUX_ACTIVE] = &audio_auxpcm[1],
		},
	},
	{
		.gpio = 64,
		.settings = {
			[GPIOMUX_SUSPENDED] = &audio_auxpcm[0],
			[GPIOMUX_ACTIVE] = &audio_auxpcm[1],
		},
	},
	{
		.gpio = 65,
		.settings = {
			[GPIOMUX_SUSPENDED] = &audio_auxpcm[0],
			[GPIOMUX_ACTIVE] = &audio_auxpcm[1],
		},
	},
	{
		.gpio = 66,
		.settings = {
			[GPIOMUX_SUSPENDED] = &audio_auxpcm[0],
			[GPIOMUX_ACTIVE] = &audio_auxpcm[1],
		},
	},
};

static struct msm_gpiomux_config wcnss_5wire_interface[] = {
	{
		.gpio = 84,
		.settings = {
			[GPIOMUX_ACTIVE]    = &wcnss_5wire_active_cfg,
			[GPIOMUX_SUSPENDED] = &wcnss_5wire_suspend_cfg,
		},
	},
	{
		.gpio = 85,
		.settings = {
			[GPIOMUX_ACTIVE]    = &wcnss_5wire_active_cfg,
			[GPIOMUX_SUSPENDED] = &wcnss_5wire_suspend_cfg,
		},
	},
	{
		.gpio = 86,
		.settings = {
			[GPIOMUX_ACTIVE]    = &wcnss_5wire_active_cfg,
			[GPIOMUX_SUSPENDED] = &wcnss_5wire_suspend_cfg,
		},
	},
	{
		.gpio = 87,
		.settings = {
			[GPIOMUX_ACTIVE]    = &wcnss_5wire_active_cfg,
			[GPIOMUX_SUSPENDED] = &wcnss_5wire_suspend_cfg,
		},
	},
	{
		.gpio = 88,
		.settings = {
			[GPIOMUX_ACTIVE]    = &wcnss_5wire_active_cfg,
			[GPIOMUX_SUSPENDED] = &wcnss_5wire_suspend_cfg,
		},
	},
};
/* [PLATFORM]-Del-BEGIN by TCTNB.Alvin, 2012/10/12, Atmel TS is not used on Viper */
#if 0
static struct msm_gpiomux_config msm8960_atmel_configs[] __initdata = {
	{	/* TS INTERRUPT */
		.gpio = 11,
		.settings = {
			[GPIOMUX_ACTIVE]    = &atmel_int_act_cfg,
			[GPIOMUX_SUSPENDED] = &atmel_int_sus_cfg,
		},
	},
	{	/* TS LDO ENABLE */
		.gpio = 50,
		.settings = {
			[GPIOMUX_ACTIVE]    = &atmel_ldo_en_act_cfg,
			[GPIOMUX_SUSPENDED] = &atmel_ldo_en_sus_cfg,
		},
	},
	{	/* TS RESOUT */
		.gpio = 52,
		.settings = {
			[GPIOMUX_ACTIVE]    = &atmel_resout_act_cfg,
			[GPIOMUX_SUSPENDED] = &atmel_resout_sus_cfg,
		},
	},
};
#endif
/* [PLATFORM]-Del-END by TCTNB.Alvin */
/* [PLATFORM]-Add-BEGIN by TCTNB.Alvin, 2012/10/12, GPIO configruation for touch screen */
static struct msm_gpiomux_config msm8960_ts_configs[] __initdata = {
    {   /* TS INTERRUPT */
        .gpio = 11,
        .settings = {
            [GPIOMUX_ACTIVE]    = &ts_int_act_cfg,
            [GPIOMUX_SUSPENDED] = &ts_int_sus_cfg,
        },
    },
    {   /* TS WAKEUP */
        .gpio = 22,
        .settings = {
            [GPIOMUX_ACTIVE]    = &ts_wakeup_act_cfg,
            [GPIOMUX_SUSPENDED] = &ts_wakeup_sus_cfg,
        },
    },
    {   /* TS RESET */
        .gpio = 52,
        .settings = {
            [GPIOMUX_ACTIVE]    = &ts_reset_act_cfg,
            [GPIOMUX_SUSPENDED] = &ts_reset_sus_cfg,
        },
    },    
};
/* [PLATFORM]-Add-END by TCTNB.Alvin */

static struct msm_gpiomux_config hap_lvl_shft_config[] __initdata = {
	{
		.gpio = 47,
		.settings = {
			[GPIOMUX_SUSPENDED] = &hap_lvl_shft_suspended_config,
			[GPIOMUX_ACTIVE] = &hap_lvl_shft_active_config,
		},
	},
};

static struct msm_gpiomux_config mdm_configs[] __initdata = {
	/* AP2MDM_STATUS */
	{
		.gpio = 94,
		.settings = {
			[GPIOMUX_SUSPENDED] = &ap2mdm_cfg,
		}
	},
	/* MDM2AP_STATUS */
	{
		.gpio = 69,
		.settings = {
			[GPIOMUX_SUSPENDED] = &mdm2ap_status_cfg,
		}
	},
	/* MDM2AP_ERRFATAL */
	{
		.gpio = 70,
		.settings = {
			[GPIOMUX_SUSPENDED] = &mdm2ap_errfatal_cfg,
		}
	},
	/* AP2MDM_ERRFATAL */
	{
		.gpio = 95,
		.settings = {
			[GPIOMUX_SUSPENDED] = &ap2mdm_cfg,
		}
	},
	/* AP2MDM_KPDPWR_N */
	{
		.gpio = 81,
		.settings = {
			[GPIOMUX_SUSPENDED] = &ap2mdm_kpdpwr_n_cfg,
		}
	},
	/* AP2MDM_PMIC_RESET_N */
	{
		.gpio = 80,
		.settings = {
			[GPIOMUX_SUSPENDED] = &ap2mdm_kpdpwr_n_cfg,
		}
	}
};

static struct msm_gpiomux_config msm8960_mdp_vsync_configs[] __initdata = {
	{
		.gpio = 0,
		.settings = {
			[GPIOMUX_ACTIVE]    = &mdp_vsync_active_cfg,
			[GPIOMUX_SUSPENDED] = &mdp_vsync_suspend_cfg,
		},
	}
};

#ifdef CONFIG_FB_MSM_HDMI_MSM_PANEL
static struct msm_gpiomux_config msm8960_hdmi_configs[] __initdata = {
	{
		.gpio = 99,
		.settings = {
			[GPIOMUX_ACTIVE]    = &hdmi_active_1_cfg,
			[GPIOMUX_SUSPENDED] = &hdmi_suspend_cfg,
		},
	},
	{
		.gpio = 100,
		.settings = {
			[GPIOMUX_ACTIVE]    = &hdmi_active_1_cfg,
			[GPIOMUX_SUSPENDED] = &hdmi_suspend_cfg,
		},
	},
	{
		.gpio = 101,
		.settings = {
			[GPIOMUX_ACTIVE]    = &hdmi_active_1_cfg,
			[GPIOMUX_SUSPENDED] = &hdmi_suspend_cfg,
		},
	},
	{
		.gpio = 102,
		.settings = {
			[GPIOMUX_ACTIVE]    = &hdmi_active_2_cfg,
			[GPIOMUX_SUSPENDED] = &hdmi_suspend_cfg,
		},
	},

};

static struct msm_gpiomux_config msm8930_mhl_configs[] __initdata = {
	{
		.gpio = 72,
		.settings = {
			[GPIOMUX_ACTIVE]    = &hdmi_active_3_cfg,
			[GPIOMUX_SUSPENDED] = &hdmi_suspend_cfg,
		},
	},
	{
		.gpio = 71,
		.settings = {
			[GPIOMUX_ACTIVE]    = &hdmi_active_4_cfg,
			[GPIOMUX_SUSPENDED] = &hdmi_suspend_cfg,
		},
	},
	{
		.gpio = 73,
		.settings = {
			[GPIOMUX_ACTIVE]    = &hdmi_active_5_cfg,
			[GPIOMUX_SUSPENDED] = &hdmi_suspend_cfg,
		},
	},

};
#endif

static struct gpiomux_setting haptics_active_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_UP,
};
static struct gpiomux_setting haptics_suspend_cfg = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_8MA,
	.pull = GPIOMUX_PULL_DOWN,
};

static struct msm_gpiomux_config msm8930_haptics_configs[] __initdata = {
	{
		.gpio = 77,
		.settings = {
			[GPIOMUX_ACTIVE] = &haptics_active_cfg,
			[GPIOMUX_SUSPENDED] = &haptics_suspend_cfg,
		},
	},
	{
		.gpio = 78,
		.settings = {
			[GPIOMUX_ACTIVE] = &haptics_active_cfg,
			[GPIOMUX_SUSPENDED] = &haptics_suspend_cfg,
		},
	},
};

static struct gpiomux_setting sd_det_line = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
};

static struct msm_gpiomux_config msm8930_sd_det_config[] __initdata = {
	{
		.gpio = 94,	/* SD Card Detect Line */
		.settings = {
			[GPIOMUX_SUSPENDED] = &sd_det_line,
			[GPIOMUX_ACTIVE] = &sd_det_line,
		},
	},
};

/* [PLATFORM]-Add-BEGIN by TCTNB.Alvin, 2012/10/12, config LCD Reset and Unused pins */
static struct gpiomux_setting lcd_rst_gpio_act = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_6MA,
	.pull = GPIOMUX_PULL_UP,
};
static struct gpiomux_setting lcd_rst_gpio_sus = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_6MA,
/* [PLATFORM]-Mod-BEGIN by TCTNB.YJ, 2013/1/22, enable the splash screen  */
//	.pull = GPIOMUX_PULL_DOWN,
	.pull = GPIOMUX_PULL_UP,
/* [PLATFORM]-Mod-BEGIN by TCTNB.YJ */
};

static struct msm_gpiomux_config msm8930_lcd_rst_config[] __initdata = {
	{
		.gpio = 58,	/* LCD Reset */
		.settings = {
			[GPIOMUX_SUSPENDED] = &lcd_rst_gpio_sus,
			[GPIOMUX_ACTIVE] = &lcd_rst_gpio_act,
		},
	},
};

/* [PLATFORM]-Del-BEGIN by TCTNB.YJ, 2013/3/28, config Unused gpios */
#if 0
static struct gpiomux_setting unused_gpio_1 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_15 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_43 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_48 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_56 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_63 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_69 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_71 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_72 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_73 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_77 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_78 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_81 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_82 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_97 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_99 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_100 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_101 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_109 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_110 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_120 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_121 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};
static struct gpiomux_setting unused_gpio_124 = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
	.dir = GPIOMUX_OUT_LOW,
};

static struct msm_gpiomux_config msm8930_unused_config[] __initdata = {
	{
		.gpio = 1,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_1,
			[GPIOMUX_ACTIVE] = &unused_gpio_1,
		},
	},
	{
		.gpio = 15,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_15,
			[GPIOMUX_ACTIVE] = &unused_gpio_15,
		},
	},
	{
		.gpio = 43,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_43,
			[GPIOMUX_ACTIVE] = &unused_gpio_43,
		},
	},
	{
		.gpio = 48,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_48,
			[GPIOMUX_ACTIVE] = &unused_gpio_48,
		},
	},
	{
		.gpio = 56,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_56,
			[GPIOMUX_ACTIVE] = &unused_gpio_56,
		},
	},
	{
		.gpio = 63,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_63,
			[GPIOMUX_ACTIVE] = &unused_gpio_63,
		},
	},
	{
		.gpio = 69,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_69,
			[GPIOMUX_ACTIVE] = &unused_gpio_69,
		},
	},
	{
		.gpio = 71,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_71,
			[GPIOMUX_ACTIVE] = &unused_gpio_71,
		},
	},
	{
		.gpio = 72,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_72,
			[GPIOMUX_ACTIVE] = &unused_gpio_72,
		},
	},
	{
		.gpio = 73,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_73,
			[GPIOMUX_ACTIVE] = &unused_gpio_73,
		},
	},
	{
		.gpio = 77,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_77,
			[GPIOMUX_ACTIVE] = &unused_gpio_77,
		},
	},
	{
		.gpio = 78,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_78,
			[GPIOMUX_ACTIVE] = &unused_gpio_78,
		},
	},
	{
		.gpio = 81,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_81,
			[GPIOMUX_ACTIVE] = &unused_gpio_81,
		},
	},
	{
		.gpio = 82,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_82,
			[GPIOMUX_ACTIVE] = &unused_gpio_82,
		},
	},
	{
		.gpio = 97,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_97,
			[GPIOMUX_ACTIVE] = &unused_gpio_97,
		},
	},
	{
		.gpio = 99,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_99,
			[GPIOMUX_ACTIVE] = &unused_gpio_99,
		},
	},
	{
		.gpio = 100,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_100,
			[GPIOMUX_ACTIVE] = &unused_gpio_100,
		},
	},
	{
		.gpio = 101,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_101,
			[GPIOMUX_ACTIVE] = &unused_gpio_101,
		},
	},
	{
		.gpio = 109,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_109,
			[GPIOMUX_ACTIVE] = &unused_gpio_109,
		},
	},
	{
		.gpio = 110,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_110,
			[GPIOMUX_ACTIVE] = &unused_gpio_110,
		},
	},
	{
		.gpio = 120,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_120,
			[GPIOMUX_ACTIVE] = &unused_gpio_120,
		},
	},
	{
		.gpio = 121,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_121,
			[GPIOMUX_ACTIVE] = &unused_gpio_121,
		},
	},
	{
		.gpio = 124,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio_124,
			[GPIOMUX_ACTIVE] = &unused_gpio_124,
		},
	},
};
#endif
/* [PLATFORM]-Del-End by TCTNB.YJ */
/* [PLATFORM]-Add-BEGIN by TCTNB.Alvin */

/* [PLATFORM]-Add-BEGIN by TCTNB.YJ, 2013/3/28, config Unused gpios */
static struct gpiomux_setting unused_gpio = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_DOWN,
	.dir = GPIOMUX_IN,
};

static struct msm_gpiomux_config msm8930_unused_config[] __initdata = {
	{
		.gpio = 1,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 6,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 7,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 8,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 9,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 10,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 12,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 13,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 14,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 15,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 18,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 19,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 22,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 23,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 24,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 25,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 35,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 40,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 41,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 43,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 47,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 48,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 51,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
/* [PLATFORM]-Add-BEGIN by TCTNB.HJ, 2013/06/08 */
	{
		.gpio = 53,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
/* [PLATFORM]-Add-BEGIN by TCTNB.HJ, 2013/06/08*/
	{
		.gpio = 56,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 63,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 65,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 66,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 69,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 71,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 72,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 73,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 74,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 75,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 77,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 78,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 81,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 82,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 89,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 90,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 91,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 92,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 93,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 95,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 96,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 97,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 99,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 100,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 101,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 102,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 106,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 109,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 110,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 112,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 120,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 124,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 130,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 135,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 138,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 140,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 141,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 144,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 145,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 146,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 149,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 150,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
	{
		.gpio = 151,
		.settings = {
			[GPIOMUX_SUSPENDED] = &unused_gpio,
			[GPIOMUX_ACTIVE] = &unused_gpio,
		},
	},
};
/* [PLATFORM]-Add-End by TCTNB.YJ */

static struct gpiomux_setting gyro_int_line = {
	.func = GPIOMUX_FUNC_GPIO,
	.drv = GPIOMUX_DRV_2MA,
	.pull = GPIOMUX_PULL_NONE,
};

static struct msm_gpiomux_config msm8930_gyro_int_config[] __initdata = {
	{
		.gpio = 69,	/* Gyro Interrupt Line */
		.settings = {
			[GPIOMUX_SUSPENDED] = &gyro_int_line,
			[GPIOMUX_ACTIVE] = &gyro_int_line,
		},
	},
};

static struct msm_gpiomux_config msm_sitar_config[] __initdata = {
	{
		.gpio   = 42,           /* SYS_RST_N */
		.settings = {
			[GPIOMUX_SUSPENDED] = &sitar_reset,
		},
	}
};

int __init msm8930_init_gpiomux(void)
{
	int rc = msm_gpiomux_init(NR_GPIO_IRQS);
	if (rc) {
		pr_err(KERN_ERR "msm_gpiomux_init failed %d\n", rc);
		return rc;
	}

#if defined(CONFIG_KS8851) || defined(CONFIG_KS8851_MODULE)
	msm_gpiomux_install(msm8960_ethernet_configs,
			ARRAY_SIZE(msm8960_ethernet_configs));
#endif

	msm_gpiomux_install(msm8960_gsbi_configs,
			ARRAY_SIZE(msm8960_gsbi_configs));

/* [PLATFORM]-Del-BEGIN by TCTNB.Alvin, 2012/10/12, Atmel TS is not used on Viper */
#if 0
	msm_gpiomux_install(msm8960_atmel_configs,
			ARRAY_SIZE(msm8960_atmel_configs));
#endif
/* [PLATFORM]-Del-END by TCTNB.Alvin */

/* [PLATFORM]-Add-BEGIN by TCTNB.Alvin, 2012/10/12, GPIO configruation for touch screen */
    msm_gpiomux_install(msm8960_ts_configs,
            ARRAY_SIZE(msm8960_ts_configs));
/* [PLATFORM]-Add-END by TCTNB.Alvin */

	msm_gpiomux_install(msm8960_slimbus_config,
			ARRAY_SIZE(msm8960_slimbus_config));

	msm_gpiomux_install(msm8960_audio_codec_configs,
			ARRAY_SIZE(msm8960_audio_codec_configs));

	msm_gpiomux_install(msm8960_audio_mbhc_configs,
			ARRAY_SIZE(msm8960_audio_mbhc_configs));

/* [PLATFORM]-Del-BEGIN by TCTNB.Alvin, 2012/10/12, audio spkr boost is not used on Viper */
#if 0
	msm_gpiomux_install(msm8960_audio_spkr_configs,
			ARRAY_SIZE(msm8960_audio_spkr_configs));
#endif
/* [PLATFORM]-Del-END by TCTNB.Alvin */

	msm_gpiomux_install(msm8960_audio_auxpcm_configs,
			ARRAY_SIZE(msm8960_audio_auxpcm_configs));

/* [PLATFORM]-Add-BEGIN by TCTNB.YJ, 2013/2/23, lcd id pin on viper */
	msm_gpiomux_install(msm8960_lcd_id_pin_configs,
			ARRAY_SIZE(msm8960_lcd_id_pin_configs));
/* [PLATFORM]-Add-END by TCTNB.YJ */

	msm_gpiomux_install(wcnss_5wire_interface,
			ARRAY_SIZE(wcnss_5wire_interface));

	if (machine_is_msm8930_mtp() || machine_is_msm8930_fluid() ||
		machine_is_msm8930_cdp()) {
		msm_gpiomux_install(hap_lvl_shft_config,
			ARRAY_SIZE(hap_lvl_shft_config));
#ifdef MSM8930_PHASE_2
		msm_gpiomux_install(msm8930_hsusb_configs,
			ARRAY_SIZE(msm8930_hsusb_configs));
#endif
	}

	if (PLATFORM_IS_CHARM25())
		msm_gpiomux_install(mdm_configs,
			ARRAY_SIZE(mdm_configs));

	if (machine_is_msm8930_cdp() || machine_is_msm8930_mtp()
		|| machine_is_msm8930_fluid())
		msm_gpiomux_install(msm8930_haptics_configs,
			ARRAY_SIZE(msm8930_haptics_configs));

#ifdef CONFIG_FB_MSM_HDMI_MSM_PANEL
	msm_gpiomux_install(msm8960_hdmi_configs,
			ARRAY_SIZE(msm8960_hdmi_configs));
	if (machine_is_msm8930_fluid())
		msm_gpiomux_install(msm8930_mhl_configs,
				ARRAY_SIZE(msm8930_mhl_configs));
#endif

	msm_gpiomux_install(msm8960_mdp_vsync_configs,
			ARRAY_SIZE(msm8960_mdp_vsync_configs));

	msm_gpiomux_install(msm8930_sd_det_config,
			ARRAY_SIZE(msm8930_sd_det_config));

/* [PLATFORM]-Add-BEGIN by TCTNB.Alvin, 2012/10/12, config LCD Reset and Unused pins */
    msm_gpiomux_install(msm8930_lcd_rst_config,
            ARRAY_SIZE(msm8930_lcd_rst_config));

    msm_gpiomux_install(msm8930_unused_config,
            ARRAY_SIZE(msm8930_unused_config));
/* [PLATFORM]-Add-END by TCTNB.Alvin */

	if (machine_is_msm8930_fluid() || machine_is_msm8930_mtp())
		msm_gpiomux_install(msm8930_gyro_int_config,
			ARRAY_SIZE(msm8930_gyro_int_config));

	msm_gpiomux_install(msm_sitar_config, ARRAY_SIZE(msm_sitar_config));

	return 0;
}
