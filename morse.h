#ifndef _MORSE_H_
#define _MORSE_H_

#ifndef Arduino_h
#include<cstring>
typedef unsigned short int uint16_t;
#endif

struct Morse_Node {
    char Node;
    Morse_Node* LN;
    Morse_Node* RN;
};

void MorseBTCreate();
void MorseBTCreate( Morse_Node* node , uint16_t& counter );
char SearchMorseCode( char* code );

#endif