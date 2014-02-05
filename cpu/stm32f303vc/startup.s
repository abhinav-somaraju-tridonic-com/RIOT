

/* set assembly environment */
.syntax     unified
.thumb


/* refer to externally declared variables */
.extern     _stack_end
.extern     default_handler

/*
 * definition of the interrupt vector
 * 
 * it consists of two parts:
 *  1. arm specific handlers that are valid for all cortex-m based controllers
 *  2. vendor specific external interrupts, which need to be redefined for each cpu
 */
.section    isr_vector, "a",%progbits
.type       stup_vectors, %object
.size       stup_vectors, .-stup_vectors


stup_vectors:
/* global ARM vector, valid for all cortex-m based platforms */
  .word  _stack_end
  .word  reset_handler
  .word  nmi_handler
  .word  hard_fault_handler
  .word  mem_manage_handler
  .word  bus_fault_handler
  .word  usage_fault_handler
  .word  0
  .word  0
  .word  0
  .word  0
  .word  svc_isr
  .word  debug_mon_handler
  .word  0
  .word  pendsv_isr
  .word  systick_isr
/* STM32F303VC specific interrupt vector */
  .word     WWDG_isr                   /* Window WatchDog              */
  .word     PVD_isr                    /* PVD through EXTI Line detection */
  .word     TAMP_STAMP_isr             /* Tamper and TimeStamps through the EXTI line */
  .word     RTC_WKUP_isr               /* RTC Wakeup through the EXTI line */
  .word     FLASH_isr                  /* FLASH                        */
  .word     RCC_isr                    /* RCC                          */
  .word     EXTI0_isr                  /* EXTI Line0                   */
  .word     EXTI1_isr                  /* EXTI Line1                   */
  .word     EXTI2_isr                  /* EXTI Line2                   */
  .word     EXTI3_isr                  /* EXTI Line3                   */
  .word     EXTI4_isr                  /* EXTI Line4                   */
  .word     DMA1_Stream0_isr           /* DMA1 Stream 0                */
  .word     DMA1_Stream1_isr           /* DMA1 Stream 1                */
  .word     DMA1_Stream2_isr           /* DMA1 Stream 2                */
  .word     DMA1_Stream3_isr           /* DMA1 Stream 3                */
  .word     DMA1_Stream4_isr           /* DMA1 Stream 4                */
  .word     DMA1_Stream5_isr           /* DMA1 Stream 5                */
  .word     DMA1_Stream6_isr           /* DMA1 Stream 6                */
  .word     ADC_isr                    /* ADC1, ADC2 and ADC3s         */
  .word     CAN1_TX_isr                /* CAN1 TX                      */
  .word     CAN1_RX0_isr               /* CAN1 RX0                     */
  .word     CAN1_RX1_isr               /* CAN1 RX1                     */
  .word     CAN1_SCE_isr               /* CAN1 SCE                     */
  .word     EXTI9_5_isr                /* External Line[9:5]s          */
  .word     TIM1_BRK_TIM9_isr          /* TIM1 Break and TIM9          */
  .word     TIM1_UP_TIM10_isr          /* TIM1 Update and TIM10        */
  .word     TIM1_TRG_COM_TIM11_isr     /* TIM1 Trigger and Commutation and TIM11 */
  .word     TIM1_CC_isr                /* TIM1 Capture Compare         */
  .word     TIM2_isr                   /* TIM2                         */
  .word     TIM3_isr                   /* TIM3                         */
  .word     TIM4_isr                   /* TIM4                         */
  .word     I2C1_EV_isr                /* I2C1 Event                   */
  .word     I2C1_ER_isr                /* I2C1 Error                   */
  .word     I2C2_EV_isr                /* I2C2 Event                   */
  .word     I2C2_ER_isr                /* I2C2 Error                   */
  .word     SPI1_isr                   /* SPI1                         */
  .word     SPI2_isr                   /* SPI2                         */
  .word     USART1_isr                 /* USART1                       */
  .word     USART2_isr                 /* USART2                       */
  .word     USART3_isr                 /* USART3                       */
  .word     EXTI15_10_isr              /* External Line[15:10]s        */
  .word     RTC_Alarm_isr              /* RTC Alarm (A and B) through EXTI Line */
  .word     OTG_FS_WKUP_isr            /* USB OTG FS Wakeup through EXTI line */
  .word     TIM8_BRK_TIM12_isr         /* TIM8 Break and TIM12         */
  .word     TIM8_UP_TIM13_isr          /* TIM8 Update and TIM13        */
  .word     TIM8_TRG_COM_TIM14_isr     /* TIM8 Trigger and Commutation and TIM14 */
  .word     TIM8_CC_isr                /* TIM8 Capture Compare         */
  .word     DMA1_Stream7_isr           /* DMA1 Stream7                 */
  .word     FSMC_isr                   /* FSMC                         */
  .word     SDIO_isr                   /* SDIO                         */
  .word     TIM5_isr                   /* TIM5                         */
  .word     SPI3_isr                   /* SPI3                         */
  .word     UART4_isr                  /* UART4                        */
  .word     UART5_isr                  /* UART5                        */
  .word     TIM6_DAC_isr               /* TIM6 and DAC1&2 underrun errors */
  .word     TIM7_isr                   /* TIM7                         */
  .word     DMA2_Stream0_isr           /* DMA2 Stream 0                */
  .word     DMA2_Stream1_isr           /* DMA2 Stream 1                */
  .word     DMA2_Stream2_isr           /* DMA2 Stream 2                */
  .word     DMA2_Stream3_isr           /* DMA2 Stream 3                */
  .word     DMA2_Stream4_isr           /* DMA2 Stream 4                */
  .word     ETH_isr                    /* Ethernet                     */
  .word     ETH_WKUP_isr               /* Ethernet Wakeup through EXTI line */
  .word     CAN2_TX_isr                /* CAN2 TX                      */
  .word     CAN2_RX0_isr               /* CAN2 RX0                     */
  .word     CAN2_RX1_isr               /* CAN2 RX1                     */
  .word     CAN2_SCE_isr               /* CAN2 SCE                     */
  .word     OTG_FS_isr                 /* USB OTG FS                   */
  .word     DMA2_Stream5_isr           /* DMA2 Stream 5                */
  .word     DMA2_Stream6_isr           /* DMA2 Stream 6                */
  .word     DMA2_Stream7_isr           /* DMA2 Stream 7                */
  .word     USART6_isr                 /* USART6                       */
  .word     I2C3_EV_isr                /* I2C3 event                   */
  .word     I2C3_ER_isr                /* I2C3 error                   */
  .word     OTG_HS_EP1_OUT_isr         /* USB OTG HS End Point 1 Out   */
  .word     OTG_HS_EP1_IN_isr          /* USB OTG HS End Point 1 In    */
  .word     OTG_HS_WKUP_isr            /* USB OTG HS Wakeup through EXTI */
  .word     OTG_HS_isr                 /* USB OTG HS                   */
  .word     DCMI_isr                   /* DCMI                         */
  .word     CRYP_isr                   /* CRYP crypto                  */
  .word     HASH_RNG_isr               /* Hash and Rng                 */
  .word     FPU_isr                    /* FPU                          */


