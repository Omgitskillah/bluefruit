#ifndef _LED13_
#define _LED13_

typedef enum led_state
{
    LED13_OFF,
    LED13_ON
} led_state_e;

void led13_init( void );
void led13_flash_blocking( uint32_t duration );
void led13_set( led_state_e state );

#endif