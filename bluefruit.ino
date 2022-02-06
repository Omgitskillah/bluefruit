#include <Arduino.h>
#include <bluefruit.h>
#include "debug_serial.h"
#include "neopixel.h"
#include "led13.h"
#include "button.h"
#include "buzzer.h"

void setup( void )
{
    debug_serial_init();
    button_init();
    buzzer_init();
}

void loop( void )
{

}
