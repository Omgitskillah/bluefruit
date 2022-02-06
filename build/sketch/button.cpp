#line 1 "D:\\git\\bluefruit\\button.cpp"
#include <Arduino.h>
#include <bluefruit.h>
#include "debug_serial.h"
#include "led13.h"

#include "button.h"

#define BUTTON_LEFT (34)

void digital_callback(void);
void button_init( void );


void button_init( void )
{
    pinMode( BUTTON_LEFT, INPUT_PULLUP);
    attachInterrupt( BUTTON_LEFT, digital_callback, CHANGE );
}

void digital_callback(void)
{
    uint8_t pin_state = digitalRead( BUTTON_LEFT );
    // int string_length = sprintf( debug_serial_scratchpad, "Pin value: %s", pin_state );
    // debug_serial_print( debug_serial_scratchpad, string_length );

    if( true == pin_state )
    {
        led13_set( LED13_ON );
    }
    else
    {
        led13_set( LED13_OFF );
    }
}
