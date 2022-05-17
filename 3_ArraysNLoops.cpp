/********* Arrays and loops: What's covered?
______
** (1) Array initialization
** (2) stdArray
** (3) For loop


***************************/

#include "3_ArraysNLoops.h"
#include <array>

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
    std::string AutoInferArray[]{"Lol", "Wow", "What"}; //size of the array will be 3
    std::cout << "Size of the array AutoInferArray[]{\"Lol\", \"Wow\", \"What\"}: " << AutoInferArray->size() <<  std::endl;

    //old way of finding size when there is no C++17 support available,
    std::cout << "Size of the AutoInferArray traditional way sizeof(AutoInferArray)/sizeof(AutoInferArray[0]) : " << sizeof(AutoInferArray)/sizeof(AutoInferArray[0])  << "\n" << std::endl; 

    //this single variable handles loops and size of the array. Keeping it constant will help us keeping it constant through out - avoids errors
    const int Size = 2; 
    std::string Names[Size]{};
    for (size_t i = 0; i < Size; i++) //first sentense with ; after for loop is ran for the loop
        Names[i] = "Wow"; //this is fine
    for (size_t i = 0; i < Size; i++) //if we want to execute multiple statements, we need to use brackets
    {
        std::cout << Names[i] << std::endl;
        Names[i] = "NotOkay"; //this is fine
        std::cout << "Used brackets" << std::endl;
    } std::cout <<"\n" << std::endl;

    //interesting way to use forloop to sum elements of the array!
    int ArrayToSum[] {5,10,20};
    int sum{};
    for (size_t i = 0; i < std::size(ArrayToSum); sum += ArrayToSum[i++]); //try to avoid this since, readable code is more important than being percieved clever
    std::cout << "Sum of the ArrayToSum[] {5,10,20} : " << sum  << "\n"<< std::endl;
    
    //character arrays
    char vowels[5] {'a','e','i','o','u'}; //this is not a std::string - its just an array of five characters
    char vowels_extra[6] {'a','e','i','o','u'}; //since we have one extra space here, that will be initialized with null character - \0
    char vowels_auto[] {'a','e','i','o','u'}; //will have five elements automatically

    //char array with a std::string
    char myName[10] {"What ever"}; //this is similar to
    char myName_char [10] {'W','h','a','t',' ','e','v','e','r','\0'}; //notice the null character at the std::endl
    char autoNull[] {"Null"}; //the array will be of 5 characters with one null at the std::endl - {'N','u','l','l','\0'}

    //whenever we print the char array be carefull - with char we get entire std::string ununtill we have null character
    std::cout << " Printing char vowels[5] {'a','e','i','o','u'}; : "<< vowels << std::endl; //this will print aeiou
    //for safe guard with older compiler always make sure there is a null character at the std::endl of array. Only store size-1 members and leave \0 at the std::endl
    //but that is not the same with int array - here we get the address of the first byte!
    //For loop below, can be a problem since at the std::endl of aeiou in memory, we may or may not have \0 characer
    //it will keep running untill we encounter null character, possibly in invalid mem space. so always make sure to have null character at the std::endl
    for (int i = 0; vowels[i] != '\0'; i++)
        std::cout << " Printing vowels : " << vowels[i] << std::endl;

    int myInts[3] {1,5,9};
    std::cout << " Printing int myInts[3] {1,5,9}; : "<< myInts << std::endl; //this is printing address at the start of the array: 0x63f7b8

    //to read from user input and to store in char array, insertion operators are not enough since they do not recognize the spaces. 
    //user can use std::cin.getline() function. Here you can specify the location you want to store user input 
    //and "c" - any character that indicates termination, instead of "\n" - uncomment block below to practice
    /*const int maxLength = 10;
    char inputStorage[maxLength]{};
    std::cout << " Please enter something here std::endling  with * : " << std::endl;
    std::cin.getline(inputStorage, maxLength, '*');
    std::cout << " User entered : " << inputStorage << std::endl; */

    //All about multi-dimensional array
    float bunny[2][3]; //array with junk values
    float CleanBunny[2][3]{}; //array with values initialized
    int JumpBunny[3][2]{
                        {2,3}, 
                        {4,89},
                        {34,65}
                        };
    std::cout << " \nJumpBunny " << std::endl;
    for (size_t i = 0; i < std::size(JumpBunny); i++)
        for (size_t j = 0; j < std::size(JumpBunny[0]); j++)
            std::cout << JumpBunny[i][j] << " ";
        
    
    //what happens when we miss one of the member in between?
    int missedBunny[3][2]{
                        {2,3}, 
                        {4  }, //missing element will be zero
                        {34,65}
                        };
    std::cout << " \nmissedBunny " << std::endl;
    for (size_t i = 0; i < std::size(missedBunny); i++)
        for (size_t j = 0; j < std::size(missedBunny[0]); j++)
            std::cout << missedBunny[i][j] << " ";

     int LinemissedBunny[3][2]{
                        {2,3}, 
                        {34,65} //last row will be {0,0}
                        };
    std::cout << " \nLinemissedBunny " << std::endl;
    for (size_t i = 0; i < std::size(LinemissedBunny); i++)
        for (size_t j = 0; j < std::size(LinemissedBunny[0]); j++)
            std::cout << LinemissedBunny[i][j] << " ";

    //with mutli dimension arrays, array can only guess one channel
    //int mutliarray [][] { {1,2 }, {3,4 }}; - will not compile
    //array can only automatically workout size of one channel out of all

    int multiArray [][3] {{1,2}, {3,4}}; //this works fine since we only need to deduce once channel
    int multimultiArray [][2][3]{
        { {1,2,3},{4,5,7} },
        { {2,3,4}, {3,5,2} },
        { {45,56,4}, {5,3,2} },
        { {2,32,41}, {6,2,8} }
    };
    std::cout << " \nmultimultiArray " << std::endl;
    for (size_t i = 0; i < std::size(multimultiArray); i++)
        for (size_t j = 0; j < std::size(multimultiArray[0]); j++)
            for (size_t k = 0; k < std::size(multimultiArray[0][0]); k++)
                std::cout << multimultiArray[i][j][k] << " ";

    //Similarly we can have multidimensional character arrays
    //after storing MyCar rest of the 7 characters will be null characters.
    char Cars[][12]{
        "MyCar",
        "YourCar",
        "OurCar"
    };
    std::cout << " \nchar Array " << std::endl;
    for (size_t i = 0; i < std::size(Cars); i++)
        for (size_t j = 0; j < std::size(Cars[0]); j++)
            std::cout << Cars[i][j]  << " " << i << " "<<  j << " "; //this does not print all the lines since insertion operator does not recognize the null character

    //Array usually demands size at the compile time, however some compilers do allow user to specify size just before its initialized.
}//(1)

