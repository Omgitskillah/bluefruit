# 1 "D:\\git\\bluefruit\\bluefruit.ino"
# 2 "D:\\git\\bluefruit\\bluefruit.ino" 2
# 3 "D:\\git\\bluefruit\\bluefruit.ino" 2
# 4 "D:\\git\\bluefruit\\bluefruit.ino" 2

# 6 "D:\\git\\bluefruit\\bluefruit.ino" 2
# 7 "D:\\git\\bluefruit\\bluefruit.ino" 2


uint8_t all_pins[] =
{
    (14) /* not really analog!*/
    ,(6)
    ,(9)
    ,(10)
    ,(3)
    ,(2)
    ,(0)
    ,(21) /* not really analog!*/
    ,(22)
    ,(23)
    ,(13)
    ,(8)
    ,10
    ,(13)
    ,(13)
    ,(13)
    ,(4) /* Button A (Left)*/
    ,(5) /* Button B (Right)*/
};

void setup( void )
{
    debug_serial_init();
    // led13_init();
    // button_init();

    for( uint8_t i = 0; i < sizeof(all_pins); i++ )
    {
        pinMode( all_pins[i], (0x2));
    }
}

void loop( void )
{
    for( uint8_t i = 0; i < sizeof(all_pins); i++ )
    {
        Serial.print( digitalRead( all_pins[i] ) );
    }
     Serial.println();

     delay( 1000 );
}
