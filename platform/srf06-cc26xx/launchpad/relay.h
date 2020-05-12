/*---------------------------------------------------------------------------*/
/**
 * \addtogroup launchpad-cc26xx-peripherals
 * @{
 *
 * \defgroup launchpad-cc26xx-relay Launchpad Relay
 * @{
 *
 * \file
 * Header file for the Launchpad Relay
 */
/*---------------------------------------------------------------------------*/
#ifndef RELAY_H_
#define RELAY_H_
/*---------------------------------------------------------------------------*/
#include <stdint.h>
/*---------------------------------------------------------------------------*/
#define RELAY_ID_PUMP 0

/**
 * \brief Initialise the relay
 */
void relay_init(void);

/**
 * \brief Start the relay
 * \param id Which of the 3 relays
 */
void relay_on(uint8_t id);

/**
 * \brief Stop the relay
 * \param id Which of the 3 relays
 */
void relay_off(uint8_t id);

/**
 * \brief Retrieve the relay state
 * \param id Which of the 3 relays
 * \return 1: on, 0: off
 */
uint8_t relay_state(uint8_t id);
/*---------------------------------------------------------------------------*/
#endif /* RELAY_H_ */
/*---------------------------------------------------------------------------*/
/**
 * @}
 * @}
 */