/*
 * define interrupt handlers as week and default them with the default handler
 */

/* fault handlers */
.weak       nmi_handler
.thumb_set  nmi_handler,default_handler

.weak       mem_manage_handler
.thumb_set  mem_manage_handler,default_handler

.weak       debug_mon_handler
.thumb_set  debug_mon_handler,default_handler

.weak       hard_fault_handler
.thumb_set  hard_fault_handler,default_handler

.weak       bus_fault_handler
.thumb_set  bus_fault_handler,default_handler

.weak       usage_fault_handler
.thumb_set  usage_fault_handler,default_handler

/* system interrupt handlers */
.weak      svc_isr
.thumb_set svc_isr,default_handler

.weak      pendsv_isr
.thumb_set pendsv_isr,default_handler

.weak      systick_isr
.thumb_set systick_isr,default_handler


/* external interrupt handlers */
.weak      WWDG_isr
.thumb_set WWDG_isr,default_handler

.weak      PVD_isr
.thumb_set PVD_isr,default_handler

.weak      TAMP_STAMP_isr
.thumb_set TAMP_STAMP_isr,default_handler

.weak      RTC_WKUP_isr
.thumb_set RTC_WKUP_isr,default_handler

.weak      FLASH_isr
.thumb_set FLASH_isr,default_handler

