#ifndef LPM_H_
#define LPM_H_

#include "arch/lpm_arch.h"
/**
 * @defgroup    lpm     Power Management
 * @ingroup     kernel
 * @{
 */

/**
 * @file
 * @brief       Power Management Interface
 *
 * @author      Freie Universität Berlin, Computer Systems & Telematics
 * @version     $Revision$
 *
 * This interface needs to be implemented for each platform.
 *
 * @note        $Id$
 */

/**
 * @brief   Initialization of power management (including clock setup)
 *
 * This function is invoked once during boot.
 */
void lpm_init(void);

/**
 * @brief   Switches the MCU to a new power mode
 * @param[in]   target      Target power mode
 */
enum lpm_mode lpm_set(enum lpm_mode target);

void lpm_awake(void);

void lpm_begin_awake(void);
void lpm_end_awake(void);

/**
 * @brief   Returns the current power mode
 * @return  Current power mode
 */
enum lpm_mode lpm_get(void);


/** @} */
#endif /* LPM_H_ */
