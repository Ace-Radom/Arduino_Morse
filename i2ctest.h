// Program comes from https://www.lab-z.com/ai2cscan/ posted on 3 Dec. 2013
// Copied, edited and reformated by Ace-Radom <https://github.com/Ace-Radom>

#ifndef _I2CTEST_H_
#define _I2CTEST_H_

#include "Wire.h"
extern "C" {
    #include "utility/twi.h"
}

void scanI2CBus( byte from_addr , byte to_addr , void ( *callback )( byte address , byte result ) );

#endif