//** (2) ****************************//
void stdArrays(){

    //c++ offers more advance type of array with some built in functionality. That is std::array<T,N> T-type, N-no of elements
    std::array<int, 5> stdArray; //array with garbage values
    std::array<float, 15> arrayInitialized {1.32, 4.22, 6.0};//first three variable as defined and rest 0.0..etc
    std::array<double, 34> emptyArray {};//all the values 0

    //as of C++17, compiler can deduce the type and length on its own
    //std::array autoArray {1,3.54,5}; //can not deduce from the mixed type or an empty array
    std::array autoArray{1,3,4}; //this works fine
    autoArray.fill(25); //all the array members now will be 25. 
    //Specific numbers such as pi can be written as std::numbers::pi with <numbers> module if the compiler allows

    //also the size of the array can be deduced as follow
    std::cout << "The size of the autoArray: " << autoArray.size() << std::endl;

    //for loop can be used here with array like this
    for (auto number : autoArray)
        {std::cout << "Array autoArray.fill(25) member : " << number << std::endl;}
    
    //When accessing the members of array [] is useful. However it does not check for the validity of the index.
    // Contrary to that .at() does check the validity of the index.
    for (size_t i = 0; i < autoArray.size() + 2; i++)
        std::cout << "autoArray with size 3, when accessing inValid index with [] : " << autoArray[i] << std::endl;
    //using .at(), upon encountering the invalid index, it will throw std::out_of_range error.
    //for (size_t i = 0; i < autoArray.size() + 2; i++)
        //std::cout << "autoArray with size 3, when accessing inValid index with .at(): " << autoArray.at(i) << std::endl;

    //Using the less than or greater than operators with an entire array
    //Only works if the container is of the same size and same type
    std::array one {1,2,5,6};
    std::array two {1,5,2,6};
    std::array three {1,5,2,6};

    //only same when all the elements at each index are same
    //for greater or less than comparision, the result of first element that differs
    std::cout << "\nThree Arrays one {1,2,5,6}, two {1,5,2,6} and three {1,5,2,6} " << std::endl;
    if(two == three) std::cout << "Two and three are equal" << std::endl;
    if(one != two) std::cout << "One and two are not equal" << std::endl;
    if(one < two) std::cout << "One is less than two" << std::endl;
    if(two > one) std::cout << "two is greater than one" << std::endl;

    //however these does not work with normal arrays
    int oneNormal[] {1,2,5,6};
    int twoNormal[] {1,5,2,6};
    //since comparision here really means comparision of the address space of the first element!
    //not the comparision of its elements
    std::cout << "Address of oneNormal: " << oneNormal << " Address of twoNormal : " << twoNormal << std::endl; 
    //std::cout << "So doing oneNormal>twonormal : is comparing the address sequence : " << (oneNormal == twoNormal) << std::endl; //Compilation depends on the compiler. may or may not allow

    //we can not do twoNormal = oneNormal, since its really assignment of the address, it does not assign elements of oneNormal to twoNormal
    //however with std::array user can perform assignment as long as they are of the same size and same type of elements
    two = one; //completely fine

    //moreover we can store array inside an array which we can not do with the normal array,
    //no performance overhead with std::array unless we use .at()
    std::array<std::array<int, 5>,6> newArray;

    //with legacy code, we may have function that only accepts the c-style array, not the std one, to access the code array inside the std::array
    auto Array = newArray.data(); //with .data() we can use the core array encapsulated within std::array
    

}//(2)

