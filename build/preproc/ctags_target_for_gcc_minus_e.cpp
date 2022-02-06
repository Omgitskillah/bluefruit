# 1 "D:\\git\\bluefruit\\bluefruit.ino"
# 2 "D:\\git\\bluefruit\\bluefruit.ino" 2
# 3 "D:\\git\\bluefruit\\bluefruit.ino" 2
# 4 "D:\\git\\bluefruit\\bluefruit.ino" 2
# 5 "D:\\git\\bluefruit\\bluefruit.ino" 2
# 6 "D:\\git\\bluefruit\\bluefruit.ino" 2
# 7 "D:\\git\\bluefruit\\bluefruit.ino" 2

void toggle_pixel_1( void );
void toggle_pixel_3( void );

void setup( void )
{
    debug_serial_init();
    neopixel_init();
    button_init();

    button_subscribe( BUTTON_A, 
# 17 "D:\\git\\bluefruit\\bluefruit.ino" 3 4
                               __null
# 17 "D:\\git\\bluefruit\\bluefruit.ino"
                                   , 
# 17 "D:\\git\\bluefruit\\bluefruit.ino" 3 4
                                     __null
# 17 "D:\\git\\bluefruit\\bluefruit.ino"
                                         , toggle_pixel_1 );
    button_subscribe( BUTTON_B, 
# 18 "D:\\git\\bluefruit\\bluefruit.ino" 3 4
                               __null
# 18 "D:\\git\\bluefruit\\bluefruit.ino"
                                   , toggle_pixel_3, 
# 18 "D:\\git\\bluefruit\\bluefruit.ino" 3 4
                                                     __null 
# 18 "D:\\git\\bluefruit\\bluefruit.ino"
                                                          );
}

void loop( void )
{

}

void toggle_pixel_1( void )
{
    static uint8_t pixel_1_state = 0;

    switch (pixel_1_state)
    {
        case 0:
            neopixel_turn_on( 1, 255, 0, 0 );
            break;
        case 1:
            neopixel_turn_on( 1, 0, 255, 0 );
            break;
        case 2:
            neopixel_turn_on( 1, 0, 0, 255 );
            break;
        case 3:
            neopixel_turn_on( 1, 0, 0, 0 );
            break;
        default:
            break;
    }

    pixel_1_state++;
    if( pixel_1_state > 3 )
    {
        pixel_1_state = 0;
    }
}

void toggle_pixel_3( void )
{
    static uint8_t pixel_2_state = 0;

    switch (pixel_2_state)
    {
        case 0:
            neopixel_turn_on( 3, 255, 0, 0 );
            break;
        case 1:
            neopixel_turn_on( 3, 0, 255, 0 );
            break;
        case 2:
            neopixel_turn_on( 3, 0, 0, 255 );
            break;
        case 3:
            neopixel_turn_on( 3, 0, 0, 0 );
            break;
        default:
            break;
    }

    pixel_2_state++;
    if( pixel_2_state > 3 )
    {
        pixel_2_state = 0;
    }
}
