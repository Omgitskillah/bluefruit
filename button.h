#ifndef _BUTTON_
#define _BUTTON_

typedef enum button_id
{
    BUTTON_A,
    BUTTON_B
} button_id_e;

void button_init( void );
void button_subscribe( button_id_e _button_id, void (* _long_press)(void),
                                               void (* _medium_press)(void),
                                               void (* _short_press)(void) );

#endif