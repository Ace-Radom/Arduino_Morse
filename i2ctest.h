// Program comes from https://www.lab-z.com/ai2cscan/ posted on 3 Dec. 2013
// Copied, edited and reformated by Ace-Radom <https://github.com/Ace-Radom>

#ifndef _I2CTEST_H_
#define _I2CTEST_H_

#include "Wire.h"
extern "C" {
    #include "utility/twi.h"
}

const byte dstart_addr = 0x01; // default_start_address
const byte dend_addr   = 0x7F; // default_end_address

void ScanI2CBus( byte from_addr , byte to_addr , bool dump_all_address_to_callback , void ( *callback )( byte address , byte result ) );
void defaultScanCallback( byte address , byte result );

#endif