.weak      RCC_isr
.thumb_set RCC_isr,default_handler

.weak      EXTI0_isr
.thumb_set EXTI0_isr,default_handler

.weak      EXTI1_isr
.thumb_set EXTI1_isr,default_handler

.weak      EXTI2_isr
.thumb_set EXTI2_isr,default_handler

.weak      EXTI3_isr
.thumb_set EXTI3_isr,default_handler

.weak      EXTI4_isr
.thumb_set EXTI4_isr,default_handler

.weak      DMA1_Stream0_isr
.thumb_set DMA1_Stream0_isr,default_handler

.weak      DMA1_Stream1_isr
.thumb_set DMA1_Stream1_isr,default_handler

.weak      DMA1_Stream2_isr
.thumb_set DMA1_Stream2_isr,default_handler

.weak      DMA1_Stream3_isr
.thumb_set DMA1_Stream3_isr,default_handler

.weak      DMA1_Stream4_isr
.thumb_set DMA1_Stream4_isr,default_handler

.weak      DMA1_Stream5_isr
.thumb_set DMA1_Stream5_isr,default_handler

.weak      DMA1_Stream6_isr
.thumb_set DMA1_Stream6_isr,default_handler

.weak      ADC_isr
.thumb_set ADC_isr,default_handler

.weak      CAN1_TX_isr
.thumb_set CAN1_TX_isr,default_handler

.weak      CAN1_RX0_isr
.thumb_set CAN1_RX0_isr,default_handler

.weak      CAN1_RX1_isr
.thumb_set CAN1_RX1_isr,default_handler

.weak      CAN1_SCE_isr
.thumb_set CAN1_SCE_isr,default_handler

.weak      EXTI9_5_isr
.thumb_set EXTI9_5_isr,default_handler

.weak      TIM1_BRK_TIM9_isr
.thumb_set TIM1_BRK_TIM9_isr,default_handler

.weak      TIM1_UP_TIM10_isr
.thumb_set TIM1_UP_TIM10_isr,default_handler

.weak      TIM1_TRG_COM_TIM11_isr
.thumb_set TIM1_TRG_COM_TIM11_isr,default_handler

.weak      TIM1_CC_isr
.thumb_set TIM1_CC_isr,default_handler

.weak      TIM2_isr
.thumb_set TIM2_isr,default_handler

.weak      TIM3_isr
.thumb_set TIM3_isr,default_handler

.weak      TIM4_isr
.thumb_set TIM4_isr,default_handler

.weak      I2C1_EV_isr
.thumb_set I2C1_EV_isr,default_handler

.weak      I2C1_ER_isr
.thumb_set I2C1_ER_isr,default_handler

.weak      I2C2_EV_isr
.thumb_set I2C2_EV_isr,default_handler

.weak      I2C2_ER_isr
.thumb_set I2C2_ER_isr,default_handler

.weak      SPI1_isr
.thumb_set SPI1_isr,default_handler

.weak      SPI2_isr
.thumb_set SPI2_isr,default_handler

.weak      USART1_isr
.thumb_set USART1_isr,default_handler

.weak      USART2_isr
.thumb_set USART2_isr,default_handler

.weak      USART3_isr
.thumb_set USART3_isr,default_handler

.weak      EXTI15_10_isr
.thumb_set EXTI15_10_isr,default_handler

