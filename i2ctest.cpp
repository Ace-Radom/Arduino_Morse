// Program comes from https://www.lab-z.com/ai2cscan/ posted on 3 Dec. 2013
// Copied, edited and reformated by Ace-Radom <https://github.com/Ace-Radom>

#include"i2ctest.h"

byte start_address = 1;
byte end_address   = 127;

// Scan the I2C bus between addresses from_addr and to_addr.
// On each address, call the callback function with the address and result.
// If result==0, address was found, otherwise, address wasn't found
// (can use result to potentially get other status on the I2C bus, see twi.c)
// Assumes Wire.begin() has already been called
void scanI2CBus( byte from_addr , byte to_addr , bool dump_all_address_to_callback ,
                 void ( *callback )( byte address , byte result ) ){
    byte rc;
    byte data = 0; // not used, just an address to feed to twi_writeTo()
    for( byte addr = from_addr ; addr <= to_addr ; addr++ )
    {
        rc = twi_writeTo( addr , &data , 0 , 1 , 1 );
        if( rc == 0 || dump_all_address_to_callback )
            callback( addr , rc );
    }
}

void defaultScanCallback( byte address , byte result ){
    if ( result == 0 )
    {
        Serial.print( "Address: " );
        Serial.print( address , HEX );
        Serial.println( "\tdevice found" );
    }
    return;
}