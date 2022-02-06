#line 1 "D:\\git\\bluefruit\\bluefruit.ino"
#include <Arduino.h>
#include <bluefruit.h>
#include "debug_serial.h"
#include "neopixel.h"
#include "led13.h"
#include "button.h"
#include "buzzer.h"

#line 9 "D:\\git\\bluefruit\\bluefruit.ino"
void setup( void );
#line 16 "D:\\git\\bluefruit\\bluefruit.ino"
void loop( void );
#line 9 "D:\\git\\bluefruit\\bluefruit.ino"
void setup( void )
{
    debug_serial_init();
    button_init();
    buzzer_init();
}

void loop( void )
{

}

