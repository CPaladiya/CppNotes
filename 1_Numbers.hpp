/*  What's covered?
** (1) How to check if a header is available? and if yes, how to conditionally use it?
** (2) Never attach 0 in from of a value, why?
*/

//(1) **************************** notice how one can check if there is header file avaliable //
#if __has_include(<format>)
#include <format>
#endif //(1)

#include <iostream>

using namespace std;

void HeaderCheck(); //(1)
void OctalValues(); //(2)