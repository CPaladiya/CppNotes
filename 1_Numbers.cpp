#include "1_Numbers.hpp"
/*  What's covered?
** (1) How to check if a header is available? and if yes, how to conditionally use it?
** (2) Never attach 0 in front of a value (int or float), why?
** (3) How to know if my program is compiled for big - or little- endian?
** (4) Basics of floats and the way it is stored.
** (5) Basics of integers and initialization
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

//** (4) ****************************//
void FloatNumbers(){
    /* let's consider the example of number 365
    ** Here it can be represeted in floating point number as shown below,
    ** 3.650000E02 - 3.650000 is called 'Mentissa' which has 7 digits and 02 is an 'exponent'. Here 'E' stands for exponent. 
    *******/

   /* let's consider the example of number 365,652,2595
    ** Here it can be represeted in floating point number as shown below,
    ** 3.656522E09 - Even though we have represented the same number here but we have lost three lower order digits.
    ** In memory, 1 single bit is required to store the sign, followed by fixed bits for mentissa and remaining for exponent
    ** Single precision : (32-bit total) : 1 sign, 23 for mentissa and 8 for exponent
    ** Double precision : (64-bit total) : 1 sign, 52 for mentissa and 11 for exponent
    *******/


} //(4)

//** (5) ****************************//
void IntNumbers(){

    /* Memory occupied by int
    ** (S/U)Char    - 1   byte (Unsigned/signed only. This is not a character char, that would be just 'char' - without any signature notation)
    ** Short int    - 2   byte
    ** int          - 4   byte
    ** long int     - 4/8 byte
    ** long long int- 8   byte
    ** If you ever need to work with raw memory, prefer c++20 std::byte over (u/s) char or char. 
    */
    
    // All the ways you can initialize int,
    int appCount = 5; //Assignment notation
    int dotCount {5}; //Braced initializer
    int mainCount {appCount + dotCount};
    int eveCount(5);  //Functional notation

    cout << "int appCount = 5: " << appCount << ", int dotCount {5}: " << dotCount << ", int mainCount {appCount + dotCount}: " << mainCount << ", int eveCount(5): " << eveCount << endl;

    // empty initialization
    int garbage;                //contains garbage value
    int zeroInitialized{};      //automatic zero initialization
    int MoreZeroInitialized{0}; //zero initialization

    cout << "int garbage: " << garbage << ", int zeroInitialized{}: " << zeroInitialized << ", int MoreZeroInitialized{0}: " << MoreZeroInitialized  << endl;

    // implicit conversion problem from other data type to int
  //int popayHand{2.2}; //gives complilation warning or error for implicit conversion or data loss
    int bloobHand(5.5); //compiles without warning, accepts value of 5 (data loss occured)
    int soWhat = 2.52;  //compiles without warning, accepts value of 2 (data loss occured)

    cout << "int bloobHand(5.5): " << bloobHand << ", int soWhat = 2.52: " << soWhat << endl;

    //initialization with auto keyword,
    auto IntNomral      {5};
    auto IntLong        {5L};
    auto IntUnsigned    {5U};
    auto IntLongLong    {5LL};
    auto USIntLongLong  {5ULL};
    auto GoodVisible    {10'2525'32LL}; //Using ' to make number readable and does not affect the numbers itself

}//(5)

int main(){
    IntNumbers();
}
