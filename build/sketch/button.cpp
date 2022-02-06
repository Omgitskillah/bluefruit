#line 1 "D:\\git\\bluefruit\\button.cpp"
#include <Arduino.h>
#include <bluefruit.h>
#include "debug_serial.h"
#include "led13.h"
#include "buzzer.h"

#include "button.h"

#define BUTTON_LEFT   PIN_BUTTON1
#define BUTTON_RIGHT  PIN_BUTTON2

#define DEBOUNCE_TIME 50   //ms
#define SHORT_PRESS   1000 //ms
#define MEDIUM_PRESS  3000 //ms
#define LONG_PRESS    5000 //ms

#define BEEP_LENGTH   100

typedef struct button_instance
{
    button_id_e id;
    uint32_t pin;
    uint32_t timer;
    uint8_t previous_state;
    uint8_t current_state;
    void (* callback)( void );
    void (* short_press_handler)( void );
    void (* medium_press_handler)( void );
    void (* long_press_handler)( void );
} button_instance_e;

void button_right_callback(void);
void button_left_callback(void);
void process_button_press( button_instance_e * _button_instance );
void action_button_handler( uint32_t press_duration, button_instance_e * _button_instance );

button_instance_e button_right = { .id = BUTTON_B,
                                   .pin = PIN_BUTTON2,
                                   .timer = 0,
                                   .previous_state = LOW,
                                   .current_state = LOW,
                                   .callback = button_right_callback,
                                   .short_press_handler = NULL,
                                   .medium_press_handler = NULL,
                                   .long_press_handler = NULL };

button_instance_e button_left = { .id = BUTTON_A,
                                   .pin = PIN_BUTTON1,
                                   .timer = 0,
                                   .previous_state = LOW,
                                   .current_state = LOW,
                                   .callback = button_left_callback,
                                   .short_press_handler = NULL,
                                   .medium_press_handler = NULL,
                                   .long_press_handler = NULL };

button_instance_e * all_buttons[] = { &button_left, &button_right };

#define BUTTON_COUNT sizeof(all_buttons) / sizeof(all_buttons[0])

void button_init( void )
{
    // init all button pins
    for( uint8_t i = 0; i < BUTTON_COUNT; i++ )
    {
        pinMode( all_buttons[i]->pin, INPUT_PULLDOWN );
        attachInterrupt( all_buttons[i]->pin, all_buttons[i]->callback, ISR_DEFERRED | CHANGE );
    }
}

void button_right_callback(void)
{
    process_button_press( &button_right );
}

void button_left_callback(void)
{
    process_button_press( &button_left );
}

void process_button_press( button_instance_e * _button_instance )
{
    uint8_t pin_state = digitalRead( _button_instance->pin );
    if ( HIGH == pin_state )
    {
        _button_instance->timer = millis();
        buzzer_play_beep( BEEP_LENGTH );
    }
    else
    {
        uint32_t current_millis = millis();
        uint32_t press_duration = current_millis - _button_instance->timer;
        
        action_button_handler( press_duration, _button_instance );
    }
}

void action_button_handler( uint32_t press_duration, button_instance_e * _button_instance )
{
    // if ( press_duration >= DEBOUNCE_TIME )
    // {
    //     buzzer_play_beep( BEEP_LENGTH );
    // }

    if( press_duration >= LONG_PRESS )
    {
        if( _button_instance->long_press_handler != NULL )
        {
            _button_instance->long_press_handler();
        }
    }
    else if( press_duration >= MEDIUM_PRESS )
    {
        if( _button_instance->medium_press_handler != NULL )
        {
            _button_instance->medium_press_handler();
        }
    }
    else if( press_duration >= DEBOUNCE_TIME )
    {
        if( _button_instance->short_press_handler != NULL )
        {
            _button_instance->short_press_handler();
        }
    }
}

void button_subscribe( button_id_e _button_id, void (* _long_press)(void),
                                               void (* _medium_press)(void),
                                               void (* _short_press)(void) )
{
    for( uint8_t i = 0; i < BUTTON_COUNT; i++ )
    {
        if( all_buttons[i]->id == _button_id )
        {
            all_buttons[i]->long_press_handler = _long_press;
            all_buttons[i]->medium_press_handler = _medium_press;
            all_buttons[i]->short_press_handler = _short_press;
        }
    }
}
