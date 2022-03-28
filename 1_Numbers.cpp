/********* What's covered?
______
** (1) How to check if a header is available? and if yes, how to conditionally use it?
** (2) Never attach 0 in front of a value (int or float), why?
** (3) How to know if my program is compiled for big- or little- endian?
______
** (4) Basics of floats and ints.
** (5) Everything about literals
** (6) Find out limits of flot/int and its versions.
** (7) How to initialize infinity values or NAN(not a number) values?
** (8) ALL about char data type
***************************/

#include "1_Numbers.hpp"

//** (1) ****************************//
void HeaderCheck(){
#ifdef __cpp_lib_format //if format lib is available, compile code below (one with use of format library),
    cout << format("Hello world using std::format!");
#else //code without the use of format library
    cout << "Hello World without std::format!" << endl;
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
void IntFltNumbers(){

    /******* INT : Memory occupied by int *********************************************************

    ** (S/U)Char    - 1   byte (Unsigned/signed only. This is not a character char, that would be just 'char' - without any signature notation)
    ** Short int    - 2   byte
    ** int          - 4   byte
    ** long int     - 4/8 byte
    ** long long int- 8   byte
    ** If you ever need to work with raw memory, prefer c++20 std::byte over (u/s) char or char. 
    */
    
    cout << "********** INT *********" << endl;
    // All the ways you can initialize int,
    int appCount = 5; //Assignment notation
    int dotCount {5}; //Braced initializer
    int mainCount {appCount + dotCount};
    int eveCount(5);  //Functional notation
    
    cout << " int appCount = 5: " << appCount << ", int dotCount {5}: " << dotCount << ", int mainCount {appCount + dotCount}: " << mainCount << ", int eveCount(5): " << eveCount << endl;
    // empty initialization
    int garbage;                //contains garbage value
    int zeroInitialized{};      //automatic zero initialization
    int MoreZeroInitialized{0}; //zero initialization
    cout << " int garbage: " << garbage << ", int zeroInitialized{}: " << zeroInitialized << ", int MoreZeroInitialized{0}: " << MoreZeroInitialized  << endl;

    // implicit conversion problem from other data type to int
  //int popayHand{2.2}; //gives complilation warning or error for implicit conversion or data loss
    int bloobHand(5.5); //compiles without warning, accepts value of 5 (data loss occured)
    int soWhat = 2.52;  //compiles without warning, accepts value of 2 (data loss occured)
    cout << " int bloobHand(5.5): " << bloobHand << ", int soWhat = 2.52: " << soWhat << endl;

    cout << "__________Pitfalls of Int___________" << endl;

    // ************* pit falls of int ********
    unsigned int smallValue = 5u;
    int someValue = 25;  
    cout << " Unsigned small value 5 - some int value 25 = should be -20, but it is: " << smallValue-someValue << endl;
    // instead of smallValue-someValue = -20, it is 4294967276. It is because, statement is casted to unsigned int,
    // which means, -20 is not a valid result, so the valid result would be total signed capacity - 20!

    unsigned char someChar {251}; //this 'u_char' can only hold max 255 values, so if we add 10 to this, there should be an error, let's see!
    someChar += 15;
    cout << " u_char 251 + 15 : " << someChar << endl; //it doesn't give any error, so watch out for it!
    

    /****** FLOAT : let's consider the example of number 365 *************************************************************

    ** Here it can be represeted in floating point number as shown below,
    ** 3.650000E02 - 3.650000 is called 'Mentissa' which has 7 digits and 02 is an 'exponent'. Here 'E' stands for exponent. 
    *******/

   /* let's consider the example of number 365,652,2595
    ** Here it can be represeted in floating point number as shown below,
    ** 3.656522E09 - Even though we have represented the same number here but we have lost three lower order digits.
    ** In memory, 1 single bit is required to store the sign, followed by fixed bits for mentissa and remaining for exponent
    ** Single precision : (32-bit total) : 1 sign, 23 for mentissa and 8 for exponent  : decimal degit precision 7 : range 10E-38 to 10E38
    ** Double precision : (64-bit total) : 1 sign, 52 for mentissa and 11 for exponent : decimal digit precision 15(can ne 16) : range 10E-308 to 10E308
    ** Long Double precision : (Depends on compilers) : 1 sign, 64 for mentissa and rest for exponent : decimal digit precision 18-19 : range 10E-4932 to 10E4932
    *******/

    // Same initialization rules apply to float as well,
    float piValueGarbage;
    float emptyFloat{};
    float piDefined {3.1415926};
    double I2M = 25.4;
    long double random(1.256598564564566651564564135);
    cout << "\n********* FLOAT ********" << endl;
    cout << " float piValueGarbage: " << piValueGarbage << ", float emptyFloat{}: " << emptyFloat
    << ", float piDefined {3.1415926}: " << piDefined << ",\n double I2M = 25.4: " 
    << I2M << ", long double random(1.256598564564566651564564135): " << random << endl;

    cout << "_________Pitfalls of Float__________" << endl;
    // ************* pit falls of Float ********
    /* Some things to look out for with floats 
    ** 1) Many decimal values don't convert exactly to float.
    ** 2) Taking differnce won't be accurate
    ** 3) Values having different orders of magnitude, upon substraction or addition, small values is pretty much ignored.
    */
    
    // 1) There is never exact conversion
    float no1 = 4.0/3.0; //can never have perfect results in decimal world
    
    // 2) 
    float no2a =  1.22'55'66'88'4, no2b = 1.22'55'66'88'1;
    cout << std::setprecision(10) << std::fixed 
    << " 1.22'55'66'88'4 - 1.22'55'66'88'1 should be : 0.00'00'00'00'3, However the difference here is : " 
    << float(no2a - no2b) << endl;

    // 3) As seen with example 2, when working with very big and very small values, very big values will over shadow, 
    // small values in terms of precision. Meaning, the result won't be accurate and large value is largly unchanged.
    float LargeValue = 100E10;
    cout << " 100E10: "<< LargeValue << ", (100E10 + 0.01): "<< (LargeValue + 0.01) << ", (100E10 - 0.01): "<< (LargeValue - 0.02) << endl; 

} //(4)

//** (5) ****************************//
void Literals(){

    /* Constant values of any kind is called literals ex, 100.1, 'A', "Tesla", 555, etc. */
    /* INT:   Unsinged U/u, Long L/l, Long Long LL/ll, Unsigned Long UL/ul, Unsigned long long ULL/ull */
    
    //int literals: initialization with auto keyword,
    auto IntNomral      {5};
    auto IntLong        {5L};
    auto IntUnsigned    {5U};
    auto IntLongLong    {5LL};
    auto USIntLongLong  {5ULL};
    auto GoodVisible    {10'2525'32LL}; //Using ' to make number readable and does not affect the numbers itself
  //unsigned char WrongChar {513U}; //this is wrong since char is only 1 byte (0 to 255), and can not store 513 - complilation error!
  //unsigned int WrongUInt {-1}; //this is wrong since -1 is not unsigned int - compilation error!

    // Hexadecimal literals: Have to append '0x' before hex number.
    auto HIntNormal      {0x56BF};
    auto HIntLongLong    {0x1ABLL};
    auto HIntUnsigned    {0x25U};
    auto HIntUSLongLong  {0x65'52'a6cull};

    // Octal literals: Have to append '0' before the octal number.
    auto oIntNormal      {056};
    auto oIntLongLong    {0165LL};
    auto oIntUnsigned    {025U};
    auto oIntUSLongLong  {065'52'652ull};

    // Binary literals: Have to append '0b' or '0B' before the binary number.
    auto bIntNormal      {0B1100011};
    auto bIntLongLong    {0b1011'0110'1LL};
    auto bIntUnsigned    {0B1101'1011'1011'1U};
    auto bIntUSLongLong  {0b11100111001ull}; 

    /* FLOAT: float f/F, double No_suffix, long double L/l */
    auto FloatNormal     {1.6594565213f};   //F/f suffix
    auto FloatDouble     {5.65568694};      //no suffix
    auto FloatLDouble    {6.6543654L};      //L/l suffix
    auto Float1Way       {6E3};             //6000.0
    auto Float2Way       {525.4E2};         //52540.0
    auto Float3Way       {-4.5E-2L};        //-0.045L
    auto Float4Way       {.256e2F};         //25.60F
                                               
}//(5)

//** (6) ****************************//
void IntFloatLimits(){
    /* Findint the decimal limits of various data type********************************************
    ** Limit here means, the highest and lowest number it can store
    ** Max()   : Highest positive number a type can store
    ** Min()   : Tiniest positive number a type can store if a float, otherwise same as Lowest().
    ** Lowest(): A hugely negative number a type can store
    ********************/

   cout << " *************** INT ***************" <<  endl;
   cout << " short  :: Max: " << numeric_limits<short>::max() << ", Min: " << numeric_limits<short>::min() << ", Lowest: " << numeric_limits<short>::lowest() << endl;
   cout << " int    :: Max: " << numeric_limits<int>::max() << ", Min: " << numeric_limits<int>::min() << ", Lowest: " << numeric_limits<int>::lowest() << endl;
   cout << " uint   :: Max: " << numeric_limits<unsigned int>::max() << ", Min: " << numeric_limits<unsigned int>::min() << ", Lowest: " << numeric_limits<unsigned int>::lowest() << endl;

   cout << " \n************** FLOAT **************" <<  endl;
   cout << " float  :: Max: " << numeric_limits<float>::max() << ", Min: " << numeric_limits<float>::min() << ", Lowest: " << numeric_limits<float>::lowest() << endl;
   cout << " double :: Max: " << numeric_limits<double>::max() << ", Min: " << numeric_limits<double>::min() << ", Lowest: " << numeric_limits<double>::lowest() << endl;

   /* Findint the bits in a type********************************************
    ** The sign bit will be excluded
    ** int   : all the bits required except sign bit
    ** float : all the bits required for mentissa, excluding exponent and sign bit
    ** Read more about available options: https://en.cppreference.com/w/cpp/types/numeric_limits
    ********************/
   cout << " \n************** BITS **************" <<  endl;
   cout << " int   :: bits: " << numeric_limits<int>::digits << endl;
   cout << " float :: Mentissa bits: " << numeric_limits<float>::digits << endl;

}//(6)

//** (7) ****************************//
void InfyNANNum(){

    /** All about Infinity and NAN first *****************
    ** +-Value/0 or any operation of +-Value with +-Infinity results in +-Infinity
    ** 0/0, 0*(+-Infinity) and any operation between multiple +-Infinity converts to NAN
    *******************/

    //Here is the way to initialize a infinity or NAN variable,
    float positive_infinity = std::numeric_limits<float>::infinity();
    double negative_infinity = -std::numeric_limits<double>::infinity();
    long double not_a_number = std::numeric_limits<long double>::quiet_NaN();

    cout << " positive_infinity: " << positive_infinity << ", negative_infinity: " <<  negative_infinity << ", not_a_number: " << not_a_number << endl;

}//(7)

//** (8) ****************************//
void charInfo(){

    /********** 'char' is different than 'signed char' or 'unsigned char'
    ** signed or unsigned char is basically int with capacity of 1 byte
    ** However, char is for character and it works in a character spcace */

   //difference between unsinged/signed char and char,
    unsigned char uChar = 50;
    signed char sChar = -2;
    cout << " ******** S/U Char **********" << endl;
    cout << " unsigned char uChar = 50: " << uChar << ", signed char sChar = -10: " << sChar << endl;
    cout << " value of uChar + 1: "<< uChar + 1 << endl;

    char garbage; //contains garbage since not initialized
    char yeah {'Y'}, nup {'N'}; //char always have singe quote ''
    cout << " \n********* Char ***********" << endl;
    cout << " char yeah {'Y'}: " << yeah << ", char nup {'N'}: " << nup << endl;
    yeah++; //incrementing Y by 1
    cout << " Incrementing yeah by 1: should be 89 for Y + 1 = 90. but it returns in terms of char : " << yeah << endl;
    cout << " To get the underlying value it can be cast to int, std::static_cast<int> (yeah) : " << static_cast<int>(yeah) << endl;

    cout << "\n__________Pitfalls of char___________" << endl;
    //reading from user stream, all white space before char will be ignored.
    //if tried to input other data type to char, only first digit will be stored as char
    //depending on a compiler it may break the program too

    char UserChar;
    char UserInt;
    //uncomment below to try it out,
    //cout << " Please enter a single char value: " << endl;
    //cin >> UserChar;
    //cout << " system recorded: " << UserChar <<endl;

    //cout << " Please enter an int value: " << endl;
    //cin >> UserInt;
    //cout << " system recorded: " << UserInt <<endl;

    /********** wchar_t is a wide character, meaning char type only supports 256 character. Some languages have 10K+ characters.
     ** So to accomodate such requirements, wchar_t is used. wchar_t can handle lot more than 256 characters.
     ** To print wide character to console we need to use 'wcout' instead of 'cout', for input, 'wcin' instead of 'cin'
     ** Always append L to wide char for successful compilation
    **********/

    //ways to define wchar_t,
    wchar_t zChar {L'Z'};
    auto zaChar {L'Z'}; //notice the appended L to indicate wchar_t
    wcout << " value of wchar_t zChar {'Z'}: " << zChar << ", auto zaChar {L'Z'}: "<< zaChar << endl;

    //since for some of the wide characters we don't have the keyboard keys, we can use hex code associated,
    wchar_t cc {L'\x00E7'};
    wcout << " wchar_t cc {L'\x00E7'}: "<< cc << endl;

    /********** pitfalls of wchar_t
     ** This type is implementation specific, windows implements 16 bit wchar_t, with wide character literlas encoded with UTF-16
     ** Others do it 32 bit, with wide character literlas encoded with UTF-32
     ** That is okay for apps that work with native plateform, but for cross plateform apps, this would be a problem
     ** So, it is recommended to use char8_t, char16_t and char32_t. character encoding here is UTF-8, UTF-16 and UTF-32. Their size are same on all plateforms.
     ** There is no provision in lib yet for handling char8, 16 or 32 stream print or input as wide characters have wcoud/wcin
    **********/

   //char8_t yen8 {u8'\x00A5'}; //u8, should always use char8_t to store UTF-8 encoded letters, instead of char
   char16_t yen16 {u'\x00A5'}; //u or u16
   char32_t yen32 {U'\x00A5'}; //U

} //(8)

int main(){
    
    /********* What's covered?
______
** (1) How to check if a header is available? and if yes, how to conditionally use it?
** (2) Never attach 0 in front of a value (int or float), why?
** (3) How to know if my program is compiled for big- or little- endian?
______
** (4) Basics of floats and ints.
** (5) Everything about literals
** (6) Find out limits of flot/int and its versions.
** (7) How to initialize infinity values or NAN(not a number) values?
** (8) ALL about char data type
***************************/

    //HeaderCheck();   //(1)
    //OctalValues();   //(2)
    //CheckEndian();   //(3)
    //IntFltNumbers(); //(4)
    //Literals();      //(5)
    //IntFloatLimits();//(6)
    //InfyNANNum();    //(7)
    charInfo();      //(8)
}
