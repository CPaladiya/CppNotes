#include "1_Numbers.hpp"
/*  What's covered?
** (1) How to check if a header is available? and if yes, how to conditionally use it?
** (2) Never attach 0 in from of a value, why?
*/

//** (1) ****************************//
void HeaderCheck(){
#ifdef __cpp_lib_format //if format lib is available, compile code below (one with use of format library),
    cout << format("Why format not working!");
#else //code without the use of format library
    cout << "Hello World!" << endl;
#endif
}//(1)

//** (2) ****************************//
void OctalValues(){
    int i = 100, j = 0100;
    cout << " Values of i " << i << " and j " << j << endl;
    cout << " This happens because when we attach 0 ahead of j, \nwe request to read in \"Octal Values\" instead of \"Decimal Values\"" << endl;
}//(2)



int main(){
    OctalValues();
}