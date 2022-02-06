#include <Arduino.h>

#include "buzzer.h"

#define BEEP_FREQUENCY 3000

void buzzer_init( void )
{
    pinMode(PIN_BUZZER, OUTPUT);
    digitalWrite(PIN_BUZZER, LOW);
}

void buzzer_play_beep( uint32_t duration )
{
    tone( PIN_BUZZER, BEEP_FREQUENCY, duration );
}