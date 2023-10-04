// g++ test_morse.cpp ../morse.cpp -o test_morse.exe

#include<iostream>

#include"../morse.h"

int main(){
    MorseBTCreate();
    std::cout << SearchMorseCode( "..." ) << std::endl;     // S
    std::cout << SearchMorseCode( "---" ) << std::endl;     // O
    std::cout << SearchMorseCode( "-.-" ) << std::endl;     // K
    std::cout << SearchMorseCode( "..--" ) << std::endl;    // / (do not exist)
    return 0;
}