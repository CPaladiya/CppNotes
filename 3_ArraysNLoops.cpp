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
    std::cout << "Size of the array AutoInferArray[]{\"Lol\", \"Wow\", \"What\"}: " << std::size(AutoInferArray) <<  endl;

    //old way of finding size when there is no C++17 support available,
    std::cout << "Size of the AutoInferArray traditional way sizeof(AutoInferArray)/sizeof(AutoInferArray[0]) : " << sizeof(AutoInferArray)/sizeof(AutoInferArray[0])  << "\n" << endl; 

    //this single variable handles loops and size of the array. Keeping it constant will help us keeping it constant through out - avoids errors
    const int Size = 2; 
    string Names[Size]{};
    for (size_t i = 0; i < Size; i++) //first sentense with ; after for loop is ran for the loop
        Names[i] = "Wow"; //this is fine
    for (size_t i = 0; i < Size; i++) //if we want to execute multiple statements, we need to use brackets
    {
        std::cout << Names[i] << endl;
        Names[i] = "NotOkay"; //this is fine
        std::cout << "Used brackets" << endl;
    } std::cout <<"\n" << endl;

    //interesting way to use forloop to sum elements of the array!
    int ArrayToSum[] {5,10,20};
    int sum{};
    for (size_t i = 0; i < std::size(ArrayToSum); sum += ArrayToSum[i++]); //try to avoid this since, readable code is more important than being percieved clever
    std::cout << "Sum of the ArrayToSum[] {5,10,20} : " << sum  << "\n"<< endl;
    
    //character arrays
    char vowels[5] {'a','e','i','o','u'}; //this is not a string - its just an array of five characters
    char vowels_extra[6] {'a','e','i','o','u'}; //since we have one extra space here, that will be initialized with null character - \0
    char vowels_auto[] {'a','e','i','o','u'}; //will have five elements automatically

    //char array with a string
    char myName[10] {"What ever"}; //this is similar to
    char myName_char [10] {'W','h','a','t',' ','e','v','e','r','\0'}; //notice the null character at the end
    char autoNull[] {"Null"}; //the array will be of 5 characters with one null at the end - {'N','u','l','l','\0'}

    //whenever we print the char array be carefull - with char we get entire string ununtill we have null character
    std::cout << " Printing char vowels[5] {'a','e','i','o','u'}; : "<< vowels << endl; //this will print aeiou
    //for safe guard with older compiler always make sure there is a null character at the end of array. Only store size-1 members and leave \0 at the end
    //but that is not the same with int array - here we get the address of the first byte!
    //For loop below, can be a problem since at the end of aeiou in memory, we may or may not have \0 characer
    //it will keep running untill we encounter null character, possibly in invalid mem space. so always make sure to have null character at the end
    for (int i = 0; vowels[i] != '\0'; i++)
        cout << " Printing vowels : " << vowels[i] << endl;

    int myInts[3] {1,5,9};
    std::cout << " Printing int myInts[3] {1,5,9}; : "<< myInts << endl; //this is printing address at the start of the array: 0x63f7b8

    //to read from user input and to store in char array, insertion operators are not enough since they do not recognize the spaces. 
    //user can use std::cin.getline() function. Here you can specify the location you want to store user input 
    //and "c" - any character that indicates termination, instead of "\n" - uncomment block below to practice
    /*const int maxLength = 10;
    char inputStorage[maxLength]{};
    std::cout << " Please enter something here ending  with * : " << endl;
    std::cin.getline(inputStorage, maxLength, '*');
    std::cout << " User entered : " << inputStorage << endl; */

    //All about multi-dimensional array
    
    
    


    

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
    std::cout << "In this system the Standard C++/C implementation has choosen size_t with size " << sizeof(size_t) << endl;


    //so new way of writing loops is using size_t instead of int
    size_t i {};
    for (i = 0; i < 3; i++)
    {
        /* do something */
    }
    
    //also, it can be done like this too,
    size_t j {}; //initialized with zero
    for (; j < 3; j++); //equivalent to for (; j < 3; j++){}
    

    //a loop can be initiated with floating point values as well
    for (float i = 0.01f; i < 2.06f; i+=0.56f);

    //we can initialize multiple values in for loops as well
    for (int i = 0, j = 25, k = 30 ; i < 3; i++, j+=3, k+=10)
    {   
        //comma operator can be used to aggregate printing of multiple variables
        //this will print each variable in a new line
        std::cout << (i,j,k) <<endl; 

        //keep in mind, execution of i++, j+=3 and K+=10 only occurs 
        //after the loop has processed once
    }

    //range based loop
    std::cout << "\n"<< endl;
    int MyRange[] {998,125};
    for (int x : MyRange)
    {   
        std::cout << "Range based loop! : " << x << endl;
    }

    //skipping loop iterations
    for (size_t i = 0; i < 8; i++)
    {
        //skip to the next iteration with contunue;
        if(i==4) { std::cout << "Skipping at value 4" << endl; continue;} 
        std::cout << " Breaking the loop at 6, value of i : " << i << endl;
        //break at certain iteration and get out of the loop for good
        if(i==6) break;
        //return; //within a function using return; will break out of the loop and function as well.
    }
    
    //while controlling the loop, it is essential to know if you are working with unsigned int
    //since overflow can be a serious issue
    unsigned int uIntValue = 10;
    int NegValue = 5685;
    std::cout << "\nUnwanted results from automatic casting :  deducting usingint from bigger int value (10 - 5685 = should be -5675) : " << uIntValue - NegValue << endl;
    uIntValue = -568;
    std::cout << "Assigning a negative value to unsigned int : uIntValue = -568 : uIntValue = " << uIntValue;

    //all things should be considered with while and do_while loops as well.

}//(2)



int main(){
    Arrays();      //(1)
    //ForLoop();     //(2)
}