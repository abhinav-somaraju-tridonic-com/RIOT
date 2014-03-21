/*
 * Copyright (C) 2014 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup         stm32f303vc
 * @{
 * 
 * @file            cpu-conf.h
 * @brief           Implementation specific CPU configuration options
 * 
 * @author          Hauke Petersen <hauke.peterse@fu-berlin.de>
 */

#ifndef __CPU_CONF_H
#define __CPU_CONF_H


/**
 * @brief Kernel configuration
 */
#define KERNEL_CONF_STACKSIZE_PRINTF    (2500)

#ifndef KERNEL_CONF_STACKSIZE_DEFAULT
#define KERNEL_CONF_STACKSIZE_DEFAULT   (2500)
#endif

#define KERNEL_CONF_STACKSIZE_IDLE      (512)


/**
 * @brief Hardware timer configuration
 */
#define HWTIMER_MAXTIMERS   4               ///< the CPU implementation supports 4 HW timers
#define HWTIMER_SPEED       1000000         ///< the HW timer runs with 1MHz
#define HWTIMER_MAXTICKS    (0xFFFFFFFF)    ///< 32-bit timer



#endif /* __CPU_CONF_H */
/** @} */
