/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     driver_periph
 * @{
 * 
 * @file        adc.c
 * @brief       Low-level ADC driver implementation
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 * 
 * @}
 */


#include "periph/adc.h"
#include "periph_conf.h"






int adc_init(adc_t dev, int precision, void (*callback)(int))
{
    // GPIO_InitTypeDef GPIO_InitStructure;
    // ADC_InitTypeDef ADC_InitStructure;
    
    // RCC_ADCCLKConfig(RCC_PCLK2_Div6);
    
    // RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO | RCC_APB2Periph_ADC1, ENABLE);
    
    // GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    // GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    // GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    // GPIO_Init(GPIOC, &GPIO_InitStructure);
    
    // ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    // ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    // ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    // ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    // ADC_InitStructure.ADC_NbrOfChannel = 1;
    // ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    // ADC_Init(ADC1, &ADC_InitStructure);
     
    // ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_1Cycles5);
     
    // ADC_Cmd(ADC1, ENABLE);
     
    // ADC_SoftwareStartConvCmd(ADC1, ENABLE);
    return 0;
}
