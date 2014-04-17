/*
 * Copyright (C) 2013 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     board_stm32f0discovery
 * @{
 *
 * @file        periph_conf.h
 * @brief       Peripheral MCU configuration for the STM32F3discovery board
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#ifndef __PERIPH_CONF_H
#define __PERIPH_CONF_H


/**
 * @brief Timer configuration
 */
#define TIMER_NUMOF         (1U)
#define TIMER_0_EN          1
#define TIMER_1_EN          0

// Timer 0 configuration
#define TIMER_0_DEV         TIM2
#define TIMER_0_CHANNELS    4
#define TIMER_0_PRESCALER   (47U)
#define TIMER_0_MAX_VALUE   (0xffffffff)
#define TIMER_0_CLKEN()     RCC->APB1ENR |= RCC_APB1ENR_TIM2EN
#define TIMER_0_ISR         isr_tim2
#define TIMER_0_IRQ_CHAN    TIM2_IRQn
#define TIMER_0_IRQ_PRIO    1

// Timer 1 configuration
#define TIMER_1_DEV         TIMx                                                        // TODO !!!!!!!
#define TIMER_1_CHANNELS    
#define TIMER_1_PRESCALER   (47U)
#define TIMER_1_MAX_VALUE   (0xffff)
#define TIMER_1_CLKEN()     
#define TIMER_1_ISR         
#define TIMER_1_IRQCHAN     
#define TIMER_1_IRQ_PRIO    



/**
 * @brief ADC configuration
 */
#define ADC_NUMOF           (0U)
#define ADC_0_EN            0
#define ADC_1_EN            0

// ADC 0 configuration
#define ADC_0_DEV           ADC1                                                        // TODO !!!!!!!
#define ADC_0_SAMPLE_TIMER  
// ADC 0 channel 0 pin config
#define ADC_0_C0_PORT       
#define ADC_0_C0_PIN        
#define ADC_0_C0_CLKEN()    
#define ADC_0_C0_AFCFG()    
// ADC 0 channel 1 pin config
#define ADC_0_C1_PORT       
#define ADC_0_C1_PIN        
#define ADC_0_C1_CLKEN()    
#define ADC_0_C1_AFCFG()    
// ADC 0 channel 2 pin config
#define ADC_0_C2_PORT       
#define ADC_0_C2_PIN        
#define ADC_0_C2_CLKEN()    
#define ADC_0_C2_AFCFG()    
// ADC 0 channel 3 pin config
#define ADC_0_C3_PORT       
#define ADC_0_C3_PIN        
#define ADC_0_C3_CLKEN()    
#define ADC_0_C3_AFCFG()    

// ADC 0 configuration
#define ADC_1_DEV           ADC2                                                        // TODO !!!!!!!
#define ADC_1_SAMPLE_TIMER  
// ADC 0 channel 0 pin config
#define ADC_1_C0_PORT       
#define ADC_1_C0_PIN        
#define ADC_1_C0_CLKEN()    
#define ADC_1_C0_AFCFG()    
// ADC 0 channel 1 pin config
#define ADC_1_C1_PORT       
#define ADC_1_C1_PIN        
#define ADC_1_C1_CLKEN()    
#define ADC_1_C1_AFCFG()    
// ADC 0 channel 2 pin config
#define ADC_1_C2_PORT       
#define ADC_1_C2_PIN        
#define ADC_1_C2_CLKEN()    
#define ADC_1_C2_AFCFG()    
// ADC 0 channel 3 pin config
#define ADC_1_C3_PORT       
#define ADC_1_C3_PIN        
#define ADC_1_C3_CLKEN()    
#define ADC_1_C3_AFCFG()    


/**
 * @brief PWM configuration
 */
#define PWM_NUMOF           (0U)                                                        // TODO !!!!!!!
#define PWM_0_EN            0
#define PWM_1_EN            0

