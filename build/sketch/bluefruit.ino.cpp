#line 1 "D:\\git\\bluefruit\\bluefruit.ino"
#include <Arduino.h>
#include <bluefruit.h>
#include "debug_serial.h"

#include "led13.h"
#include "button.h"


uint8_t all_pins[] =
{
    PIN_A0
    ,PIN_A1
    ,PIN_A2
    ,PIN_A3
    ,PIN_A4
    ,PIN_A5
    ,PIN_A6
    ,PIN_A7
    ,PIN_A8
    ,PIN_A9
    ,PIN_LED1    
    ,PIN_NEOPIXEL
    ,NEOPIXEL_NUM
    ,LED_BUILTIN
    ,LED_RED 
    ,LED_BLUE
    ,PIN_BUTTON1
    ,PIN_BUTTON2
};

#line 31 "D:\\git\\bluefruit\\bluefruit.ino"
void setup( void );
#line 43 "D:\\git\\bluefruit\\bluefruit.ino"
void loop( void );
#line 31 "D:\\git\\bluefruit\\bluefruit.ino"
void setup( void )
{
    debug_serial_init();
    // led13_init();
    // button_init();

    for( uint8_t i = 0; i < sizeof(all_pins); i++ )
    {
        pinMode( all_pins[i], INPUT_PULLUP);
    }
}

void loop( void )
{
    for( uint8_t i = 0; i < sizeof(all_pins); i++ )
    {
        Serial.print( digitalRead( all_pins[i] ) );
    }
     Serial.println();

     delay( 1000 );
}
