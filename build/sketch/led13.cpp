#line 1 "D:\\git\\bluefruit\\led13.cpp"
#include <Arduino.h>
#include "led13.h"

void led13_init( void )
{
    pinMode(LED_BUILTIN, OUTPUT);
}

void led13_flash_blocking( uint32_t duration )
{
    digitalToggle( LED_BUILTIN );
    delay( duration );
}