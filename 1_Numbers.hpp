/*  What's covered?
** (1) How to check if a header is available? and if yes, how to conditionally use it?
** (2) Never attach 0 in front of a value (int or float), why?
** (3) How to know if my program is compiled for big - or little- endian?
** (4) Basics of floats and ints.
** (5) Everything about literals
*/
#include <iostream>
#include <bitset>  //to print binary and hex numbers
#include <iomanip> //to manipulate cout stream

// ^^^^^^^^^^^^^^^^^^^^^^^^^^^ Special def cases ^^^^^^^^^^^^^^^^^ //

//(1) ************************ notice how one can check if there is header file avaliable //
#if __has_include(<format>)
#include <format>
#endif //(1)

//(3) ************************ header to check big/little endian //
#if __has_include(<bit>)
#include <bit>
#endif //(3)

using namespace std;

// ^^^^^^^^^^^^^^^^^^^^^^^^^^^ Clarification Funcs ^^^^^^^^^^^^^^^^^ //

void HeaderCheck();   //(1)
void OctalValues();   //(2)
void CheckEndian();   //(3)
void IntFltNumbers(); //(4)
void Literals();      //(5)