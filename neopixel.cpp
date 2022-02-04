#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "neopixel.h"

Adafruit_NeoPixel pixels( NEOPIXEL_COUNT, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800 );

void neopixel_init( void )
{
    pixels.begin();
}

void neopixel_turn_on( uint32_t pixel_id, uint8_t r, uint8_t g, uint8_t b )
{
    pixels.setPixelColor( pixel_id, pixels.Color(r, g, b) );
    pixels.show();
}

void neopixel_clear_all( void )
{
    pixels.clear();
}
