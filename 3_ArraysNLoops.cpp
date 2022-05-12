/********* Arrays and loops: What's covered?
______
** (1) Array initialization
** (2) For loop


***************************/

#include "3_ArraysNLoops.h"

//** (1) ****************************//
void Arrays(){

    //Array represents a sequence of the memory location, each storing the same type of data.
    //define an array of exam marks for 150 different students
    int StudentMarks[150]; //currently all 150 memory locations have junk values

    //Initialized student marks with 0 value,
    int InitializedStudentMarks[150] {}; //All 150 memory location now have 0 value.

    //array with already specified values
    signed int GamesWons[6]{12,25,35,41,65,85}; // if each element is 4-bytes, total array size is 24 bytes

    //if we have only specified some value out of all
    int LolTyped[6]{54,20,68}; //array internal values 54,20,68,0,0,0

    //if we want to define a constant array which can not be modified later on,
    const double Acceleration[3]{9.88,9.89,9.78}; //now this array can not be modified anywhere

    //arrays can not be copied like normal types
    int j = 10, k = 15;
    int OneArray[3] { 15,65,95}, SecondArray[3] {65,89,41};
    j = k; // this is allowed
    //OneArray = SecondArray; // not allowed - to copy it assign it element by element

    //automatically inferring the number of elements in array
    string AutoInferArray[]{"Lol", "Wow", "What"}; //size of the array will be 3
    cout << "Size of the array AutoInferArray[]{\"Lol\", \"Wow\", \"What\"}: " << std::size(AutoInferArray) <<  endl;

    //old way of finding size when there is no C++17 support available,
    cout << "Size of the AutoInferArray traditional way sizeof(AutoInferArray)/sizeof(AutoInferArray[0]) : " << sizeof(AutoInferArray)/sizeof(AutoInferArray[0])  << "\n" << endl; 

    //this single variable handles loops and size of the array. Keeping it constant will help us keeping it constant through out - avoids errors
    const int Size = 2; 
    string Names[Size]{};
    for (size_t i = 0; i < Size; i++) //first sentense with ; after for loop is ran for the loop
        Names[i] = "Wow"; //this is fine
    for (size_t i = 0; i < Size; i++) //if we want to execute multiple statements, we need to use brackets
    {
        cout << Names[i] << endl;
        Names[i] = "NotOkay"; //this is fine
        cout << "Used brackets" << endl;
    } cout <<"\n" << endl;

    //interesting way to use forloop to sum elements of the array!
    int ArrayToSum[] {5,10,20};
    int sum{};
    for (size_t i = 0; i < std::size(ArrayToSum); sum += ArrayToSum[i++]); //try to avoid this since, readable code is more important than being percieved clever
    cout << "Sum of the ArrayToSum[] {5,10,20} : " << sum  << "\n"<< endl;
    

    

}//(1)

//** (2) ****************************//
void ForLoop(){

    //very traditional for loop
    for (int i = 0; i < 3; i++)
    {
        /* do something */
    }

    /***************** Bit about size_t ******************
    * Type size_t is a typedef that's an alias for some unsigned integer type, typically unsigned int or unsigned long, 
    * but possibly even unsigned long long. Each Standard C implementation is supposed to choose the unsigned integer 
    * that's big enough--but no bigger than needed--to represent the size of the largest possible object on the target platform
    * https://stackoverflow.com/questions/131803/unsigned-int-vs-size-t#:~:text=When%20writing%20C%20code%20you,most%20efficiently%20perform%20integer%20arithmetic.
    * Excellent read - https://www.embedded.com/why-size_t-matters/ 
    * ********************/
    cout << "In this system the Standard C++/C implementation has choosen size_t with size " << sizeof(size_t) << endl;


    //so new way of writing loops is using size_t instead of int
    size_t i {};
    for (i = 0; i < 3; i++)
    {
        /* do something */
    }
    
    //also, it can be done like this too,
    size_t j {}; //initialized with zero
    for (; j < 3; j++)
    {
        /* code */
    }


}//(2)



int main(){
    Arrays();      //(1)
    ForLoop();     //(2)
}