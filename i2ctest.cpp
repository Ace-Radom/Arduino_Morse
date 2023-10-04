// Program comes from https://www.lab-z.com/ai2cscan/ posted on 3 Dec. 2013
// Copied, edited and reformated by Ace-Radom <https://github.com/Ace-Radom>

#include"i2ctest.h"

/**
 * @brief Scan I2C bus between addresses @p from_addr and @p end_addr
 * 
 * @param from_addr                     scan begin address
 * @param to_addr                       scan end address
 * @param dump_all_address_to_callback  will the function call the callback function at each address
 * @param callback                      callback function
 * 
 * @attention Assumes Wire.begin() has already been called
*/
void ScanI2CBus( byte from_addr , byte to_addr , bool dump_all_address_to_callback ,
                 void ( *callback )( byte address , byte result ) ){
    byte rc;
    for ( byte addr = from_addr ; addr <= to_addr ; addr++ )
    {
        rc = twi_writeTo( addr , NULL , 0 , 1 , 1 );
        if( rc == 0 || dump_all_address_to_callback )
            callback( addr , rc );
    }
}

void defaultScanCallback( byte address , byte result ){
    if ( result == 0 )
    {
        Serial.print( "Address: 0x" );
        Serial.print( address , HEX );
        Serial.println( "\tdevice found" );
    }
    return;
}