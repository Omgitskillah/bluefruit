#line 1 "D:\\git\\bluefruit\\bluefruit.ino"
#include <Arduino.h>
#include <bluefruit.h>
#include "debug_serial.h"
#include "neopixel.h"
#include "led13.h"
#include "button.h"

void toggle_pixel_1( void );
void toggle_pixel_3( void );

#line 11 "D:\\git\\bluefruit\\bluefruit.ino"
void setup( void );
#line 21 "D:\\git\\bluefruit\\bluefruit.ino"
void loop( void );
#line 11 "D:\\git\\bluefruit\\bluefruit.ino"
void setup( void )
{
    debug_serial_init();
    neopixel_init();
    button_init();

    button_subscribe( BUTTON_A, NULL, NULL, toggle_pixel_1 );
    button_subscribe( BUTTON_B, NULL, toggle_pixel_3, NULL );
}

void loop( void )
{

}

void toggle_pixel_1( void )
{
    static uint8_t pixel_1_state = 0;

    switch (pixel_1_state)
    {
        case 0:
            neopixel_turn_on( 1, 255, 0, 0 );
            break;
        case 1:
            neopixel_turn_on( 1, 0, 255, 0 );
            break;
        case 2:
            neopixel_turn_on( 1, 0, 0, 255 );
            break;
        case 3:
            neopixel_turn_on( 1, 0, 0, 0 );
            break;
        default:
            break;
    }

    pixel_1_state++;
    if( pixel_1_state > 3 )
    {
        pixel_1_state = 0;
    }
}

void toggle_pixel_3( void )
{
    static uint8_t pixel_2_state = 0;

    switch (pixel_2_state)
    {
        case 0:
            neopixel_turn_on( 3, 255, 0, 0 );
            break;
        case 1:
            neopixel_turn_on( 3, 0, 255, 0 );
            break;
        case 2:
            neopixel_turn_on( 3, 0, 0, 255 );
            break;
        case 3:
            neopixel_turn_on( 3, 0, 0, 0 );
            break;
        default:
            break;
    }

    pixel_2_state++;
    if( pixel_2_state > 3 )
    {
        pixel_2_state = 0;
    }
}
