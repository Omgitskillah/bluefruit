#line 1 "D:\\git\\bluefruit\\bluefruit.ino"
#include <Arduino.h>
#include "debug_serial.h"
#include "neopixel.h"

void setup()
{
    debug_serial_init();
    neopixel_init();
}

void loop()
{
    neopixel_clear_all();

    for( uint8_t i = 0; i < NEOPIXEL_COUNT; i++ )
    {
        neopixel_turn_on( i, 100, 0, 100);
        delay( 1000 );
    }

}
