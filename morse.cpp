#include"morse.h"

Morse_Node* root;

char MorseCodePreSet[] = {
    '$' , 'E' , 'I' , 'S' , 'H' , '/' , '/' , 'V' , '/' , '/' , 'U' ,
    'F' , '/' , '/' , '/' , 'A' , 'R' , 'L' , '/' , '/' , '/' , 'W' ,
    'P' , '/' , '/' , 'J' , '/' , '/' , 'T' , 'N' , 'D' , 'B' , '/' ,
    '/' , 'X' , '/' , '/' , 'K' , 'C' , '/' , '/' , 'Y' , '/' , '/' ,
    'M' , 'G' , 'Z' , '/' , '/' , 'Q' , '/' , '/' , 'O' , '/' , '/'
};

void MorseBTCreate(){
    root = new Morse_Node;
    uint16_t counter = 0;
    MorseBTCreate( root , counter );
    return;
}

void MorseBTCreate( Morse_Node* node , uint16_t& counter ){
    node -> Node = MorseCodePreSet[counter];
    if ( node -> Node == '/' )
    {
        return;
    }
    node -> LN = new Morse_Node;
    node -> RN = new Morse_Node;
    MorseBTCreate( node -> LN , ++counter );
    MorseBTCreate( node -> RN , ++counter );
    return;
}

char SearchMorseCode( char* code ){
    Morse_Node* node_now = root;
    for ( int i = 0 ; i < strlen( code ) ; i++ )
    {
        if ( code[i] == '.' )
        {
            node_now = node_now -> LN;
        }
        else if ( code[i] == '-' )
        {
            node_now = node_now -> RN;
        }
        else
        {
            return '\0';
        }
    }
    return node_now -> Node;
}