//** (3) ****************************//
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
    std::cout << "In this system the Standard C++/C implementation has choosen size_t with size " << sizeof(size_t) << std::endl;


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
        std::cout << (i,j,k) <<std::endl; 

        //keep in mind, execution of i++, j+=3 and K+=10 only occurs 
        //after the loop has processed once
    }

    //range based loop
    std::cout << "\n"<< std::endl;
    int MyRange[] {998,125};
    for (int x : MyRange)
    {   
        std::cout << "Range based loop! : " << x << std::endl;
    }

    //skipping loop iterations
    for (size_t i = 0; i < 8; i++)
    {
        //skip to the next iteration with contunue;
        if(i==4) { std::cout << "Skipping at value 4" << std::endl; continue;} 
        std::cout << " Breaking the loop at 6, value of i : " << i << std::endl;
        //break at certain iteration and get out of the loop for good
        if(i==6) break;
        //return; //within a function using return; will break out of the loop and function as well.
    }
    
    //while controlling the loop, it is essential to know if you are working with unsigned int
    //since overflow can be a serious issue
    unsigned int uIntValue = 10;
    int NegValue = 5685;
    std::cout << "\nUnwanted results from automatic casting :  deducting usingint from bigger int value (10 - 5685 = should be -5675) : " << uIntValue - NegValue << std::endl;
    uIntValue = -568;
    std::cout << "Assigning a negative value to unsigned int : uIntValue = -568 : uIntValue = " << uIntValue;

    //all things should be considered with while and do_while loops as well.

}//(3)

