#include <Arduino.h>
#include "led13.h"

void led13_init( void )
{
    pinMode( LED_BUILTIN, OUTPUT );
}

void led13_flash_blocking( uint32_t duration )
{
    digitalToggle( LED_BUILTIN );
    delay( duration );
}

void led13_set( led_state_e state )
{
    digitalWrite( LED_BUILTIN, state );
}