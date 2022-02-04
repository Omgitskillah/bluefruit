#line 1 "D:\\git\\bluefruit\\debug_serial.h"
#ifndef _DEBUG_SERIAL_
#define _DEBUG_SERIAL_

extern char debug_serial_scratchpad[512]; 

void debug_serial_init( void );
void debug_serial_print( char * string, int len );

#endif