/* PWM 0 device configuration */
#define PWM_0_DEV           TIM1
#define PWM_0_CHANNELS      4
/* PWM 0 pin configuration */
#define PWM_0_PORT          
#define PWM_0_PINS          
#define PWM_0_PORT_CLKEN()  
#define PWM_0_CH1_AFCFG()   
#define PWM_0_CH2_AFCFG()   
#define PWM_0_CH3_AFCFG()   
#define PWM_0_CH4_AFCFG()   

/* PWM 1 device configuration */
#define PWM_1_DEV           TIM3
#define PWM_1_CHANNELS      4
/* PWM 1 pin configuration */
#define PWM_1_PORT          
#define PWM_1_PINS          
#define PWM_1_PORT_CLKEN()  
#define PWM_1_CH1_AFCFG()   
#define PWM_1_CH2_AFCFG()   
#define PWM_1_CH3_AFCFG()   
#define PWM_1_CH4_AFCFG()   


/**
 * @brief UART configuration
 */
#define UART_NUMOF          (2U)
#define UART_0_EN           1
#define UART_1_EN           1
#define UART_IRQ_PRIO       1

// UART 0 device configuration
#define UART_0_DEV          USART1
#define UART_0_CLKEN()      RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE)
#define UART_0_IRQ          USART1_IRQn
#define UART_0_ISR          isr_usart1
// UART 0 pin configuration
#define UART_0_PORT         GPIOB
#define UART_0_PINS         (GPIO_Pin_6 | GPIO_Pin_7)
#define UART_0_PORT_CLKEN() RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE)
#define UART_0_RX_AFCFG()   (GPIO_PinAFConfig(UART_0_PORT, GPIO_PinSource6, GPIO_AF_0))
#define UART_0_TX_AFCFG()   (GPIO_PinAFConfig(UART_0_PORT, GPIO_PinSource7, GPIO_AF_0))

// UART 1 device configuration
#define UART_1_DEV          USART2
#define UART_1_CLKEN()      RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART2, ENABLE)
#define UART_1_IRQ          USART2_IRQn
#define UART_1_ISR          isr_usart2
// UART 1 pin configuration
#define UART_1_PORT         GPIOA
#define UART_1_PINS         (GPIO_Pin_2 | GPIO_Pin_3)
#define UART_1_PORT_CLKEN() RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE)
#define UART_1_RX_AFCFG()   GPIO_PinAFConfig(UART_1_PORT, GPIO_PinSource2, GPIO_AF_1)
#define UART_1_TX_AFCFG()   GPIO_PinAFConfig(UART_1_PORT, GPIO_PinSource3, GPIO_AF_1)



/**
 * @brief SPI configuration
 */
#define SPI_NUMOF           (0U)                                                        // TODO !!!!!!!
#define SPI_0_EN            0
#define SPI_1_EN            0

// SPI 0 device config
#define SPI_0_DEV           SPI1
#define SPI_0_CLKEN()       
#define SPI_0_IRQ           SPI1_IRQn
#define SPI_0_IRQ_HANDLER   
#define SPI_0_IRQ_PRIO      1
// SPI 1 pin configuration
#define SPI_0_PORT          
#define SPI_0_PINS          ()
#define SPI_1_PORT_CLKEN()  
#define SPI_1_SCK_AFCFG()   
#define SPI_1_MISO_AFCFG()  
#define SPI_1_MOSI_AFCFG()  

// SPI 1 device config
#define SPI_1_DEV           SPI2
#define SPI_1_CLKEN()       
#define SPI_1_IRQ           SPI2_IRQn
#define SPI_1_IRQ_HANDLER   
#define SPI_1_IRQ_PRIO      1
// SPI 1 pin configuration
#define SPI_1_PORT          
#define SPI_1_PINS          ()
#define SPI_1_PORT_CLKEN()  
#define SPI_1_SCK_AFCFG()   
#define SPI_1_MISO_AFCFG()  
#define SPI_1_MOSI_AFCFG()  


