#line 1 "D:\\git\\bluefruit\\button.h"
#ifndef _BUTTON_
#define _BUTTON_

typedef enum button_id
{
    BUTTON_A,
    BUTTON_B
} button_id_e;

typedef enum button_press
{
    BUTTON_SHORT_PRESS,  // <1 second
    BUTTON_MEDIUM_PRESS, // 2 to 3 seconds
    BUTTON_LONG_PRESS    // >4 seconds
} button_press_e;

void button_init( void );
void button_subscribe( button_id_e _button_id, void (* _long_press)(void),
                                               void (* _medium_press)(void),
                                               void (* _short_press)(void) );

#endif