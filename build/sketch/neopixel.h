#line 1 "D:\\git\\bluefruit\\neopixel.h"
#ifndef _BLUEFRUIT_NEOPIXELS_
#define _BLUEFRUIT_NEOPIXELS_

#define NEOPIXEL_COUNT 10

void neopixel_init( void );
void neopixel_turn_on( uint32_t pixel_id, uint8_t r, uint8_t g, uint8_t b );
void neopixel_clear_all( void );


#endif
