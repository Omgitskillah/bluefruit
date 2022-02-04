#include <Arduino.h>
#include <Adafruit_TinyUSB.h> 
#include "debug_serial.h"

char debug_serial_scratchpad[512]; 


void debug_serial_init( void )
{
    Serial.begin( 115200 );
}

void debug_serial_print( char * string, int len )
{
    Serial.write( string, len );
}