/**
 * @brief I2C configuration
 */
#define I2C_NUMOF           (0U)                                                        // TODO !!!!!!!
#define I2C_0_EN            0
#define I2C_0_EN            0

/* SPI 0 device configuration */
#define I2C_0_DEV           I2C1
#define I2C_0_CLKEN()       
#define I2C_0_ISR           isr_i2c1
#define I2C_0_IRQ           I2C1_IRQn
#define I2C_0_IRQ_PRIO      1
/* SPI 0 pin configuration */
#define I2C_0_PORT          GPIOB
#define I2C_0_PINS          (GPIO_Pin_6 | GPIO_Pin_7)
#define I2C_0_PORT_CLKEN()  
#define I2C_0_SCL_AFCFG()   
#define I2C_0_SDA_AFCFG()   

/* SPI 1 device configuration */
#define I2C_1_DEV           I2C2
#define I2C_1_CLKEN()       
#define I2C_1_ISR           isr_i2c2
#define I2C_1_IRQ           I2C2_IRQn
#define I2C_1_IRQ_PRIO      1
/* SPI 1 pin configuration */
#define I2C_1_PORT          GPIOF
#define I2C_1_PINS          (GPIO_Pin_0 | GPIO_Pin_1)
#define I2C_1_PORT_CLKEN()  
#define I2C_1_SCL_AFCFG()   
#define I2C_1_SDA_AFCFG()   


/**
 * @brief GPIO configuration
 */
#define GPIO_NUMOF          12
#define GPIO_0_EN           1
#define GPIO_1_EN           1
#define GPIO_2_EN           1
#define GPIO_3_EN           1
#define GPIO_4_EN           1
#define GPIO_5_EN           1
#define GPIO_6_EN           1
#define GPIO_7_EN           1
#define GPIO_8_EN           1
#define GPIO_9_EN           1
#define GPIO_10_EN          1
#define GPIO_11_EN          1
#define GPIO_IRQ_PRIO       1

// IRQ config
#define GPIO_IRQ_0          GPIO_0
#define GPIO_IRQ_1          GPIO_1
#define GPIO_IRQ_2          // not configured
#define GPIO_IRQ_3          // not configured
#define GPIO_IRQ_4          GPIO_2
#define GPIO_IRQ_5          GPIO_3
#define GPIO_IRQ_6          GPIO_4
#define GPIO_IRQ_7          GPIO_5
#define GPIO_IRQ_8          // not configured
#define GPIO_IRQ_9          // not configured
#define GPIO_IRQ_10         GPIO_6
#define GPIO_IRQ_11         GPIO_7
#define GPIO_IRQ_12         GPIO_8
#define GPIO_IRQ_13         GPIO_9
#define GPIO_IRQ_14         GPIO_10
#define GPIO_IRQ_15         GPIO_11

