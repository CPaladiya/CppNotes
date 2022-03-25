#include "1_Numbers.hpp"
/*  What's covered?
** (1) How to check if a header is available? and if yes, how to conditionally use it?
** (2) Never attach 0 in from of a value (int of float), why?
** (3) How to know if my program is compiled for big - or little- endian?
*/

//** (1) ****************************//
void HeaderCheck(){
#ifdef __cpp_lib_format //if format lib is available, compile code below (one with use of format library),
    cout << format("Hello world using std::format!");
#else //code without the use of format library
    cout << "Hello World!" << endl;
#endif
}//(1)

//** (2) ****************************//
void OctalValues(){
    //this applies to ints and floats as well
    int i = 100, j = 0100;
    cout << " Values of 'int i = 100' : i is really " << i << ", and 'int i = 0100' : i is really " << j << endl;
    cout << " This happens because when we attach 0 ahead of j, \n we request to read in \"Octal Values\" instead of \"Decimal Values\"" << endl;
}//(2)

//** (3) ****************************//
void CheckEndian(){
    
    // little endian : least significant digit of a number stored first (lower mem address) following the most significant digit (higher mem address)
    // big endian : most significant digit of a number stored first (lower mem address) following the less significant digit (higher mem address)
    
    // let's see the example of a number 513, 4 bytes of memory is assigned to the variable (binary of 513): 0000,0000   0000,0000    0000,0010   0000,0001
    // notice that inside 8-bit array - or a single byte ALWAYS implements big endian, meaning least significant to right and most significant to left

    //Little endian encoding
    /* mem adress : 00               01              02                  03
       values     : 0000,0001        0000,0010       0000,0000           0000,0000*/

    //Big endian encoding
    /* mem adress : 00               01              02                  03
       values     : 0000,0000        0000,0000       0000,0010           0000,0001*/

    #ifdef __cpp_lib_bit //only run this if cpp has bit header c++20

    if(std::endian::native == std::endian::little) { cout << "This system is compiling for little endian" << endl;}
    else if(std::endian::native == std::endian::big) { cout << "This system is compiling for big endian" << endl;}

    #else

    cout << " ---------Testing endian the old school way!------------- " << endl;
    short int word = 0x0001; // assigning some value to short int
    char *b = (char*) &word;
    cout << " Mem size of the word : " << sizeof(word) << " Bytes, Binary value of 'Word' : " << std::bitset<8>(word) << endl;
    cout << " Out of " << sizeof(word) << " bytes, we will fetch the address of the first byte : " << &b   
    << " \n 1) If start char address contains value of 1, that is least significant digit is at the start so, it is little-endian encoding."   
    << " \n 2) If start char address contains value of 0, that is least significant digit is not at the start so, it is big-endian encoding." << endl;

    cout << " b[0] Value: " << (b[0] ? 1 : 0) <<(b[0] ? " : Little Endian " : " : Big Endian ") << endl;

    // Q : What is the reason most os implements little-endian encoding?
    /* A : Well, even if we assign let's say 4 bytes to a variable we don't always use the full capacity,
    *      Most of the numbers will have 0s in their significant digit space. With big endian encoding, 
    *      we traverse from most significant digit to least, we traverse through 0s first most of the time. 
    *      >>> To make it more efficient, we can traverse through least digit first, which will most likely won't be zero.
    ***************/

    #endif
}//(3)

int main(){
}