/********* Decision making: What's covered?
______
** (1) Comparision result and boolalpha

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



int main(){
    //BoolAlpha();      //(1)
    SpaceShipNAN();
}