// GPIO channel 0 config
#define GPIO_0_PORT         GPIOA                   // Used for user button 1
#define GPIO_0_PIN          (1 << 0)
#define GPIO_0_CLKEN()      RCC->AHBENR |= RCC_AHBENR_GPIOAEN
#define GPIO_0_LINE         EXTI_Line0
#define GPIO_0_IRQ          default_handler // TODO
#define GPIO_0_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0)
// GPIO channel 1 config
#define GPIO_1_PORT         GPIOA
#define GPIO_1_PIN          (1 << 1)
#define GPIO_1_CLKEN()      RCC->AHBENR |= RCC_AHBENR_GPIOAEN
#define GPIO_1_LINE         EXTI_Line1
#define GPIO_1_IRQ          default_handler // TODO
#define GPIO_1_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource1)
// GPIO channel 2 config
#define GPIO_2_PORT         GPIOF
#define GPIO_2_PIN          (1 << 4)
#define GPIO_2_CLKEN()      RCC->AHBENR |= RCC_AHBENR_GPIOFEN
#define GPIO_2_LINE         EXTI_Line4
#define GPIO_2_IRQ          default_handler // TODO
#define GPIO_2_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOF, EXTI_PinSource4)
// GPIO channel 3 config
#define GPIO_3_PORT         GPIOF
#define GPIO_3_PIN          (1 << 5)
#define GPIO_3_CLKEN()      RCC->AHBENR |= RCC_AHBENR_GPIOFEN
#define GPIO_3_LINE         EXTI_Line5
#define GPIO_3_IRQ          default_handler // TODO
#define GPIO_3_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOF, EXTI_PinSource5)
// GPIO channel 4 config
#define GPIO_4_PORT         GPIOF
#define GPIO_4_PIN          (1 << 6)
#define GPIO_4_CLKEN()      RCC->AHBENR |= RCC_AHBENR_GPIOFEN
#define GPIO_4_LINE         EXTI_Line6
#define GPIO_4_IRQ          default_handler // TODO
#define GPIO_4_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOF, EXTI_PinSource6)
// GPIO channel 5 config
#define GPIO_5_PORT         GPIOF
#define GPIO_5_PIN          (1 << 7)
#define GPIO_5_CLKEN()      RCC->AHBENR |= RCC_AHBENR_GPIOFEN
#define GPIO_5_LINE         EXTI_Line7
#define GPIO_5_IRQ          default_handler // TODO
#define GPIO_5_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOF, EXTI_PinSource7)
// GPIO channel 6 config
#define GPIO_6_PORT         GPIOC
#define GPIO_6_PIN          (1 << 10)
#define GPIO_6_CLKEN()      RCC->AHBENR |= RCC_AHBENR_GPIOCEN
#define GPIO_6_LINE         EXTI_Line10
#define GPIO_6_IRQ          default_handler // TODO
#define GPIO_6_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource10)
// GPIO channel 7 config
#define GPIO_7_PORT         GPIOC
#define GPIO_7_PIN          (1 << 11)
#define GPIO_7_CLKEN()      RCC->AHBENR |= RCC_AHBENR_GPIOCEN
#define GPIO_7_LINE         EXTI_Line11
#define GPIO_7_IRQ          default_handler // TODO
#define GPIO_7_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource11)
// GPIO channel 8 config
#define GPIO_8_PORT         GPIOC
#define GPIO_8_PIN          (1 << 12)
#define GPIO_8_CLKEN()      RCC->AHBENR |= RCC_AHBENR_GPIOCEN
#define GPIO_8_LINE         EXTI_Line12
#define GPIO_8_IRQ          default_handler // TODO
#define GPIO_8_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource12)
// GPIO channel 9 config
#define GPIO_9_PORT         GPIOC
#define GPIO_9_PIN          (1 << 13)
#define GPIO_9_CLKEN()      RCC->AHBENR |= RCC_AHBENR_GPIOCEN
#define GPIO_9_LINE         EXTI_Line13
#define GPIO_9_IRQ          default_handler // TODO
#define GPIO_9_EXTI_MAP()   SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource13)
// GPIO channel 10 config
#define GPIO_10_PORT        GPIOC
#define GPIO_10_PIN         (1 << 14)
#define GPIO_10_CLKEN()     RCC->AHBENR |= RCC_AHBENR_GPIOCEN
#define GPIO_10_LINE        EXTI_Line14
#define GPIO_10_IRQ         default_handler // TODO
#define GPIO_10_EXTI_MAP()  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource14)
// GPIO channel 11 config
#define GPIO_11_PORT        GPIOC
#define GPIO_11_PIN         (1 << 15)GPIO_Pin_15
#define GPIO_11_CLKEN()     RCC->AHBENR |= RCC_AHBENR_GPIOCEN
#define GPIO_11_LINE        EXTI_Line15
#define GPIO_11_IRQ         default_handler // TODO
#define GPIO_11_EXTI_MAP()  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource15)


#endif /* __PERIPH_CONF_H */