//** (4) ****************************//
void stdVector(){

    //Use std::vector when number of elements can not be decided during the compile time
    //if number of element is already known and fixed, use the type std::array

    //similar to array, vector does not need to know the number of elements to be stored at the compile time
    std::vector<double> FirstVector;
    //values can be added with push_back or emplace_back
    FirstVector.push_back(2.65);
    FirstVector.emplace_back(6.697);

    //it is possible to define a vec with predefined values - notice the bracket type
    std::vector<int> PreDefVec(15); //vec with 15 elements and all with value of 0
    std::vector<int> preDefVec1{15}; //vec with one element having value of 15

    //it is also possible to define a vec with specific values 
    std::vector<double> preDefVecValue(10,2.35); //vec with 10 elements and each with value of 2.35
    std::vector<double> preDefVecValue1 {10,2.35}; //vec with 2 elements having value of 10 and 2.35

    //both the examples above used () brackets. With {} brackets we can initialize vec like we did with array
    std::vector<int> SampelVec {2,6,8,6,3};

    //vector also has the ability to deduce type
    std::vector deduceTypeVec1 {5,6,9};
    std::vector deduceTypeVec2 (15,20.25); //type float deduced

    //similar to array, vector element can be accessed using [] or the at(). Where [] will not do the bound check, however at() will do that
    for (size_t i = 0; i <= deduceTypeVec1.size(); i++)
        std::cout << "Here is the value out of bound : " << deduceTypeVec1[i] << std::endl;
    //however this can be prevented using .at() which will generate out_of_range error with some overhead

    //Similar to array we can perform the comparision with vector too. To perform comparision, size does not have to be same, only the data type has to be the same
    //lexical order means Dictionary order. Dumb comes before Dumber in dictionary. Dumb has smaller index than Dumber in dictionary
    std::vector <int> OneVec {1,2,5,6};
    std::vector <int> TwoVec {1,2,5,6,8,9};
    std::vector <int> ThreeVec {1,3,4,7};
    std::vector <float> FourVec {1,2,5,6};
    std::cout << "\nThree vec in interest : OneVec {1,2,5,6}, TwoVec {1,2,5,6,8,9}, ThreeVec {1,3,4,7}, FourVec {1,2,5,6}" << std::endl;
    if(OneVec != TwoVec) std::cout << "OneVec is different than TwoVec" << std::endl;
    if(OneVec < TwoVec) std::cout << "TwoVec is lexically bigger than oneVec" << std::endl;    
    //if(OneVec != FourVec) std::cout << "OneVec and FourVec does not have the same datatype" << std::endl; //does not compile, since vector types are different

    //also, a vector can be assinged to vector of any length as long as it has the same data type
    std::vector <int> copyOneVec {1,5,9,8,7,6};
    copyOneVec = OneVec;
    std::cout << "\nOneVec {1,2,5,6} and copyOneVec {1,5,9,8,7,6}, we have done copyOneVec = OneVec" << std::endl;
    std::cout << "copyOneVec size : " << copyOneVec.size() << std::endl;

    //similar to fill in array, we have assing function in vector
    copyOneVec.assign(5,26); //now copyOneVec has first 5 elements and each with value of 26
    std::cout << "After copyOneVec.assign(5,26), copyOneVec size : " << copyOneVec.size() << " values ";
    for (size_t i = 0; i < copyOneVec.size(); i++)
        std::cout << " " << copyOneVec[i] << " ";
    copyOneVec.assign(10,15);//assigning first 10 elements the value of 15
    std::cout << "\nAfter copyOneVec.assign(10,15), copyOneVec size : " << copyOneVec.size() << " values ";
    for (size_t i = 0; i < copyOneVec.size(); i++)
        std::cout << " " << copyOneVec[i] << " ";

    //vector provides functions such as empty(), erase(), clear() etc.

}//(4)



int main(){
    //Arrays();      //(1)
    //stdArrays();     //(2)
    //ForLoop();     //(3)
    stdVector();     //(4)
}