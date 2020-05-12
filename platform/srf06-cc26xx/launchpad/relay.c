/*---------------------------------------------------------------------------*/
/**
 * \addtogroup sensortag-cc26xx-relay
 * @{
 *
 * \file
 *  Driver for the Launchpad Relay
 */
/*---------------------------------------------------------------------------*/
#include "contiki-conf.h"
#include "ti-lib.h"
#include "relay.h"

#include <stdint.h>
#include <string.h>
#include <stdio.h>
/*---------------------------------------------------------------------------*/
static uint8_t relay_states[3];

static const uint32_t relay_pins[] = {BOARD_IOID_DIO28, BOARD_IOID_DIO29, BOARD_IOID_DIO30};

/*---------------------------------------------------------------------------*/
void
relay_init()
{
   memset(relay_states, 0, sizeof(relay_on));

   ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_DIO28);
   ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_DIO29);
   ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_DIO30);

   ti_lib_gpio_clear_dio(BOARD_IOID_DIO28);
   ti_lib_gpio_clear_dio(BOARD_IOID_DIO29);
   ti_lib_gpio_clear_dio(BOARD_IOID_DIO30);
}
/*---------------------------------------------------------------------------*/
uint8_t
relay_state(uint8_t id)
{
   return relay_states[id];
}
/*---------------------------------------------------------------------------*/
void
relay_on(uint8_t id)
{
   relay_states[id] = 1;

   ti_lib_gpio_set_dio(relay_pins[id]);
}
/*---------------------------------------------------------------------------*/
void
relay_off(uint8_t id)
{
   relay_states[id] = 0;

   ti_lib_gpio_clear_dio(relay_pins[id]);
}
/*---------------------------------------------------------------------------*/
/** @} */
