/********* Arrays and loops: What's covered?
______
** (1) Pointers


***************************/

#include "3_ArraysNLoops.h"
#include <array>

//** (1) ****************************//
void Pointers(){

    //Pointer stores an address of the variable of a certain type. So, a pointer points to a address in a memory where that type of variable is located
    int *First; //Variable First stores address of the int type variable stored in a memory somewhere. 
    float* SameFirst; //variable can also have * near to the type. Ideally, we want * near to the variable name instead of the type name

    //multiple variables can be defined like this
    int *var1, *var2; //both var1 and var2 is a pointer pointing to int type
    int *var3, var4; //------Warning!! var3 is a pointer to int however, var4 is simply an int variable

    //varibale untill now does not point to anything. However that is not a good idea, since it contains some garbage value that can produce untraceable error
    //to avoid that always initialize pointer variables with nullptr like this
    double *iniVar{nullptr}; //this does not contain any garbage values.

    double NewVar {200.23};
    double *NewPtr = &NewVar; //storing the address of the NewVar into new variable.

    /*Pointers to type Char
    */
}//(1)





int main(){
    Pointers();      //(1)
}