.weak      RTC_Alarm_isr
.thumb_set RTC_Alarm_isr,default_handler

.weak      OTG_FS_WKUP_isr
.thumb_set OTG_FS_WKUP_isr,default_handler

.weak      TIM8_BRK_TIM12_isr
.thumb_set TIM8_BRK_TIM12_isr,default_handler

.weak      TIM8_UP_TIM13_isr
.thumb_set TIM8_UP_TIM13_isr,default_handler

.weak      TIM8_TRG_COM_TIM14_isr
.thumb_set TIM8_TRG_COM_TIM14_isr,default_handler

.weak      TIM8_CC_isr
.thumb_set TIM8_CC_isr,default_handler

.weak      DMA1_Stream7_isr
.thumb_set DMA1_Stream7_isr,default_handler

.weak      FSMC_isr
.thumb_set FSMC_isr,default_handler

.weak      SDIO_isr
.thumb_set SDIO_isr,default_handler

.weak      TIM5_isr
.thumb_set TIM5_isr,default_handler

.weak      SPI3_isr
.thumb_set SPI3_isr,default_handler

.weak      UART4_isr
.thumb_set UART4_isr,default_handler

.weak      UART5_isr
.thumb_set UART5_isr,default_handler

.weak      TIM6_DAC_isr
.thumb_set TIM6_DAC_isr,default_handler

.weak      TIM7_isr
.thumb_set TIM7_isr,default_handler

.weak      DMA2_Stream0_isr
.thumb_set DMA2_Stream0_isr,default_handler

.weak      DMA2_Stream1_isr
.thumb_set DMA2_Stream1_isr,default_handler

.weak      DMA2_Stream2_isr
.thumb_set DMA2_Stream2_isr,default_handler

.weak      DMA2_Stream3_isr
.thumb_set DMA2_Stream3_isr,default_handler

.weak      DMA2_Stream4_isr
.thumb_set DMA2_Stream4_isr,default_handler

.weak      ETH_isr
.thumb_set ETH_isr,default_handler

.weak      ETH_WKUP_isr
.thumb_set ETH_WKUP_isr,default_handler

.weak      CAN2_TX_isr
.thumb_set CAN2_TX_isr,default_handler

.weak      CAN2_RX0_isr
.thumb_set CAN2_RX0_isr,default_handler

.weak      CAN2_RX1_isr
.thumb_set CAN2_RX1_isr,default_handler

.weak      CAN2_SCE_isr
.thumb_set CAN2_SCE_isr,default_handler

.weak      OTG_FS_isr
.thumb_set OTG_FS_isr,default_handler

.weak      DMA2_Stream5_isr
.thumb_set DMA2_Stream5_isr,default_handler

.weak      DMA2_Stream6_isr
.thumb_set DMA2_Stream6_isr,default_handler

.weak      DMA2_Stream7_isr
.thumb_set DMA2_Stream7_isr,default_handler

.weak      USART6_isr
.thumb_set USART6_isr,default_handler

.weak      I2C3_EV_isr
.thumb_set I2C3_EV_isr,default_handler

.weak      I2C3_ER_isr
.thumb_set I2C3_ER_isr,default_handler

.weak      OTG_HS_EP1_OUT_isr
.thumb_set OTG_HS_EP1_OUT_isr,default_handler

.weak      OTG_HS_EP1_IN_isr
.thumb_set OTG_HS_EP1_IN_isr,default_handler

.weak      OTG_HS_WKUP_isr
.thumb_set OTG_HS_WKUP_isr,default_handler

.weak      OTG_HS_isr
.thumb_set OTG_HS_isr,default_handler

.weak      DCMI_isr
.thumb_set DCMI_isr,default_handler

.weak      CRYP_isr
.thumb_set CRYP_isr,default_handler

.weak      HASH_RNG_isr
.thumb_set HASH_RNG_isr,default_handler

.weak      FPU_isr
.thumb_set FPU_isr,default_handler

