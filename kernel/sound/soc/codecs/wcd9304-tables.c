/* Copyright (c) 2012, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/mfd/wcd9xxx/wcd9xxx_registers.h>
#include <linux/mfd/wcd9xxx/wcd9304_registers.h>
#include "wcd9304.h"

const u8 sitar_reg_defaults[SITAR_CACHE_SIZE] = {
	[WCD9XXX_A_CHIP_CTL] = WCD9XXX_A_CHIP_CTL__POR,
	[WCD9XXX_A_CHIP_STATUS] = WCD9XXX_A_CHIP_STATUS__POR,
	[WCD9XXX_A_CHIP_ID_BYTE_0] = WCD9XXX_A_CHIP_ID_BYTE_0__POR,
	[WCD9XXX_A_CHIP_ID_BYTE_1] = WCD9XXX_A_CHIP_ID_BYTE_1__POR,
	[WCD9XXX_A_CHIP_ID_BYTE_2] = WCD9XXX_A_CHIP_ID_BYTE_2__POR,
	[WCD9XXX_A_CHIP_ID_BYTE_3] = WCD9XXX_A_CHIP_ID_BYTE_3__POR,
	[WCD9XXX_A_CHIP_VERSION] = WCD9XXX_A_CHIP_VERSION__POR,
	[WCD9XXX_A_SB_VERSION] = WCD9XXX_A_SB_VERSION__POR,
	[WCD9XXX_A_SLAVE_ID_1] = WCD9XXX_A_SLAVE_ID_1__POR,
	[WCD9XXX_A_SLAVE_ID_2] = WCD9XXX_A_SLAVE_ID_2__POR,
	[WCD9XXX_A_SLAVE_ID_3] = WCD9XXX_A_SLAVE_ID_3__POR,
	[SITAR_A_PIN_CTL_OE0] = SITAR_A_PIN_CTL_OE0__POR,
	[SITAR_A_PIN_CTL_OE1] = SITAR_A_PIN_CTL_OE1__POR,
	[SITAR_A_PIN_CTL_DATA0] = SITAR_A_PIN_CTL_DATA0__POR,
	[SITAR_A_PIN_CTL_DATA1] = SITAR_A_PIN_CTL_DATA1__POR,
	[SITAR_A_HDRIVE_GENERIC] = SITAR_A_HDRIVE_GENERIC__POR,
	[SITAR_A_HDRIVE_OVERRIDE] = SITAR_A_HDRIVE_OVERRIDE__POR,
	[SITAR_A_ANA_CSR_WAIT_STATE] = SITAR_A_ANA_CSR_WAIT_STATE__POR,
	[SITAR_A_PROCESS_MONITOR_CTL0] = SITAR_A_PROCESS_MONITOR_CTL0__POR,
	[SITAR_A_PROCESS_MONITOR_CTL1] = SITAR_A_PROCESS_MONITOR_CTL1__POR,
	[SITAR_A_PROCESS_MONITOR_CTL2] = SITAR_A_PROCESS_MONITOR_CTL2__POR,
	[SITAR_A_PROCESS_MONITOR_CTL3] = SITAR_A_PROCESS_MONITOR_CTL3__POR,
	[SITAR_A_QFUSE_CTL] = SITAR_A_QFUSE_CTL__POR,
	[SITAR_A_QFUSE_STATUS] = SITAR_A_QFUSE_STATUS__POR,
	[SITAR_A_QFUSE_DATA_OUT0] = SITAR_A_QFUSE_DATA_OUT0__POR,
	[SITAR_A_QFUSE_DATA_OUT1] = SITAR_A_QFUSE_DATA_OUT1__POR,
	[SITAR_A_QFUSE_DATA_OUT2] = SITAR_A_QFUSE_DATA_OUT2__POR,
	[SITAR_A_QFUSE_DATA_OUT3] = SITAR_A_QFUSE_DATA_OUT3__POR,
	[SITAR_A_CDC_CTL] = SITAR_A_CDC_CTL__POR,
	[SITAR_A_LEAKAGE_CTL] = SITAR_A_LEAKAGE_CTL__POR,
	[SITAR_A_INTR_MODE] = SITAR_A_INTR_MODE__POR,
	[SITAR_A_INTR_MASK0] = SITAR_A_INTR_MASK0__POR,
	[SITAR_A_INTR_MASK1] = SITAR_A_INTR_MASK1__POR,
	[SITAR_A_INTR_MASK2] = SITAR_A_INTR_MASK2__POR,
	[SITAR_A_INTR_STATUS0] = SITAR_A_INTR_STATUS0__POR,
	[SITAR_A_INTR_STATUS1] = SITAR_A_INTR_STATUS1__POR,
	[SITAR_A_INTR_STATUS2] = SITAR_A_INTR_STATUS2__POR,
	[SITAR_A_INTR_CLEAR0] = SITAR_A_INTR_CLEAR0__POR,
	[SITAR_A_INTR_CLEAR1] = SITAR_A_INTR_CLEAR1__POR,
	[SITAR_A_INTR_CLEAR2] = SITAR_A_INTR_CLEAR2__POR,
	[SITAR_A_INTR_LEVEL0] = SITAR_A_INTR_LEVEL0__POR,
	[SITAR_A_INTR_LEVEL1] = SITAR_A_INTR_LEVEL1__POR,
	[SITAR_A_INTR_LEVEL2] = SITAR_A_INTR_LEVEL2__POR,
	[SITAR_A_INTR_TEST0] = SITAR_A_INTR_TEST0__POR,
	[SITAR_A_INTR_TEST1] = SITAR_A_INTR_TEST1__POR,
	[SITAR_A_INTR_TEST2] = SITAR_A_INTR_TEST2__POR,
	[SITAR_A_INTR_SET0] = SITAR_A_INTR_SET0__POR,
	[SITAR_A_INTR_SET1] = SITAR_A_INTR_SET1__POR,
	[SITAR_A_INTR_SET2] = SITAR_A_INTR_SET2__POR,
	[SITAR_A_CDC_TX_I2S_SCK_MODE] = SITAR_A_CDC_TX_I2S_SCK_MODE__POR,
	[SITAR_A_CDC_TX_I2S_WS_MODE] = SITAR_A_CDC_TX_I2S_WS_MODE__POR,
	[SITAR_A_CDC_DMIC_DATA0_MODE] = SITAR_A_CDC_DMIC_DATA0_MODE__POR,
	[SITAR_A_CDC_DMIC_CLK0_MODE] = SITAR_A_CDC_DMIC_CLK0_MODE__POR,
	[SITAR_A_CDC_DMIC_DATA1_MODE] = SITAR_A_CDC_DMIC_DATA1_MODE__POR,
	[SITAR_A_CDC_DMIC_CLK1_MODE] = SITAR_A_CDC_DMIC_CLK1_MODE__POR,
	[SITAR_A_CDC_TX_I2S_SD0_MODE] = SITAR_A_CDC_TX_I2S_SD0_MODE__POR,
	[SITAR_A_CDC_INTR_MODE] = SITAR_A_CDC_INTR_MODE__POR,
	[SITAR_A_CDC_RX_I2S_SD0_MODE] = SITAR_A_CDC_RX_I2S_SD0_MODE__POR,
	[SITAR_A_CDC_RX_I2S_SD1_MODE] = SITAR_A_CDC_RX_I2S_SD1_MODE__POR,
	[SITAR_A_BIAS_REF_CTL] = SITAR_A_BIAS_REF_CTL__POR,
	[SITAR_A_BIAS_CENTRAL_BG_CTL] = SITAR_A_BIAS_CENTRAL_BG_CTL__POR,
	[SITAR_A_BIAS_PRECHRG_CTL] = SITAR_A_BIAS_PRECHRG_CTL__POR,
	[SITAR_A_BIAS_CURR_CTL_1] = SITAR_A_BIAS_CURR_CTL_1__POR,
	[SITAR_A_BIAS_CURR_CTL_2] = SITAR_A_BIAS_CURR_CTL_2__POR,
	[SITAR_A_BIAS_OSC_BG_CTL] = SITAR_A_BIAS_OSC_BG_CTL__POR,
	[SITAR_A_CLK_BUFF_EN1] = SITAR_A_CLK_BUFF_EN1__POR,
	[SITAR_A_CLK_BUFF_EN2] = SITAR_A_CLK_BUFF_EN2__POR,
	[SITAR_A_LDO_H_MODE_1] = SITAR_A_LDO_H_MODE_1__POR,
	[SITAR_A_LDO_H_MODE_2] = SITAR_A_LDO_H_MODE_2__POR,
	[SITAR_A_LDO_H_LOOP_CTL] = SITAR_A_LDO_H_LOOP_CTL__POR,
	[SITAR_A_LDO_H_COMP_1] = SITAR_A_LDO_H_COMP_1__POR,
	[SITAR_A_LDO_H_COMP_2] = SITAR_A_LDO_H_COMP_2__POR,
	[SITAR_A_LDO_H_BIAS_1] = SITAR_A_LDO_H_BIAS_1__POR,
	[SITAR_A_LDO_H_BIAS_2] = SITAR_A_LDO_H_BIAS_2__POR,
	[SITAR_A_LDO_H_BIAS_3] = SITAR_A_LDO_H_BIAS_3__POR,
	[SITAR_A_MICB_CFILT_1_CTL] = SITAR_A_MICB_CFILT_1_CTL__POR,
	[SITAR_A_MICB_CFILT_1_VAL] = SITAR_A_MICB_CFILT_1_VAL__POR,
	[SITAR_A_MICB_CFILT_1_PRECHRG] = SITAR_A_MICB_CFILT_1_PRECHRG__POR,
	[SITAR_A_MICB_1_CTL] = SITAR_A_MICB_1_CTL__POR,
	[SITAR_A_MICB_1_INT_RBIAS] = SITAR_A_MICB_1_INT_RBIAS__POR,
	[SITAR_A_MICB_1_MBHC] = SITAR_A_MICB_1_MBHC__POR,
	[SITAR_A_MICB_CFILT_2_CTL] = SITAR_A_MICB_CFILT_2_CTL__POR,
	[SITAR_A_MICB_CFILT_2_VAL] = SITAR_A_MICB_CFILT_2_VAL__POR,
	[SITAR_A_MICB_CFILT_2_PRECHRG] = SITAR_A_MICB_CFILT_2_PRECHRG__POR,
	[SITAR_A_MICB_2_CTL] = SITAR_A_MICB_2_CTL__POR,
	[SITAR_A_MICB_2_INT_RBIAS] = SITAR_A_MICB_2_INT_RBIAS__POR,
	[SITAR_A_MICB_2_MBHC] = SITAR_A_MICB_2_MBHC__POR,
	[SITAR_A_TX_COM_BIAS] = SITAR_A_TX_COM_BIAS__POR,
	[SITAR_A_MBHC_SCALING_MUX_1] = SITAR_A_MBHC_SCALING_MUX_1__POR,
	[SITAR_A_MBHC_SCALING_MUX_2] = SITAR_A_MBHC_SCALING_MUX_2__POR,
	[SITAR_A_TX_SUP_SWITCH_CTRL_1] = SITAR_A_TX_SUP_SWITCH_CTRL_1__POR,
	[SITAR_A_TX_SUP_SWITCH_CTRL_2] = SITAR_A_TX_SUP_SWITCH_CTRL_2__POR,
	[SITAR_A_TX_1_2_EN] = SITAR_A_TX_1_2_EN__POR,
	[SITAR_A_TX_1_2_TEST_EN] = SITAR_A_TX_1_2_TEST_EN__POR,
	[SITAR_A_TX_1_2_ADC_CH1] = SITAR_A_TX_1_2_ADC_CH1__POR,
	[SITAR_A_TX_1_2_ADC_CH2] = SITAR_A_TX_1_2_ADC_CH2__POR,
	[SITAR_A_TX_1_2_ATEST_REFCTRL] = SITAR_A_TX_1_2_ATEST_REFCTRL__POR,
	[SITAR_A_TX_1_2_TEST_CTL] = SITAR_A_TX_1_2_TEST_CTL__POR,
	[SITAR_A_TX_1_2_TEST_BLOCK_EN] = SITAR_A_TX_1_2_TEST_BLOCK_EN__POR,
	[SITAR_A_TX_1_2_TXFE_CLKDIV] = SITAR_A_TX_1_2_TXFE_CLKDIV__POR,
	[SITAR_A_TX_1_2_SAR_ERR_CH1] = SITAR_A_TX_1_2_SAR_ERR_CH1__POR,
	[SITAR_A_TX_1_2_SAR_ERR_CH2] = SITAR_A_TX_1_2_SAR_ERR_CH2__POR,
	[SITAR_A_TX_3_EN] = SITAR_A_TX_3_EN__POR,
	[SITAR_A_TX_3_TEST_EN] = SITAR_A_TX_3_TEST_EN__POR,
	[SITAR_A_TX_3_ADC] = SITAR_A_TX_3_ADC__POR,
	[SITAR_A_TX_3_MBHC_ATEST_REFCTRL] =
		SITAR_A_TX_3_MBHC_ATEST_REFCTRL__POR,
	[SITAR_A_TX_3_TEST_CTL] = SITAR_A_TX_3_TEST_CTL__POR,
	[SITAR_A_TX_3_TEST_BLOCK_EN] = SITAR_A_TX_3_TEST_BLOCK_EN__POR,
	[SITAR_A_TX_3_TXFE_CKDIV] = SITAR_A_TX_3_TXFE_CKDIV__POR,
	[SITAR_A_TX_3_SAR_ERR] = SITAR_A_TX_3_SAR_ERR__POR,
	[SITAR_A_TX_4_MBHC_EN] = SITAR_A_TX_4_MBHC_EN__POR,
	[SITAR_A_TX_4_MBHC_ADC] = SITAR_A_TX_4_MBHC_ADC__POR,
	[SITAR_A_TX_4_MBHC_TEST_CTL] = SITAR_A_TX_4_MBHC_TEST_CTL__POR,
	[SITAR_A_TX_4_MBHC_SAR_ERR] = SITAR_A_TX_4_MBHC_SAR_ERR__POR,
	[SITAR_A_TX_4_TXFE_CLKDIV] = SITAR_A_TX_4_TXFE_CLKDIV__POR,
	[SITAR_A_AUX_COM_CTL] = SITAR_A_AUX_COM_CTL__POR,
	[SITAR_A_AUX_COM_ATEST] = SITAR_A_AUX_COM_ATEST__POR,
	[SITAR_A_AUX_L_EN] = SITAR_A_AUX_L_EN__POR,
	[SITAR_A_AUX_L_GAIN] = SITAR_A_AUX_L_GAIN__POR,
	[SITAR_A_AUX_L_PA_CONN] = SITAR_A_AUX_L_PA_CONN__POR,
	[SITAR_A_AUX_L_PA_CONN_INV] = SITAR_A_AUX_L_PA_CONN_INV__POR,
	[SITAR_A_AUX_R_EN] = SITAR_A_AUX_R_EN__POR,
	[SITAR_A_AUX_R_GAIN] = SITAR_A_AUX_R_GAIN__POR,
	[SITAR_A_AUX_R_PA_CONN] = SITAR_A_AUX_R_PA_CONN__POR,
	[SITAR_A_AUX_R_PA_CONN_INV] = SITAR_A_AUX_R_PA_CONN_INV__POR,
	[SITAR_A_CP_EN] = SITAR_A_CP_EN__POR,
	[SITAR_A_CP_CLK] = SITAR_A_CP_CLK__POR,
	[SITAR_A_CP_STATIC] = SITAR_A_CP_STATIC__POR,
	[SITAR_A_CP_DCC1] = SITAR_A_CP_DCC1__POR,
	[SITAR_A_CP_DCC3] = SITAR_A_CP_DCC3__POR,
	[SITAR_A_CP_ATEST] = SITAR_A_CP_ATEST__POR,
	[SITAR_A_CP_DTEST] = SITAR_A_CP_DTEST__POR,
	[SITAR_A_RX_COM_TIMER_DIV] = SITAR_A_RX_COM_TIMER_DIV__POR,
	[SITAR_A_RX_COM_OCP_CTL] = SITAR_A_RX_COM_OCP_CTL__POR,
	[SITAR_A_RX_COM_OCP_COUNT] = SITAR_A_RX_COM_OCP_COUNT__POR,
	[SITAR_A_RX_COM_DAC_CTL] = SITAR_A_RX_COM_DAC_CTL__POR,
	[SITAR_A_RX_COM_BIAS] = SITAR_A_RX_COM_BIAS__POR,
	[SITAR_A_RX_HPH_BIAS_PA] = SITAR_A_RX_HPH_BIAS_PA__POR,
	[SITAR_A_RX_HPH_BIAS_LDO] = SITAR_A_RX_HPH_BIAS_LDO__POR,
	[SITAR_A_RX_HPH_BIAS_CNP] = SITAR_A_RX_HPH_BIAS_CNP__POR,
	[SITAR_A_RX_HPH_BIAS_WG] = SITAR_A_RX_HPH_BIAS_WG__POR,
	[SITAR_A_RX_HPH_OCP_CTL] = SITAR_A_RX_HPH_OCP_CTL__POR,
	[SITAR_A_RX_HPH_CNP_EN] = SITAR_A_RX_HPH_CNP_EN__POR,
	[SITAR_A_RX_HPH_CNP_WG_CTL] = SITAR_A_RX_HPH_CNP_WG_CTL__POR,
	[SITAR_A_RX_HPH_CNP_WG_TIME] = SITAR_A_RX_HPH_CNP_WG_TIME__POR,
	[SITAR_A_RX_HPH_L_GAIN] = SITAR_A_RX_HPH_L_GAIN__POR,
	[SITAR_A_RX_HPH_L_TEST] = SITAR_A_RX_HPH_L_TEST__POR,
	[SITAR_A_RX_HPH_L_PA_CTL] = SITAR_A_RX_HPH_L_PA_CTL__POR,
	[SITAR_A_RX_HPH_L_DAC_CTL] = SITAR_A_RX_HPH_L_DAC_CTL__POR,
	[SITAR_A_RX_HPH_L_ATEST] = SITAR_A_RX_HPH_L_ATEST__POR,
	[SITAR_A_RX_HPH_L_STATUS] = SITAR_A_RX_HPH_L_STATUS__POR,
	[SITAR_A_RX_HPH_R_GAIN] = SITAR_A_RX_HPH_R_GAIN__POR,
	[SITAR_A_RX_HPH_R_TEST] = SITAR_A_RX_HPH_R_TEST__POR,
	[SITAR_A_RX_HPH_R_PA_CTL] = SITAR_A_RX_HPH_R_PA_CTL__POR,
	[SITAR_A_RX_HPH_R_DAC_CTL] = SITAR_A_RX_HPH_R_DAC_CTL__POR,
	[SITAR_A_RX_HPH_R_ATEST] = SITAR_A_RX_HPH_R_ATEST__POR,
	[SITAR_A_RX_HPH_R_STATUS] = SITAR_A_RX_HPH_R_STATUS__POR,
	[SITAR_A_RX_EAR_BIAS_PA] = SITAR_A_RX_EAR_BIAS_PA__POR,
	[SITAR_A_RX_EAR_BIAS_CMBUFF] = SITAR_A_RX_EAR_BIAS_CMBUFF__POR,
	[SITAR_A_RX_EAR_EN] = SITAR_A_RX_EAR_EN__POR,
	[SITAR_A_RX_EAR_GAIN] = SITAR_A_RX_EAR_GAIN__POR,
	[SITAR_A_RX_EAR_CMBUFF] = SITAR_A_RX_EAR_CMBUFF__POR,
	[SITAR_A_RX_EAR_ICTL] = SITAR_A_RX_EAR_ICTL__POR,
	[SITAR_A_RX_EAR_CCOMP] = SITAR_A_RX_EAR_CCOMP__POR,
	[SITAR_A_RX_EAR_VCM] = SITAR_A_RX_EAR_VCM__POR,
	[SITAR_A_RX_EAR_CNP] = SITAR_A_RX_EAR_CNP__POR,
	[SITAR_A_RX_EAR_ATEST] = SITAR_A_RX_EAR_ATEST__POR,
	[SITAR_A_RX_EAR_STATUS] = SITAR_A_RX_EAR_STATUS__POR,
	[SITAR_A_RX_LINE_BIAS_PA] = SITAR_A_RX_LINE_BIAS_PA__POR,
	[SITAR_A_RX_LINE_BIAS_LDO] = SITAR_A_RX_LINE_BIAS_LDO__POR,
	[SITAR_A_RX_LINE_BIAS_CNP1] = SITAR_A_RX_LINE_BIAS_CNP1__POR,
	[SITAR_A_RX_LINE_COM] = SITAR_A_RX_LINE_COM__POR,
	[SITAR_A_RX_LINE_CNP_EN] = SITAR_A_RX_LINE_CNP_EN__POR,
	[SITAR_A_RX_LINE_CNP_WG_CTL] = SITAR_A_RX_LINE_CNP_WG_CTL__POR,
	[SITAR_A_RX_LINE_CNP_WG_TIME] = SITAR_A_RX_LINE_CNP_WG_TIME__POR,
	[SITAR_A_RX_LINE_1_GAIN] = SITAR_A_RX_LINE_1_GAIN__POR,
	[SITAR_A_RX_LINE_1_TEST] = SITAR_A_RX_LINE_1_TEST__POR,
	[SITAR_A_RX_LINE_1_DAC_CTL] = SITAR_A_RX_LINE_1_DAC_CTL__POR,
	[SITAR_A_RX_LINE_1_STATUS] = SITAR_A_RX_LINE_1_STATUS__POR,
	[SITAR_A_RX_LINE_2_GAIN] = SITAR_A_RX_LINE_2_GAIN__POR,
	[SITAR_A_RX_LINE_2_TEST] = SITAR_A_RX_LINE_2_TEST__POR,
	[SITAR_A_RX_LINE_2_DAC_CTL] = SITAR_A_RX_LINE_2_DAC_CTL__POR,
	[SITAR_A_RX_LINE_2_STATUS] = SITAR_A_RX_LINE_2_STATUS__POR,
	[SITAR_A_RX_LINE_BIAS_CNP2] = SITAR_A_RX_LINE_BIAS_CNP2__POR,
	[SITAR_A_RX_LINE_OCP_CTL] = SITAR_A_RX_LINE_OCP_CTL__POR,
	[SITAR_A_RX_LINE_1_PA_CTL] = SITAR_A_RX_LINE_1_PA_CTL__POR,
	[SITAR_A_RX_LINE_2_PA_CTL] = SITAR_A_RX_LINE_2_PA_CTL__POR,
	[SITAR_A_RX_LINE_CNP_DBG] = SITAR_A_RX_LINE_CNP_DBG__POR,
	[SITAR_A_MBHC_HPH] = SITAR_A_MBHC_HPH__POR,
	[SITAR_A_RC_OSC_FREQ] = SITAR_A_RC_OSC_FREQ__POR,
	[SITAR_A_RC_OSC_TEST] = SITAR_A_RC_OSC_TEST__POR,
	[SITAR_A_RC_OSC_STATUS] = SITAR_A_RC_OSC_STATUS__POR,
	[SITAR_A_RC_OSC_TUNER] = SITAR_A_RC_OSC_TUNER__POR,
	[SITAR_A_CDC_ANC1_CTL] = SITAR_A_CDC_ANC1_CTL__POR,
	[SITAR_A_CDC_ANC1_SHIFT] = SITAR_A_CDC_ANC1_SHIFT__POR,
	[SITAR_A_CDC_ANC1_IIR_B1_CTL] = SITAR_A_CDC_ANC1_IIR_B1_CTL__POR,
	[SITAR_A_CDC_ANC1_IIR_B2_CTL] = SITAR_A_CDC_ANC1_IIR_B2_CTL__POR,
	[SITAR_A_CDC_ANC1_IIR_B3_CTL] = SITAR_A_CDC_ANC1_IIR_B3_CTL__POR,
	[SITAR_A_CDC_ANC1_IIR_B4_CTL] = SITAR_A_CDC_ANC1_IIR_B4_CTL__POR,
	[SITAR_A_CDC_ANC1_LPF_B1_CTL] = SITAR_A_CDC_ANC1_LPF_B1_CTL__POR,
	[SITAR_A_CDC_ANC1_LPF_B2_CTL] = SITAR_A_CDC_ANC1_LPF_B2_CTL__POR,
	[SITAR_A_CDC_ANC1_LPF_B3_CTL] = SITAR_A_CDC_ANC1_LPF_B3_CTL__POR,
	[SITAR_A_CDC_ANC1_SPARE] = SITAR_A_CDC_ANC1_SPARE__POR,
	[SITAR_A_CDC_ANC1_SMLPF_CTL] = SITAR_A_CDC_ANC1_SMLPF_CTL__POR,
	[SITAR_A_CDC_ANC1_DCFLT_CTL] = SITAR_A_CDC_ANC1_DCFLT_CTL__POR,
	[SITAR_A_CDC_TX1_VOL_CTL_TIMER] = SITAR_A_CDC_TX1_VOL_CTL_TIMER__POR,
	[SITAR_A_CDC_TX1_VOL_CTL_GAIN] = SITAR_A_CDC_TX1_VOL_CTL_GAIN__POR,
	[SITAR_A_CDC_TX1_VOL_CTL_CFG] = SITAR_A_CDC_TX1_VOL_CTL_CFG__POR,
	[SITAR_A_CDC_TX1_MUX_CTL] = SITAR_A_CDC_TX1_MUX_CTL__POR,
	[SITAR_A_CDC_TX1_CLK_FS_CTL] = SITAR_A_CDC_TX1_CLK_FS_CTL__POR,
	[SITAR_A_CDC_TX1_DMIC_CTL] = SITAR_A_CDC_TX1_DMIC_CTL__POR,
	[SITAR_A_CDC_SRC1_PDA_CFG] = SITAR_A_CDC_SRC1_PDA_CFG__POR,
	[SITAR_A_CDC_SRC1_FS_CTL] = SITAR_A_CDC_SRC1_FS_CTL__POR,
	[SITAR_A_CDC_RX1_B1_CTL] = SITAR_A_CDC_RX1_B1_CTL__POR,
	[SITAR_A_CDC_RX1_B2_CTL] = SITAR_A_CDC_RX1_B2_CTL__POR,
	[SITAR_A_CDC_RX1_B3_CTL] = SITAR_A_CDC_RX1_B3_CTL__POR,
	[SITAR_A_CDC_RX1_B4_CTL] = SITAR_A_CDC_RX1_B4_CTL__POR,
	[SITAR_A_CDC_RX1_B5_CTL] = SITAR_A_CDC_RX1_B5_CTL__POR,
	[SITAR_A_CDC_RX1_B6_CTL] = SITAR_A_CDC_RX1_B6_CTL__POR,
	[SITAR_A_CDC_RX1_VOL_CTL_B1_CTL] = SITAR_A_CDC_RX1_VOL_CTL_B1_CTL__POR,
	[SITAR_A_CDC_RX1_VOL_CTL_B2_CTL] = SITAR_A_CDC_RX1_VOL_CTL_B2_CTL__POR,
	[SITAR_A_CDC_CLK_ANC_RESET_CTL] = SITAR_A_CDC_CLK_ANC_RESET_CTL__POR,
	[SITAR_A_CDC_CLK_RX_RESET_CTL] = SITAR_A_CDC_CLK_RX_RESET_CTL__POR,
	[SITAR_A_CDC_CLK_TX_RESET_B1_CTL] =
		SITAR_A_CDC_CLK_TX_RESET_B1_CTL__POR,
	[SITAR_A_CDC_CLK_TX_RESET_B2_CTL] =
		SITAR_A_CDC_CLK_TX_RESET_B2_CTL__POR,
	[SITAR_A_CDC_CLK_DMIC_CTL] = SITAR_A_CDC_CLK_DMIC_CTL__POR,
	[SITAR_A_CDC_CLK_RX_I2S_CTL] = SITAR_A_CDC_CLK_RX_I2S_CTL__POR,
	[SITAR_A_CDC_CLK_TX_I2S_CTL] = SITAR_A_CDC_CLK_TX_I2S_CTL__POR,
	[SITAR_A_CDC_CLK_OTHR_RESET_CTL] = SITAR_A_CDC_CLK_OTHR_RESET_CTL__POR,
	[SITAR_A_CDC_CLK_TX_CLK_EN_B1_CTL] =
		SITAR_A_CDC_CLK_TX_CLK_EN_B1_CTL__POR,
	[SITAR_A_CDC_CLK_OTHR_CTL] = SITAR_A_CDC_CLK_OTHR_CTL__POR,
	[SITAR_A_CDC_CLK_RDAC_CLK_EN_CTL] =
		SITAR_A_CDC_CLK_RDAC_CLK_EN_CTL__POR,
	[SITAR_A_CDC_CLK_ANC_CLK_EN_CTL] = SITAR_A_CDC_CLK_ANC_CLK_EN_CTL__POR,
	[SITAR_A_CDC_CLK_RX_B1_CTL] = SITAR_A_CDC_CLK_RX_B1_CTL__POR,
	[SITAR_A_CDC_CLK_RX_B2_CTL] = SITAR_A_CDC_CLK_RX_B2_CTL__POR,
	[SITAR_A_CDC_CLK_MCLK_CTL] = SITAR_A_CDC_CLK_MCLK_CTL__POR,
	[SITAR_A_CDC_CLK_PDM_CTL] = SITAR_A_CDC_CLK_PDM_CTL__POR,
	[SITAR_A_CDC_CLK_SD_CTL] = SITAR_A_CDC_CLK_SD_CTL__POR,
	[SITAR_A_CDC_CLK_LP_CTL] = SITAR_A_CDC_CLK_LP_CTL__POR,
	[SITAR_A_CDC_CLSG_FREQ_THRESH_B1_CTL] =
		SITAR_A_CDC_CLSG_FREQ_THRESH_B1_CTL__POR,
	[SITAR_A_CDC_CLSG_FREQ_THRESH_B2_CTL] =
		SITAR_A_CDC_CLSG_FREQ_THRESH_B2_CTL__POR,
	[SITAR_A_CDC_CLSG_FREQ_THRESH_B3_CTL] =
		SITAR_A_CDC_CLSG_FREQ_THRESH_B3_CTL__POR,
	[SITAR_A_CDC_CLSG_FREQ_THRESH_B4_CTL] =
		SITAR_A_CDC_CLSG_FREQ_THRESH_B4_CTL__POR,
	[SITAR_A_CDC_CLSG_GAIN_THRESH_CTL] =
		SITAR_A_CDC_CLSG_GAIN_THRESH_CTL__POR,
	[SITAR_A_CDC_CLSG_TIMER_B1_CFG] = SITAR_A_CDC_CLSG_TIMER_B1_CFG__POR,
	[SITAR_A_CDC_CLSG_TIMER_B2_CFG] = SITAR_A_CDC_CLSG_TIMER_B2_CFG__POR,
	[SITAR_A_CDC_CLSG_CTL] = SITAR_A_CDC_CLSG_CTL__POR,
	[SITAR_A_CDC_IIR1_GAIN_B1_CTL] = SITAR_A_CDC_IIR1_GAIN_B1_CTL__POR,
	[SITAR_A_CDC_IIR1_GAIN_B2_CTL] = SITAR_A_CDC_IIR1_GAIN_B2_CTL__POR,
	[SITAR_A_CDC_IIR1_GAIN_B3_CTL] = SITAR_A_CDC_IIR1_GAIN_B3_CTL__POR,
	[SITAR_A_CDC_IIR1_GAIN_B4_CTL] = SITAR_A_CDC_IIR1_GAIN_B4_CTL__POR,
	[SITAR_A_CDC_IIR1_GAIN_B5_CTL] = SITAR_A_CDC_IIR1_GAIN_B5_CTL__POR,
	[SITAR_A_CDC_IIR1_GAIN_B6_CTL] = SITAR_A_CDC_IIR1_GAIN_B6_CTL__POR,
	[SITAR_A_CDC_IIR1_GAIN_B7_CTL] = SITAR_A_CDC_IIR1_GAIN_B7_CTL__POR,
	[SITAR_A_CDC_IIR1_GAIN_B8_CTL] = SITAR_A_CDC_IIR1_GAIN_B8_CTL__POR,
	[SITAR_A_CDC_IIR1_CTL] = SITAR_A_CDC_IIR1_CTL__POR,
	[SITAR_A_CDC_IIR1_GAIN_TIMER_CTL] =
		SITAR_A_CDC_IIR1_GAIN_TIMER_CTL__POR,
	[SITAR_A_CDC_IIR1_COEF_B1_CTL] = SITAR_A_CDC_IIR1_COEF_B1_CTL__POR,
	[SITAR_A_CDC_IIR1_COEF_B2_CTL] = SITAR_A_CDC_IIR1_COEF_B2_CTL__POR,
	[SITAR_A_CDC_IIR1_COEF_B3_CTL] = SITAR_A_CDC_IIR1_COEF_B3_CTL__POR,
	[SITAR_A_CDC_IIR1_COEF_B4_CTL] = SITAR_A_CDC_IIR1_COEF_B4_CTL__POR,
	[SITAR_A_CDC_IIR1_COEF_B5_CTL] = SITAR_A_CDC_IIR1_COEF_B5_CTL__POR,
	[SITAR_A_CDC_IIR2_GAIN_B1_CTL] = SITAR_A_CDC_IIR2_GAIN_B1_CTL__POR,
	[SITAR_A_CDC_IIR2_GAIN_B2_CTL] = SITAR_A_CDC_IIR2_GAIN_B2_CTL__POR,
	[SITAR_A_CDC_IIR2_GAIN_B3_CTL] = SITAR_A_CDC_IIR2_GAIN_B3_CTL__POR,
	[SITAR_A_CDC_IIR2_GAIN_B4_CTL] = SITAR_A_CDC_IIR2_GAIN_B4_CTL__POR,
	[SITAR_A_CDC_IIR2_GAIN_B5_CTL] = SITAR_A_CDC_IIR2_GAIN_B5_CTL__POR,
	[SITAR_A_CDC_IIR2_GAIN_B6_CTL] = SITAR_A_CDC_IIR2_GAIN_B6_CTL__POR,
	[SITAR_A_CDC_IIR2_GAIN_B7_CTL] = SITAR_A_CDC_IIR2_GAIN_B7_CTL__POR,
	[SITAR_A_CDC_IIR2_GAIN_B8_CTL] = SITAR_A_CDC_IIR2_GAIN_B8_CTL__POR,
	[SITAR_A_CDC_IIR2_CTL] = SITAR_A_CDC_IIR2_CTL__POR,
	[SITAR_A_CDC_IIR2_GAIN_TIMER_CTL] =
		SITAR_A_CDC_IIR2_GAIN_TIMER_CTL__POR,
	[SITAR_A_CDC_IIR2_COEF_B1_CTL] = SITAR_A_CDC_IIR2_COEF_B1_CTL__POR,
	[SITAR_A_CDC_IIR2_COEF_B2_CTL] = SITAR_A_CDC_IIR2_COEF_B2_CTL__POR,
	[SITAR_A_CDC_IIR2_COEF_B3_CTL] = SITAR_A_CDC_IIR2_COEF_B3_CTL__POR,
	[SITAR_A_CDC_IIR2_COEF_B4_CTL] = SITAR_A_CDC_IIR2_COEF_B4_CTL__POR,
	[SITAR_A_CDC_IIR2_COEF_B5_CTL] = SITAR_A_CDC_IIR2_COEF_B5_CTL__POR,
	[SITAR_A_CDC_TOP_GAIN_UPDATE] = SITAR_A_CDC_TOP_GAIN_UPDATE__POR,
	[SITAR_A_CDC_TOP_RDAC_DOUT_CTL] = SITAR_A_CDC_TOP_RDAC_DOUT_CTL__POR,
	[SITAR_A_CDC_DEBUG_B1_CTL] = SITAR_A_CDC_DEBUG_B1_CTL__POR,
	[SITAR_A_CDC_DEBUG_B2_CTL] = SITAR_A_CDC_DEBUG_B2_CTL__POR,
	[SITAR_A_CDC_DEBUG_B3_CTL] = SITAR_A_CDC_DEBUG_B3_CTL__POR,
	[SITAR_A_CDC_DEBUG_B4_CTL] = SITAR_A_CDC_DEBUG_B4_CTL__POR,
	[SITAR_A_CDC_DEBUG_B5_CTL] = SITAR_A_CDC_DEBUG_B5_CTL__POR,
	[SITAR_A_CDC_DEBUG_B6_CTL] = SITAR_A_CDC_DEBUG_B6_CTL__POR,
	[SITAR_A_CDC_DEBUG_B7_CTL] = SITAR_A_CDC_DEBUG_B7_CTL__POR,
	[SITAR_A_CDC_COMP1_B1_CTL] = SITAR_A_CDC_COMP1_B1_CTL__POR,
	[SITAR_A_CDC_COMP1_B2_CTL] = SITAR_A_CDC_COMP1_B2_CTL__POR,
	[SITAR_A_CDC_COMP1_B3_CTL] = SITAR_A_CDC_COMP1_B3_CTL__POR,
	[SITAR_A_CDC_COMP1_B4_CTL] = SITAR_A_CDC_COMP1_B4_CTL__POR,
	[SITAR_A_CDC_COMP1_B5_CTL] = SITAR_A_CDC_COMP1_B5_CTL__POR,
	[SITAR_A_CDC_COMP1_B6_CTL] = SITAR_A_CDC_COMP1_B6_CTL__POR,
	[SITAR_A_CDC_COMP1_SHUT_DOWN_STATUS] =
		SITAR_A_CDC_COMP1_SHUT_DOWN_STATUS__POR,
	[SITAR_A_CDC_COMP1_FS_CFG] = SITAR_A_CDC_COMP1_FS_CFG__POR,
	[SITAR_A_CDC_CONN_RX1_B1_CTL] = SITAR_A_CDC_CONN_RX1_B1_CTL__POR,
	[SITAR_A_CDC_CONN_RX1_B2_CTL] = SITAR_A_CDC_CONN_RX1_B2_CTL__POR,
	[SITAR_A_CDC_CONN_RX1_B3_CTL] = SITAR_A_CDC_CONN_RX1_B3_CTL__POR,
	[SITAR_A_CDC_CONN_RX2_B1_CTL] = SITAR_A_CDC_CONN_RX2_B1_CTL__POR,
	[SITAR_A_CDC_CONN_RX2_B2_CTL] = SITAR_A_CDC_CONN_RX2_B2_CTL__POR,
	[SITAR_A_CDC_CONN_RX2_B3_CTL] = SITAR_A_CDC_CONN_RX2_B3_CTL__POR,
	[SITAR_A_CDC_CONN_RX3_B1_CTL] = SITAR_A_CDC_CONN_RX3_B1_CTL__POR,
	[SITAR_A_CDC_CONN_RX3_B2_CTL] = SITAR_A_CDC_CONN_RX3_B2_CTL__POR,
	[SITAR_A_CDC_CONN_RX3_B3_CTL] = SITAR_A_CDC_CONN_RX3_B3_CTL__POR,
	[SITAR_A_CDC_CONN_ANC_B1_CTL] = SITAR_A_CDC_CONN_ANC_B1_CTL__POR,
	[SITAR_A_CDC_CONN_ANC_B2_CTL] = SITAR_A_CDC_CONN_ANC_B2_CTL__POR,
	[SITAR_A_CDC_CONN_TX_B1_CTL] = SITAR_A_CDC_CONN_TX_B1_CTL__POR,
	[SITAR_A_CDC_CONN_TX_B2_CTL] = SITAR_A_CDC_CONN_TX_B2_CTL__POR,
	[SITAR_A_CDC_CONN_EQ1_B1_CTL] = SITAR_A_CDC_CONN_EQ1_B1_CTL__POR,
	[SITAR_A_CDC_CONN_EQ1_B2_CTL] = SITAR_A_CDC_CONN_EQ1_B2_CTL__POR,
	[SITAR_A_CDC_CONN_EQ1_B3_CTL] = SITAR_A_CDC_CONN_EQ1_B3_CTL__POR,
	[SITAR_A_CDC_CONN_EQ1_B4_CTL] = SITAR_A_CDC_CONN_EQ1_B4_CTL__POR,
	[SITAR_A_CDC_CONN_EQ2_B1_CTL] = SITAR_A_CDC_CONN_EQ2_B1_CTL__POR,
	[SITAR_A_CDC_CONN_EQ2_B2_CTL] = SITAR_A_CDC_CONN_EQ2_B2_CTL__POR,
	[SITAR_A_CDC_CONN_EQ2_B3_CTL] = SITAR_A_CDC_CONN_EQ2_B3_CTL__POR,
	[SITAR_A_CDC_CONN_EQ2_B4_CTL] = SITAR_A_CDC_CONN_EQ2_B4_CTL__POR,
	[SITAR_A_CDC_CONN_SRC1_B1_CTL] = SITAR_A_CDC_CONN_SRC1_B1_CTL__POR,
	[SITAR_A_CDC_CONN_SRC1_B2_CTL] = SITAR_A_CDC_CONN_SRC1_B2_CTL__POR,
	[SITAR_A_CDC_CONN_SRC2_B1_CTL] = SITAR_A_CDC_CONN_SRC2_B1_CTL__POR,
	[SITAR_A_CDC_CONN_SRC2_B2_CTL] = SITAR_A_CDC_CONN_SRC2_B2_CTL__POR,
	[SITAR_A_CDC_CONN_TX_SB_B1_CTL] = SITAR_A_CDC_CONN_TX_SB_B1_CTL__POR,
	[SITAR_A_CDC_CONN_TX_SB_B2_CTL] = SITAR_A_CDC_CONN_TX_SB_B2_CTL__POR,
	[SITAR_A_CDC_CONN_TX_SB_B3_CTL] = SITAR_A_CDC_CONN_TX_SB_B3_CTL__POR,
	[SITAR_A_CDC_CONN_TX_SB_B4_CTL] = SITAR_A_CDC_CONN_TX_SB_B4_CTL__POR,
	[SITAR_A_CDC_CONN_TX_SB_B5_CTL] = SITAR_A_CDC_CONN_TX_SB_B5_CTL__POR,
	[SITAR_A_CDC_CONN_RX_SB_B1_CTL] = SITAR_A_CDC_CONN_RX_SB_B1_CTL__POR,
	[SITAR_A_CDC_CONN_RX_SB_B2_CTL] = SITAR_A_CDC_CONN_RX_SB_B2_CTL__POR,
	[SITAR_A_CDC_CONN_CLSG_CTL] = SITAR_A_CDC_CONN_CLSG_CTL__POR,
	[SITAR_A_CDC_CONN_SPARE] = SITAR_A_CDC_CONN_SPARE__POR,
	[SITAR_A_CDC_MBHC_EN_CTL] = SITAR_A_CDC_MBHC_EN_CTL__POR,
	[SITAR_A_CDC_MBHC_FIR_B1_CFG] = SITAR_A_CDC_MBHC_FIR_B1_CFG__POR,
	[SITAR_A_CDC_MBHC_FIR_B2_CFG] = SITAR_A_CDC_MBHC_FIR_B2_CFG__POR,
	[SITAR_A_CDC_MBHC_TIMER_B1_CTL] = SITAR_A_CDC_MBHC_TIMER_B1_CTL__POR,
	[SITAR_A_CDC_MBHC_TIMER_B2_CTL] = SITAR_A_CDC_MBHC_TIMER_B2_CTL__POR,
	[SITAR_A_CDC_MBHC_TIMER_B3_CTL] = SITAR_A_CDC_MBHC_TIMER_B3_CTL__POR,
	[SITAR_A_CDC_MBHC_TIMER_B4_CTL] = SITAR_A_CDC_MBHC_TIMER_B4_CTL__POR,
	[SITAR_A_CDC_MBHC_TIMER_B5_CTL] = SITAR_A_CDC_MBHC_TIMER_B5_CTL__POR,
	[SITAR_A_CDC_MBHC_TIMER_B6_CTL] = SITAR_A_CDC_MBHC_TIMER_B6_CTL__POR,
	[SITAR_A_CDC_MBHC_B1_STATUS] = SITAR_A_CDC_MBHC_B1_STATUS__POR,
	[SITAR_A_CDC_MBHC_B2_STATUS] = SITAR_A_CDC_MBHC_B2_STATUS__POR,
	[SITAR_A_CDC_MBHC_B3_STATUS] = SITAR_A_CDC_MBHC_B3_STATUS__POR,
	[SITAR_A_CDC_MBHC_B4_STATUS] = SITAR_A_CDC_MBHC_B4_STATUS__POR,
	[SITAR_A_CDC_MBHC_B5_STATUS] = SITAR_A_CDC_MBHC_B5_STATUS__POR,
	[SITAR_A_CDC_MBHC_B1_CTL] = SITAR_A_CDC_MBHC_B1_CTL__POR,
	[SITAR_A_CDC_MBHC_B2_CTL] = SITAR_A_CDC_MBHC_B2_CTL__POR,
	[SITAR_A_CDC_MBHC_VOLT_B1_CTL] = SITAR_A_CDC_MBHC_VOLT_B1_CTL__POR,
	[SITAR_A_CDC_MBHC_VOLT_B2_CTL] = SITAR_A_CDC_MBHC_VOLT_B2_CTL__POR,
	[SITAR_A_CDC_MBHC_VOLT_B3_CTL] = SITAR_A_CDC_MBHC_VOLT_B3_CTL__POR,
	[SITAR_A_CDC_MBHC_VOLT_B4_CTL] = SITAR_A_CDC_MBHC_VOLT_B4_CTL__POR,
	[SITAR_A_CDC_MBHC_VOLT_B5_CTL] = SITAR_A_CDC_MBHC_VOLT_B5_CTL__POR,
	[SITAR_A_CDC_MBHC_VOLT_B6_CTL] = SITAR_A_CDC_MBHC_VOLT_B6_CTL__POR,
	[SITAR_A_CDC_MBHC_VOLT_B7_CTL] = SITAR_A_CDC_MBHC_VOLT_B7_CTL__POR,
	[SITAR_A_CDC_MBHC_VOLT_B8_CTL] = SITAR_A_CDC_MBHC_VOLT_B8_CTL__POR,
	[SITAR_A_CDC_MBHC_VOLT_B9_CTL] = SITAR_A_CDC_MBHC_VOLT_B9_CTL__POR,
	[SITAR_A_CDC_MBHC_VOLT_B10_CTL] = SITAR_A_CDC_MBHC_VOLT_B10_CTL__POR,
	[SITAR_A_CDC_MBHC_VOLT_B11_CTL] = SITAR_A_CDC_MBHC_VOLT_B11_CTL__POR,
	[SITAR_A_CDC_MBHC_VOLT_B12_CTL] = SITAR_A_CDC_MBHC_VOLT_B12_CTL__POR,
	[SITAR_A_CDC_MBHC_CLK_CTL] = SITAR_A_CDC_MBHC_CLK_CTL__POR,
	[SITAR_A_CDC_MBHC_INT_CTL] = SITAR_A_CDC_MBHC_INT_CTL__POR,
	[SITAR_A_CDC_MBHC_DEBUG_CTL] = SITAR_A_CDC_MBHC_DEBUG_CTL__POR,
	[SITAR_A_CDC_MBHC_SPARE] = SITAR_A_CDC_MBHC_SPARE__POR,
};

const u8 sitar_reg_readable[SITAR_CACHE_SIZE] = {
	[WCD9XXX_A_CHIP_CTL] = 1,
	[WCD9XXX_A_CHIP_STATUS] = 1,
	[WCD9XXX_A_CHIP_ID_BYTE_0] = 1,
	[WCD9XXX_A_CHIP_ID_BYTE_1] = 1,
	[WCD9XXX_A_CHIP_ID_BYTE_2] = 1,
	[WCD9XXX_A_CHIP_ID_BYTE_3] = 1,
	[WCD9XXX_A_CHIP_VERSION] = 1,
	[WCD9XXX_A_SB_VERSION] = 1,
	[WCD9XXX_A_SLAVE_ID_1] = 1,
	[WCD9XXX_A_SLAVE_ID_2] = 1,
	[WCD9XXX_A_SLAVE_ID_3] = 1,
	[SITAR_A_PIN_CTL_OE0] = 1,
	[SITAR_A_PIN_CTL_OE1] = 1,
	[SITAR_A_PIN_CTL_DATA0] = 1,
	[SITAR_A_PIN_CTL_DATA1] = 1,
	[SITAR_A_HDRIVE_GENERIC] = 1,
	[SITAR_A_HDRIVE_OVERRIDE] = 1,
	[SITAR_A_ANA_CSR_WAIT_STATE] = 1,
	[SITAR_A_PROCESS_MONITOR_CTL0] = 1,
	[SITAR_A_PROCESS_MONITOR_CTL1] = 1,
	[SITAR_A_PROCESS_MONITOR_CTL2] = 1,
	[SITAR_A_PROCESS_MONITOR_CTL3] = 1,
	[SITAR_A_QFUSE_CTL] = 1,
	[SITAR_A_QFUSE_STATUS] = 1,
	[SITAR_A_QFUSE_DATA_OUT0] = 1,
	[SITAR_A_QFUSE_DATA_OUT1] = 1,
	[SITAR_A_QFUSE_DATA_OUT2] = 1,
	[SITAR_A_QFUSE_DATA_OUT3] = 1,
	[SITAR_A_QFUSE_DATA_OUT4] = 1,
	[SITAR_A_QFUSE_DATA_OUT5] = 1,
	[SITAR_A_QFUSE_DATA_OUT6] = 1,
	[SITAR_A_QFUSE_DATA_OUT7] = 1,
	[SITAR_A_CDC_CTL] = 1,
	[SITAR_A_LEAKAGE_CTL] = 1,
	[SITAR_A_INTR_MODE] = 1,
	[SITAR_A_INTR_MASK0] = 1,
	[SITAR_A_INTR_MASK1] = 1,
	[SITAR_A_INTR_MASK2] = 1,
	[SITAR_A_INTR_STATUS0] = 1,
	[SITAR_A_INTR_STATUS1] = 1,
	[SITAR_A_INTR_STATUS2] = 1,
	[SITAR_A_INTR_CLEAR0] = 1,
	[SITAR_A_INTR_CLEAR1] = 1,
	[SITAR_A_INTR_CLEAR2] = 1,
	[SITAR_A_INTR_LEVEL0] = 1,
	[SITAR_A_INTR_LEVEL1] = 1,
	[SITAR_A_INTR_LEVEL2] = 1,
	[SITAR_A_INTR_TEST0] = 1,
	[SITAR_A_INTR_TEST1] = 1,
	[SITAR_A_INTR_TEST2] = 1,
	[SITAR_A_INTR_SET0] = 1,
	[SITAR_A_INTR_SET1] = 1,
	[SITAR_A_INTR_SET2] = 1,
	[SITAR_A_CDC_TX_I2S_SCK_MODE] = 1,
	[SITAR_A_CDC_TX_I2S_WS_MODE] = 1,
	[SITAR_A_CDC_DMIC_DATA0_MODE] = 1,
	[SITAR_A_CDC_DMIC_CLK0_MODE] = 1,
	[SITAR_A_CDC_DMIC_DATA1_MODE] = 1,
	[SITAR_A_CDC_DMIC_CLK1_MODE] = 1,
	[SITAR_A_CDC_TX_I2S_SD0_MODE] = 1,
	[SITAR_A_CDC_INTR_MODE] = 1,
	[SITAR_A_CDC_RX_I2S_SD0_MODE] = 1,
	[SITAR_A_CDC_RX_I2S_SD1_MODE] = 1,
	[SITAR_A_BIAS_REF_CTL] = 1,
	[SITAR_A_BIAS_CENTRAL_BG_CTL] = 1,
	[SITAR_A_BIAS_PRECHRG_CTL] = 1,
	[SITAR_A_BIAS_CURR_CTL_1] = 1,
	[SITAR_A_BIAS_CURR_CTL_2] = 1,
	[SITAR_A_BIAS_OSC_BG_CTL] = 1,
	[SITAR_A_CLK_BUFF_EN1] = 1,
	[SITAR_A_CLK_BUFF_EN2] = 1,
	[SITAR_A_LDO_H_MODE_1] = 1,
	[SITAR_A_LDO_H_MODE_2] = 1,
	[SITAR_A_LDO_H_LOOP_CTL] = 1,
	[SITAR_A_LDO_H_COMP_1] = 1,
	[SITAR_A_LDO_H_COMP_2] = 1,
	[SITAR_A_LDO_H_BIAS_1] = 1,
	[SITAR_A_LDO_H_BIAS_2] = 1,
	[SITAR_A_LDO_H_BIAS_3] = 1,
	[SITAR_A_MICB_CFILT_1_CTL] = 1,
	[SITAR_A_MICB_CFILT_1_VAL] = 1,
	[SITAR_A_MICB_CFILT_1_PRECHRG] = 1,
	[SITAR_A_MICB_1_CTL] = 1,
	[SITAR_A_MICB_1_INT_RBIAS] = 1,
	[SITAR_A_MICB_1_MBHC] = 1,
	[SITAR_A_MICB_CFILT_2_CTL] = 1,
	[SITAR_A_MICB_CFILT_2_VAL] = 1,
	[SITAR_A_MICB_CFILT_2_PRECHRG] = 1,
	[SITAR_A_MICB_2_CTL] = 1,
	[SITAR_A_MICB_2_INT_RBIAS] = 1,
	[SITAR_A_MICB_2_MBHC] = 1,
	[SITAR_A_TX_COM_BIAS] = 1,
	[SITAR_A_MBHC_SCALING_MUX_1] = 1,
	[SITAR_A_MBHC_SCALING_MUX_2] = 1,
	[SITAR_A_TX_SUP_SWITCH_CTRL_1] = 1,
	[SITAR_A_TX_SUP_SWITCH_CTRL_2] = 1,
	[SITAR_A_TX_1_2_EN] = 1,
	[SITAR_A_TX_1_2_TEST_EN] = 1,
	[SITAR_A_TX_1_2_ADC_CH1] = 1,
	[SITAR_A_TX_1_2_ADC_CH2] = 1,
	[SITAR_A_TX_1_2_ATEST_REFCTRL] = 1,
	[SITAR_A_TX_1_2_TEST_CTL] = 1,
	[SITAR_A_TX_1_2_TEST_BLOCK_EN] = 1,
	[SITAR_A_TX_1_2_TXFE_CLKDIV] = 1,
	[SITAR_A_TX_1_2_SAR_ERR_CH1] = 1,
	[SITAR_A_TX_1_2_SAR_ERR_CH2] = 1,
	[SITAR_A_TX_3_EN] = 1,
	[SITAR_A_TX_3_TEST_EN] = 1,
	[SITAR_A_TX_3_ADC] = 1,
	[SITAR_A_TX_3_MBHC_ATEST_REFCTRL] = 1,
	[SITAR_A_TX_3_TEST_CTL] = 1,
	[SITAR_A_TX_3_TEST_BLOCK_EN] = 1,
	[SITAR_A_TX_3_TXFE_CKDIV] = 1,
	[SITAR_A_TX_3_SAR_ERR] = 1,
	[SITAR_A_TX_4_MBHC_EN] = 1,
	[SITAR_A_TX_4_MBHC_ADC] = 1,
	[SITAR_A_TX_4_MBHC_TEST_CTL] = 1,
	[SITAR_A_TX_4_MBHC_SAR_ERR] = 1,
	[SITAR_A_TX_4_TXFE_CLKDIV] = 1,
	[SITAR_A_AUX_COM_CTL] = 1,
	[SITAR_A_AUX_COM_ATEST] = 1,
	[SITAR_A_AUX_L_EN] = 1,
	[SITAR_A_AUX_L_GAIN] = 1,
	[SITAR_A_AUX_L_PA_CONN] = 1,
	[SITAR_A_AUX_L_PA_CONN_INV] = 1,
	[SITAR_A_AUX_R_EN] = 1,
	[SITAR_A_AUX_R_GAIN] = 1,
	[SITAR_A_AUX_R_PA_CONN] = 1,
	[SITAR_A_AUX_R_PA_CONN_INV] = 1,
	[SITAR_A_CP_EN] = 1,
	[SITAR_A_CP_CLK] = 1,
	[SITAR_A_CP_STATIC] = 1,
	[SITAR_A_CP_DCC1] = 1,
	[SITAR_A_CP_DCC3] = 1,
	[SITAR_A_CP_ATEST] = 1,
	[SITAR_A_CP_DTEST] = 1,
	[SITAR_A_RX_COM_TIMER_DIV] = 1,
	[SITAR_A_RX_COM_OCP_CTL] = 1,
	[SITAR_A_RX_COM_OCP_COUNT] = 1,
	[SITAR_A_RX_COM_DAC_CTL] = 1,
	[SITAR_A_RX_COM_BIAS] = 1,
	[SITAR_A_RX_HPH_BIAS_PA] = 1,
	[SITAR_A_RX_HPH_BIAS_LDO] = 1,
	[SITAR_A_RX_HPH_BIAS_CNP] = 1,
	[SITAR_A_RX_HPH_BIAS_WG] = 1,
	[SITAR_A_RX_HPH_OCP_CTL] = 1,
	[SITAR_A_RX_HPH_CNP_EN] = 1,
	[SITAR_A_RX_HPH_CNP_WG_CTL] = 1,
	[SITAR_A_RX_HPH_CNP_WG_TIME] = 1,
	[SITAR_A_RX_HPH_L_GAIN] = 1,
	[SITAR_A_RX_HPH_L_TEST] = 1,
	[SITAR_A_RX_HPH_L_PA_CTL] = 1,
	[SITAR_A_RX_HPH_L_DAC_CTL] = 1,
	[SITAR_A_RX_HPH_L_ATEST] = 1,
	[SITAR_A_RX_HPH_L_STATUS] = 1,
	[SITAR_A_RX_HPH_R_GAIN] = 1,
	[SITAR_A_RX_HPH_R_TEST] = 1,
	[SITAR_A_RX_HPH_R_PA_CTL] = 1,
	[SITAR_A_RX_HPH_R_DAC_CTL] = 1,
	[SITAR_A_RX_HPH_R_ATEST] = 1,
	[SITAR_A_RX_HPH_R_STATUS] = 1,
	[SITAR_A_RX_EAR_BIAS_PA] = 1,
	[SITAR_A_RX_EAR_BIAS_CMBUFF] = 1,
	[SITAR_A_RX_EAR_EN] = 1,
	[SITAR_A_RX_EAR_GAIN] = 1,
	[SITAR_A_RX_EAR_CMBUFF] = 1,
	[SITAR_A_RX_EAR_ICTL] = 1,
	[SITAR_A_RX_EAR_CCOMP] = 1,
	[SITAR_A_RX_EAR_VCM] = 1,
	[SITAR_A_RX_EAR_CNP] = 1,
	[SITAR_A_RX_EAR_ATEST] = 1,
	[SITAR_A_RX_EAR_STATUS] = 1,
	[SITAR_A_RX_LINE_BIAS_PA] = 1,
	[SITAR_A_RX_LINE_BIAS_LDO] = 1,
	[SITAR_A_RX_LINE_BIAS_CNP1] = 1,
	[SITAR_A_RX_LINE_COM] = 1,
	[SITAR_A_RX_LINE_CNP_EN] = 1,
	[SITAR_A_RX_LINE_CNP_WG_CTL] = 1,
	[SITAR_A_RX_LINE_CNP_WG_TIME] = 1,
	[SITAR_A_RX_LINE_1_GAIN] = 1,
	[SITAR_A_RX_LINE_1_TEST] = 1,
	[SITAR_A_RX_LINE_1_DAC_CTL] = 1,
	[SITAR_A_RX_LINE_1_STATUS] = 1,
	[SITAR_A_RX_LINE_2_GAIN] = 1,
	[SITAR_A_RX_LINE_2_TEST] = 1,
	[SITAR_A_RX_LINE_2_DAC_CTL] = 1,
	[SITAR_A_RX_LINE_2_STATUS] = 1,
	[SITAR_A_RX_LINE_BIAS_CNP2] = 1,
	[SITAR_A_RX_LINE_OCP_CTL] = 1,
	[SITAR_A_RX_LINE_1_PA_CTL] = 1,
	[SITAR_A_RX_LINE_2_PA_CTL] = 1,
	[SITAR_A_RX_LINE_CNP_DBG] = 1,
	[SITAR_A_MBHC_HPH] = 1,
	[SITAR_A_RC_OSC_FREQ] = 1,
	[SITAR_A_RC_OSC_TEST] = 1,
	[SITAR_A_RC_OSC_STATUS] = 1,
	[SITAR_A_RC_OSC_TUNER] = 1,
	[SITAR_A_CDC_ANC1_CTL] = 1,
	[SITAR_A_CDC_ANC1_SHIFT] = 1,
	[SITAR_A_CDC_ANC1_IIR_B1_CTL] = 1,
	[SITAR_A_CDC_ANC1_IIR_B2_CTL] = 1,
	[SITAR_A_CDC_ANC1_IIR_B3_CTL] = 1,
	[SITAR_A_CDC_ANC1_IIR_B4_CTL] = 1,
	[SITAR_A_CDC_ANC1_LPF_B1_CTL] = 1,
	[SITAR_A_CDC_ANC1_LPF_B2_CTL] = 1,
	[SITAR_A_CDC_ANC1_LPF_B3_CTL] = 1,
	[SITAR_A_CDC_ANC1_SPARE] = 1,
	[SITAR_A_CDC_ANC1_SMLPF_CTL] = 1,
	[SITAR_A_CDC_ANC1_DCFLT_CTL] = 1,
	[SITAR_A_CDC_ANC2_CTL] = 1,
	[SITAR_A_CDC_ANC2_SHIFT] = 1,
	[SITAR_A_CDC_ANC2_IIR_B1_CTL] = 1,
	[SITAR_A_CDC_ANC2_IIR_B2_CTL] = 1,
	[SITAR_A_CDC_ANC2_IIR_B3_CTL] = 1,
	[SITAR_A_CDC_ANC2_IIR_B4_CTL] = 1,
	[SITAR_A_CDC_ANC2_LPF_B1_CTL] = 1,
	[SITAR_A_CDC_ANC2_LPF_B2_CTL] = 1,
	[SITAR_A_CDC_ANC2_LPF_B3_CTL] = 1,
	[SITAR_A_CDC_ANC2_SPARE] = 1,
	[SITAR_A_CDC_ANC2_SMLPF_CTL] = 1,
	[SITAR_A_CDC_ANC2_DCFLT_CTL] = 1,
	[SITAR_A_CDC_TX1_VOL_CTL_TIMER] = 1,
	[SITAR_A_CDC_TX1_VOL_CTL_GAIN] = 1,
	[SITAR_A_CDC_TX1_VOL_CTL_CFG] = 1,
	[SITAR_A_CDC_TX1_MUX_CTL] = 1,
	[SITAR_A_CDC_TX1_CLK_FS_CTL] = 1,
	[SITAR_A_CDC_TX1_DMIC_CTL] = 1,
	[SITAR_A_CDC_TX2_VOL_CTL_TIMER] = 1,
	[SITAR_A_CDC_TX2_VOL_CTL_GAIN] = 1,
	[SITAR_A_CDC_TX2_VOL_CTL_CFG] = 1,
	[SITAR_A_CDC_TX2_MUX_CTL] = 1,
	[SITAR_A_CDC_TX2_CLK_FS_CTL] = 1,
	[SITAR_A_CDC_TX2_DMIC_CTL] = 1,
	[SITAR_A_CDC_TX3_VOL_CTL_TIMER] = 1,
	[SITAR_A_CDC_TX3_VOL_CTL_GAIN] = 1,
	[SITAR_A_CDC_TX3_VOL_CTL_CFG] = 1,
	[SITAR_A_CDC_TX3_MUX_CTL] = 1,
	[SITAR_A_CDC_TX3_CLK_FS_CTL] = 1,
	[SITAR_A_CDC_TX3_DMIC_CTL] = 1,
	[SITAR_A_CDC_TX4_VOL_CTL_TIMER] = 1,
	[SITAR_A_CDC_TX4_VOL_CTL_GAIN] = 1,
	[SITAR_A_CDC_TX4_VOL_CTL_CFG] = 1,
	[SITAR_A_CDC_TX4_MUX_CTL] = 1,
	[SITAR_A_CDC_TX4_CLK_FS_CTL] = 1,
	[SITAR_A_CDC_TX4_DMIC_CTL] = 1,
	[SITAR_A_CDC_TX5_VOL_CTL_TIMER] = 1,
	[SITAR_A_CDC_TX5_VOL_CTL_GAIN] = 1,
	[SITAR_A_CDC_TX5_VOL_CTL_CFG] = 1,
	[SITAR_A_CDC_TX5_MUX_CTL] = 1,
	[SITAR_A_CDC_TX5_CLK_FS_CTL] = 1,
	[SITAR_A_CDC_TX5_DMIC_CTL] = 1,
	[SITAR_A_CDC_SRC1_PDA_CFG] = 1,
	[SITAR_A_CDC_SRC1_FS_CTL] = 1,
	[SITAR_A_CDC_SRC2_PDA_CFG] = 1,
	[SITAR_A_CDC_SRC2_FS_CTL] = 1,
	[SITAR_A_CDC_RX1_B1_CTL] = 1,
	[SITAR_A_CDC_RX1_B2_CTL] = 1,
	[SITAR_A_CDC_RX1_B3_CTL] = 1,
	[SITAR_A_CDC_RX1_B4_CTL] = 1,
	[SITAR_A_CDC_RX1_B5_CTL] = 1,
	[SITAR_A_CDC_RX1_B6_CTL] = 1,
	[SITAR_A_CDC_RX1_VOL_CTL_B1_CTL] = 1,
	[SITAR_A_CDC_RX1_VOL_CTL_B2_CTL] = 1,
	[SITAR_A_CDC_RX2_B1_CTL] = 1,
	[SITAR_A_CDC_RX2_B2_CTL] = 1,
	[SITAR_A_CDC_RX2_B3_CTL] = 1,
	[SITAR_A_CDC_RX2_B4_CTL] = 1,
	[SITAR_A_CDC_RX2_B5_CTL] = 1,
/*[PLATFORM]-Mod-BEGIN by TCTNB.YuBin, 2013/7/7, Remove headset left ear noise to resolved pr453599*/
	//[SITAR_A_CDC_RX2_B6_CTL] = 1,
