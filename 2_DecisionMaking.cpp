/********* Decision making: What's covered?
______
** (1) Comparision result and boolalpha
** (2) Spaceship operator and NAN comparision
** (3) If statements and its nuances

***************************/

#include "2_DecisionMaking.h"

//** (1) ****************************//
void BoolAlpha(){

    //How generally comparision results are generated - not true and false but 1 and 0
    cout << " 1==2 : "<< (1==2) << " and 1<2 : " << (1<2) << endl; 
    //To print the actual true or false results,
    cout << boolalpha << " After boolalpha insertion, 1==2 : "<< (1==2) << " and 1<2 : " << (1<2) << endl; 
    cout << " Checking if boolalpha is till ON with new cout stream, 1==2 : "<< (1==2) << " and 1<2 : " << (1<2) << endl; 
    cout << noboolalpha <<" After noboolalpha insertion, 1==2 : "<< (1==2) << " and 1<2 : " << (1<2) << endl; 

}//(1)

//** (2) ****************************//
void SpaceShipNAN(){

    //1. NAN number and its comparision - NAN values are not equal, greater or less than any other values or even NAN
    const double NANnum {numeric_limits<double>::quiet_NaN()};
    cout << " Comparision of NAN < 1: "<< (NANnum < 1) << ", NAN > 2: "<< (NANnum > 2) << ", and NAN==NAN: " << (NANnum == numeric_limits<double>::quiet_NaN()) << endl;

    /*2. All about spaceship operator(<=>) - is not available yet
    ** std::strong_ordering CurrentComparision {1 <=> 0} // the way to check the comparision;
    ** CurrentComparision == std::strong_ordering::less
    ** CurrentComparision == std::strong_ordering::greater
    ** CurrentComparision == std::strong_ordering::equal
    *************/

   /*3. Use cases(<=>) 
    ** Three types of ordering : (1)strong_ordering, (2)partial_ordering and (3)weak_ordering
    ** <=> does not always evaluate to strong_ordering. It depends on the type of operand.
    ** (1)For example, with int(or most fundamental types) it would have strong_ordering since number int are strong_ordered
    ** (2)With float (or anything with floating point numbers), it would evaluate to partial_ordering since floating point numbers are not totally ordered.
    ** what happens if we use this operator on NAN, NAN1<=>NAN2 it will evaluate to std::partial_ordering::unordered
    ** (3)Weak_ordering is only evaluated to whenever we implement <=> for user defined data tyepes
    *************/

   /*3. Result types(<=>) 
    ** Three types of ordering : (1)less, (2)greater, (3)equal, (4)equivalent and (5)unordered
    ** > strong_ordering uses equal while weak and partial ordering uses equivalent. int can have equal, floats can't be compared so they can be equivalent.
       > equal means you can interchange two variables, but equvivalent does not mean you can interchange them
       > for example, -0.0== +0.0 here sign bits of both variables are different. However, they are for certain same value. so they are quite equal but not exactly, so equivalent.
    ** For Int, strong_ordering::equal is same as strong_ordering::equivalent
    ** strong and weak ordering can implicitely convert to partial but there is no other way around
    ** std::strong_ordering CurrentComparision {1 <=> 0}, we can also use results like this to reduce typing:
       > std::is_lt(CurrentComparision) - less than
       > std::is_gt(CurrentComparision) - greater than
       > std::is_eq(CurrentComparision) - equal
       > std::is_neq(CurrentComparision) - not equal
       > std::is_lteq(CurrentComparision) - less than or equal
       > std::is_gteq(CurrentComparision) - greater than or equal
    *************/


}//(2)

//** (3) ****************************//
void AllAboutIf(){

    //The deadly ; - this causes to miss the next block and we will not reach the 
    if(0>5);
        cout<<"This will always reached no matter the condition!"<<endl;
    //else //this won't compile because of earlier ;
        //cout<<"We can reach at else block" << endl;

    if(0<5); // is same as if(0<5){ }

    //Why this can happen? because empty ; is allowed in C++, so any statement with multiple ; at the end is valid
    int i = 25;;;;;
    cout << "Multiple ;;;;; is fine" << endl;;;;;;

    //Casting true to an int converts it to 1 and false will be zero, and reverse is also true
    bool BoolTrue = true;
    bool BoolFalse = false;
    int intTrue = (int) BoolTrue;
    int intFalse = (int) BoolFalse;
    cout << " Value of intTrue : " << intTrue << " value of intFalse : " << intFalse << endl;  

    //any number greater than 0 is true in bool terms and only false when is equal to zero
    BoolTrue = 77;
    BoolFalse = 0;
    cout << " After assigning 77, Value of BoolTrue : " << BoolTrue << " | After assigning 0, value of BoolFalse : " << BoolFalse << endl; 

    //header <cctype> provides you with ways to test characters such as isupper(), isblank(), and ispunct() etc.

    //else always belongs to the nearest if
    if ("Coffee" == "Coffee")
        if (0>5) {}
        else {} //this else belongs to if(0>5) since its closest to that, to avoid this use brackets instead

    //no need to compare a bool to a bool - true or false since it itself is a bool
    bool IsValid = true;
    if(IsValid == true) { } //no need to do this
    if(IsValid) { } //this is suffice

    /************* Logical vs Bitwise operators ***************
    * Don't be confused about logical and bitwise operators, they look same but are not the same 
    * && vs &, || vs |, ! vs ~ for example
    * With logical operators, the value always evaluates to bool values - true or false , even though operands are integers or any other values
    * With bitwise operators, they always evaluate to integer numbers - even if both operands are bool
    **********************/
    
    //in the example of bitwise operators below we will have 'true | true' scenario, so true will be first converted to int '1 | 1' - and then bitwise operation will happen on its bit values
    if(500>1000 | 100>200) {}
    //Bitwise operators are called short circuit operators since they always evaluate both sides of any operators, that is not the case with logical operators
    //With logical operators if you have X || Y scenario, if X is true Y is not evaluated.
    //Similarly, if you have X && Y scenario, and if X is false, Y is not evaluated.






}//(3)



int main(){
    //BoolAlpha();      //(1)
    //SpaceShipNAN();   //(2)
    AllAboutIf();       //(3)
}