#line 1 "D:\\git\\bluefruit\\ble.cpp"
#include <Arduino.h>

#include <bluefruit.h>
#include <Adafruit_LittleFS.h>
#include <InternalFileSystem.h>

#include "debug_serial.h"
#include "ble.h"

/* BLE defines */
#define BLE_TX_POWER         4
#define BLE_INTERVAL_LOW     32
#define BLE_INTERVAL_HIGH    244
#define BLE_FASTMODE_TIMEOUT 30 //seconds
#define BLE_ADVERTISE_TIMOUT 0 // forever
// #define BLE_ADVERTISE_TIMOUT 30 // 30 seconds

#define BLE_NAME     "EINK OVER BLE"

BLEDfu  bledfu;  // OTA DFU service
BLEDis  bledis;  // device information
BLEUart bleuart; // uart over ble
BLEBas  blebas;  // battery

/* local function prototypes */
void connect_callback( uint16_t conn_handle );
void disconnect_callback( uint16_t conn_handle, uint8_t reason );

void ble_central_init( void )
{
    Bluefruit.autoConnLed( true );
    Bluefruit.configPrphBandwidth( BANDWIDTH_MAX );

    Bluefruit.begin();
    Bluefruit.setTxPower( BLE_TX_POWER );
    Bluefruit.Periph.setConnectCallback( connect_callback );
    Bluefruit.Periph.setDisconnectCallback( disconnect_callback );
    
    bledfu.begin();

    bledis.setManufacturer("Adafruit Industries");
    bledis.setModel("Bluefruit Feather52");
    bledis.begin();

    bleuart.begin();

    blebas.begin();
    blebas.write(100);

    ble_advertise();
}

void connect_callback( uint16_t conn_handle )
{
    /** TODO: Set connected flag */
    
    BLEConnection* connection = Bluefruit.Connection(conn_handle);
    char central_name[32] = { 0 };

    connection->getPeerName(central_name, sizeof(central_name));

    int string_length = sprintf( debug_serial_scratchpad, "Connected to: %s", central_name );
    debug_serial_print( debug_serial_scratchpad, string_length );
}

void disconnect_callback( uint16_t conn_handle, uint8_t reason )
{
    (void) conn_handle;
    /** TODO: Throw error here */
    
    int string_length = sprintf( debug_serial_scratchpad, "Disconnected, reason = %02x", reason );
    debug_serial_print( debug_serial_scratchpad, string_length );
}


/** ------------------------------------------------------------------------------------------ */
/* Public functions                                                                            */
/** ------------------------------------------------------------------------------------------ */

void ble_advertise( void )
{
    Bluefruit.Advertising.addFlags( BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE );
    Bluefruit.Advertising.addTxPower();

    Bluefruit.Advertising.addService( bleuart );

    Bluefruit.ScanResponse.addName();
  
    Bluefruit.Advertising.restartOnDisconnect( true );
    Bluefruit.Advertising.setInterval( BLE_INTERVAL_LOW, BLE_INTERVAL_HIGH );
    Bluefruit.Advertising.setFastTimeout( BLE_FASTMODE_TIMEOUT );
    Bluefruit.Advertising.start( BLE_ADVERTISE_TIMOUT );
}

void ble_print_bleuart( void )
{
    while ( bleuart.available() )
    {
        uint8_t ch;
        ch = (uint8_t) bleuart.read();

        debug_serial_print( (char *)&ch, sizeof(ch) );
    }
}