/*[PLATFORM]-Mod-END by TCTNB.YuBin*/
	[SITAR_A_CDC_RX2_VOL_CTL_B1_CTL] = 1,
	[SITAR_A_CDC_RX2_VOL_CTL_B2_CTL] = 1,
	[SITAR_A_CDC_RX3_B1_CTL] = 1,
	[SITAR_A_CDC_RX3_B2_CTL] = 1,
	[SITAR_A_CDC_RX3_B3_CTL] = 1,
	[SITAR_A_CDC_RX3_B4_CTL] = 1,
	[SITAR_A_CDC_RX3_B5_CTL] = 1,
/*[PLATFORM]-Mod-BEGIN by TCTNB.YuBin, 2013/7/7, Remove headset right ear noise to resolved pr453599*/
	//[SITAR_A_CDC_RX3_B6_CTL] = 1,
/*[PLATFORM]-Mod-END by TCTNB.YuBin*/
	[SITAR_A_CDC_RX3_VOL_CTL_B1_CTL] = 1,
	[SITAR_A_CDC_RX3_VOL_CTL_B2_CTL] = 1,
	[SITAR_A_CDC_CLK_ANC_RESET_CTL] = 1,
	[SITAR_A_CDC_CLK_RX_RESET_CTL] = 1,
	[SITAR_A_CDC_CLK_TX_RESET_B1_CTL] = 1,
	[SITAR_A_CDC_CLK_TX_RESET_B2_CTL] = 1,
	[SITAR_A_CDC_CLK_DMIC_CTL] = 1,
	[SITAR_A_CDC_CLK_RX_I2S_CTL] = 1,
	[SITAR_A_CDC_CLK_TX_I2S_CTL] = 1,
	[SITAR_A_CDC_CLK_OTHR_RESET_CTL] = 1,
	[SITAR_A_CDC_CLK_TX_CLK_EN_B1_CTL] = 1,
	[SITAR_A_CDC_CLK_OTHR_CTL] = 1,
	[SITAR_A_CDC_CLK_RDAC_CLK_EN_CTL] = 1,
	[SITAR_A_CDC_CLK_ANC_CLK_EN_CTL] = 1,
	[SITAR_A_CDC_CLK_RX_B1_CTL] = 1,
	[SITAR_A_CDC_CLK_RX_B2_CTL] = 1,
	[SITAR_A_CDC_CLK_MCLK_CTL] = 1,
	[SITAR_A_CDC_CLK_PDM_CTL] = 1,
	[SITAR_A_CDC_CLK_SD_CTL] = 1,
	[SITAR_A_CDC_CLK_LP_CTL] = 1,
	[SITAR_A_CDC_CLSG_FREQ_THRESH_B1_CTL] = 1,
	[SITAR_A_CDC_CLSG_FREQ_THRESH_B2_CTL] = 1,
	[SITAR_A_CDC_CLSG_FREQ_THRESH_B3_CTL] = 1,
	[SITAR_A_CDC_CLSG_FREQ_THRESH_B4_CTL] = 1,
	[SITAR_A_CDC_CLSG_GAIN_THRESH_CTL] = 1,
	[SITAR_A_CDC_CLSG_TIMER_B1_CFG] = 1,
	[SITAR_A_CDC_CLSG_TIMER_B2_CFG] = 1,
	[SITAR_A_CDC_CLSG_CTL] = 1,
	[SITAR_A_CDC_IIR1_GAIN_B1_CTL] = 1,
	[SITAR_A_CDC_IIR1_GAIN_B2_CTL] = 1,
	[SITAR_A_CDC_IIR1_GAIN_B3_CTL] = 1,
	[SITAR_A_CDC_IIR1_GAIN_B4_CTL] = 1,
	[SITAR_A_CDC_IIR1_GAIN_B5_CTL] = 1,
	[SITAR_A_CDC_IIR1_GAIN_B6_CTL] = 1,
	[SITAR_A_CDC_IIR1_GAIN_B7_CTL] = 1,
	[SITAR_A_CDC_IIR1_GAIN_B8_CTL] = 1,
	[SITAR_A_CDC_IIR1_CTL] = 1,
	[SITAR_A_CDC_IIR1_GAIN_TIMER_CTL] = 1,
	[SITAR_A_CDC_IIR1_COEF_B1_CTL] = 1,
	[SITAR_A_CDC_IIR1_COEF_B2_CTL] = 1,
	[SITAR_A_CDC_IIR1_COEF_B3_CTL] = 1,
	[SITAR_A_CDC_IIR1_COEF_B4_CTL] = 1,
	[SITAR_A_CDC_IIR1_COEF_B5_CTL] = 1,
	[SITAR_A_CDC_IIR2_GAIN_B1_CTL] = 1,
	[SITAR_A_CDC_IIR2_GAIN_B2_CTL] = 1,
	[SITAR_A_CDC_IIR2_GAIN_B3_CTL] = 1,
	[SITAR_A_CDC_IIR2_GAIN_B4_CTL] = 1,
	[SITAR_A_CDC_IIR2_GAIN_B5_CTL] = 1,
	[SITAR_A_CDC_IIR2_GAIN_B6_CTL] = 1,
	[SITAR_A_CDC_IIR2_GAIN_B7_CTL] = 1,
	[SITAR_A_CDC_IIR2_GAIN_B8_CTL] = 1,
	[SITAR_A_CDC_IIR2_CTL] = 1,
	[SITAR_A_CDC_IIR2_GAIN_TIMER_CTL] = 1,
	[SITAR_A_CDC_IIR2_COEF_B1_CTL] = 1,
	[SITAR_A_CDC_IIR2_COEF_B2_CTL] = 1,
	[SITAR_A_CDC_IIR2_COEF_B3_CTL] = 1,
	[SITAR_A_CDC_IIR2_COEF_B4_CTL] = 1,
	[SITAR_A_CDC_IIR2_COEF_B5_CTL] = 1,
	[SITAR_A_CDC_TOP_GAIN_UPDATE] = 1,
	[SITAR_A_CDC_TOP_RDAC_DOUT_CTL] = 1,
	[SITAR_A_CDC_DEBUG_B1_CTL] = 1,
	[SITAR_A_CDC_DEBUG_B2_CTL] = 1,
	[SITAR_A_CDC_DEBUG_B3_CTL] = 1,
	[SITAR_A_CDC_DEBUG_B4_CTL] = 1,
	[SITAR_A_CDC_DEBUG_B5_CTL] = 1,
	[SITAR_A_CDC_DEBUG_B6_CTL] = 1,
	[SITAR_A_CDC_DEBUG_B7_CTL] = 1,
	[SITAR_A_CDC_COMP1_B1_CTL] = 1,
	[SITAR_A_CDC_COMP1_B2_CTL] = 1,
	[SITAR_A_CDC_COMP1_B3_CTL] = 1,
	[SITAR_A_CDC_COMP1_B4_CTL] = 1,
	[SITAR_A_CDC_COMP1_B5_CTL] = 1,
	[SITAR_A_CDC_COMP1_B6_CTL] = 1,
	[SITAR_A_CDC_COMP1_SHUT_DOWN_STATUS] = 1,
	[SITAR_A_CDC_COMP1_FS_CFG] = 1,
	[SITAR_A_CDC_COMP2_B1_CTL] = 1,
	[SITAR_A_CDC_COMP2_B2_CTL] = 1,
	[SITAR_A_CDC_COMP2_B3_CTL] = 1,
	[SITAR_A_CDC_COMP2_B4_CTL] = 1,
	[SITAR_A_CDC_COMP2_B5_CTL] = 1,
	[SITAR_A_CDC_COMP2_B6_CTL] = 1,
	[SITAR_A_CDC_COMP2_SHUT_DOWN_STATUS] = 1,
	[SITAR_A_CDC_COMP2_FS_CFG] = 1,
	[SITAR_A_CDC_CONN_RX1_B1_CTL] = 1,
	[SITAR_A_CDC_CONN_RX1_B2_CTL] = 1,
	[SITAR_A_CDC_CONN_RX1_B3_CTL] = 1,
	[SITAR_A_CDC_CONN_RX2_B1_CTL] = 1,
	[SITAR_A_CDC_CONN_RX2_B2_CTL] = 1,
	[SITAR_A_CDC_CONN_RX2_B3_CTL] = 1,
	[SITAR_A_CDC_CONN_RX3_B1_CTL] = 1,
	[SITAR_A_CDC_CONN_RX3_B2_CTL] = 1,
	[SITAR_A_CDC_CONN_RX3_B3_CTL] = 1,
	[SITAR_A_CDC_CONN_ANC_B1_CTL] = 1,
	[SITAR_A_CDC_CONN_ANC_B2_CTL] = 1,
	[SITAR_A_CDC_CONN_TX_B1_CTL] = 1,
	[SITAR_A_CDC_CONN_TX_B2_CTL] = 1,
	[SITAR_A_CDC_CONN_EQ1_B1_CTL] = 1,
	[SITAR_A_CDC_CONN_EQ1_B2_CTL] = 1,
	[SITAR_A_CDC_CONN_EQ1_B3_CTL] = 1,
	[SITAR_A_CDC_CONN_EQ1_B4_CTL] = 1,
	[SITAR_A_CDC_CONN_EQ2_B1_CTL] = 1,
	[SITAR_A_CDC_CONN_EQ2_B2_CTL] = 1,
	[SITAR_A_CDC_CONN_EQ2_B3_CTL] = 1,
	[SITAR_A_CDC_CONN_EQ2_B4_CTL] = 1,
	[SITAR_A_CDC_CONN_SRC1_B1_CTL] = 1,
	[SITAR_A_CDC_CONN_SRC1_B2_CTL] = 1,
	[SITAR_A_CDC_CONN_SRC2_B1_CTL] = 1,
	[SITAR_A_CDC_CONN_SRC2_B2_CTL] = 1,
	[SITAR_A_CDC_CONN_TX_SB_B1_CTL] = 1,
	[SITAR_A_CDC_CONN_TX_SB_B2_CTL] = 1,
	[SITAR_A_CDC_CONN_TX_SB_B3_CTL] = 1,
	[SITAR_A_CDC_CONN_TX_SB_B4_CTL] = 1,
	[SITAR_A_CDC_CONN_TX_SB_B5_CTL] = 1,
	[SITAR_A_CDC_CONN_RX_SB_B1_CTL] = 1,
	[SITAR_A_CDC_CONN_RX_SB_B2_CTL] = 1,
	[SITAR_A_CDC_CONN_CLSG_CTL] = 1,
	[SITAR_A_CDC_CONN_SPARE] = 1,
	[SITAR_A_CDC_MBHC_EN_CTL] = 1,
	[SITAR_A_CDC_MBHC_FIR_B1_CFG] = 1,
	[SITAR_A_CDC_MBHC_FIR_B2_CFG] = 1,
	[SITAR_A_CDC_MBHC_TIMER_B1_CTL] = 1,
	[SITAR_A_CDC_MBHC_TIMER_B2_CTL] = 1,
	[SITAR_A_CDC_MBHC_TIMER_B3_CTL] = 1,
	[SITAR_A_CDC_MBHC_TIMER_B4_CTL] = 1,
	[SITAR_A_CDC_MBHC_TIMER_B5_CTL] = 1,
	[SITAR_A_CDC_MBHC_TIMER_B6_CTL] = 1,
	[SITAR_A_CDC_MBHC_B1_STATUS] = 1,
	[SITAR_A_CDC_MBHC_B2_STATUS] = 1,
	[SITAR_A_CDC_MBHC_B3_STATUS] = 1,
	[SITAR_A_CDC_MBHC_B4_STATUS] = 1,
	[SITAR_A_CDC_MBHC_B5_STATUS] = 1,
	[SITAR_A_CDC_MBHC_B1_CTL] = 1,
	[SITAR_A_CDC_MBHC_B2_CTL] = 1,
	[SITAR_A_CDC_MBHC_VOLT_B1_CTL] = 1,
	[SITAR_A_CDC_MBHC_VOLT_B2_CTL] = 1,
	[SITAR_A_CDC_MBHC_VOLT_B3_CTL] = 1,
	[SITAR_A_CDC_MBHC_VOLT_B4_CTL] = 1,
	[SITAR_A_CDC_MBHC_VOLT_B5_CTL] = 1,
	[SITAR_A_CDC_MBHC_VOLT_B6_CTL] = 1,
	[SITAR_A_CDC_MBHC_VOLT_B7_CTL] = 1,
	[SITAR_A_CDC_MBHC_VOLT_B8_CTL] = 1,
	[SITAR_A_CDC_MBHC_VOLT_B9_CTL] = 1,
	[SITAR_A_CDC_MBHC_VOLT_B10_CTL] = 1,
	[SITAR_A_CDC_MBHC_VOLT_B11_CTL] = 1,
	[SITAR_A_CDC_MBHC_VOLT_B12_CTL] = 1,
	[SITAR_A_CDC_MBHC_CLK_CTL] = 1,
	[SITAR_A_CDC_MBHC_INT_CTL] = 1,
	[SITAR_A_CDC_MBHC_DEBUG_CTL] = 1,
	[SITAR_A_CDC_MBHC_SPARE] = 1,
};
