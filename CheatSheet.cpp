#include <iostream>
#include <string>
#include <memory>
#include <array>
#include <vector>

// Entity class just to view how Smart Pointers work, see referenced video
class Entity {
    public:
      Entity() {std::cout << "Created Entity!" << std::endl;}
     ~Entity() {std::cout << "Deleted Entity!" << std::endl;}
};

// Function declaration
void myFunction ();

// Reference: https://docs.microsoft.com/en-us/cpp/cpp/?view=msvc-160
int main() {
    static const int arraySize = 5;

// Just a quick reference of basic C++
    // TYPES:
      bool myTrueBool = true;   // could also be 1 
      bool myFalseBool = false; // could also be 0
      int myInt = 5;
      double myDouble = 5.0;
      char myCharacter = 'J';
      std::string myString = "This is my string.";

    // DECLARATIONS:
      /* A C++ program consists of various entities such as variables, 
        functions, types, and namespaces. Each of these entities must 
        be declared before they can be used. A declaration specifies a 
        unique name for the entity, along with information about its 
        type and other characteristics. In C++ the point at which a 
        name is declared is the point at which it becomes visible to 
        the compiler. You cannot refer to a function or class that is 
        declared at some later point in the compilation unit. Variables 
        should be declared as close as possible before the point at 
        which they are used. */

    // POINTERS:
      /* A pointer is a variable that stores the memory address of an object. 
        Pointers are used extensively in both C and C++ for three main purposes:
        - to allocate new objects on the heap,
        - to pass functions to other functions
        - to iterate over elements in arrays or other data structures. 
        In C-style programming, raw pointers are used for all these scenarios. 
        However, raw pointers are the source of many serious programming errors. 
        Therefore, their use is strongly discouraged except where they provide 
        a significant performance benefit and there is no ambiguity as to which 
        pointer is the owning pointer that is responsible for deleting the object. 
        Modern C++ provides smart pointers for allocating objects, iterators for 
        traversing data structures, and lambda expressions for passing functions. 
        By using these language and library facilities instead of raw pointers, 
        you will make your program safer, easier to debug, and simpler to understand 
        and maintain. */
      // Raw Pointer (Don't use, just know)---------------
      int* myPointer = nullptr; // declare pointer & initialize it so that it doesn't store a random address
      int i = 5;
      myPointer = &i;           // assign pointer to address of object
      int j = *myPointer;       // dereference p to retrieve the value at its address
      /* "cout << myPointer;"  would output the mem address
         "cout << *myPointer;" would output the value stored in that mem address */

      // Smart Pointer (Use this, deletes the memory automatically for you)
        // helpful reference: https://www.youtube.com/watch?v=UOB7-B2MfwA&ab_channel=TheCherno
        // to get access to smart pointers, must "#include <memory>"
        /* The simplest smart pointer is the "unique_ptr"
           It cannot be copied and is limited to it's scope, but very low overhead.
           It auto-deletes once it exits the scope it's in. */
        std::unique_ptr<Entity> myEntity = std::make_unique<Entity>();
        /* Another smart pointer is the "shared_ptr"
           It won't auto delete once leaving scope because it has a reference 
           counter and deletes once references to that pointer are gone. It
           has more overhead than a "unique_ptr", so "unique_ptr"s should have
           first preference when using smart pointers.
           Also, you can make copies of "shared_ptr"s. */
        std::shared_ptr<Entity> mySharedEntity = std::make_shared<Entity>();

    // ARRAYS:
      /* An array is a sequence of objects of the same type that occupy a contiguous 
      area of memory. Traditional C-style arrays are the source of many bugs, but are 
      still common, especially in older code bases. In modern C++, we strongly recommend 
      using std::vector or std::array instead of C-style arrays described in this section. 
      Both of these standard library types store their elements as a contiguous block of 
      memory. However, they provide much greater type safety, and support iterators that 
      are guaranteed to point to a valid location within the sequence. */
      // original array, better to use containers
      std::cout << "Print a regular array." << std::endl;
      int myArray[arraySize] = {1, 2, 3, 4, 5}; // created on the stack, deletes once exiting the scope.
      for (int i = 0; i < arraySize; i++) {std::cout << myArray[i] << std::endl;}
      myArray[0] = 6;
      std::cout << myArray[0] << std::endl;

      std::cout << "Print a pointer to an array." << std::endl;
      int* anotherArray = new int[arraySize];   // created on the heap
      for (int i = 0; i < arraySize; i++) {
          anotherArray[i] = i;
          std::cout << anotherArray[i] << std::endl;
      }
      delete[] anotherArray;                    // to delete from heap, must do

      /* HOWEVER, better to use either std::array or std::vector
         Good references: https://stackoverflow.com/questions/4424579/stdvector-versus-stdarray-in-c
                          https://docs.microsoft.com/en-us/cpp/standard-library/array-class-stl?view=msvc-160
                          https://docs.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-160
      */

      // Standard Array: std::array<TYPE, SIZE> NAME;
      // Must #include <array>, safer than raw array, but has more overhead
      std::cout << "Print a an array from the standard library." << std::endl;
      std::array<int, arraySize> myStandardArray;
      for (int i = 0; i < arraySize; i++) {
          myStandardArray[i] = i;
          std::cout << myStandardArray[i] << std::endl;
      }

      // Vector Array: are dynamic in size, use heap memory (slower), don't use if you don't have to
      // references: https://docs.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-160
      std::cout << "Print a vector array." << std::endl;
      std::vector<int> myVector;
      for (int i = 0; i < arraySize; i++) {
          myVector.push_back(i);
          std::cout << myStandardArray[i] << std::endl;
      }

    // LOOPS:
      // While Loop
      int loopCount = 0;
      std::cout << std::endl;
      std::cout << "This is a while loop:" << std::endl;
      while (loopCount < arraySize) {
        std::cout << "While Loop Count: " << loopCount << std::endl;
        loopCount++;
      };
      loopCount = 0; // reset loopCount

      // Do-While Loop
      std::cout << "This is a do-while loop:" << std::endl;
      do {
        std::cout << "Do-While Loop Count: " << loopCount << std::endl;
        loopCount++;
      } while (loopCount < arraySize);
      loopCount = 0; // reset loopCount
      
      // For Loop, see arrays above.
      
      // Nested Loop
      std::cout << "This is a nested loop:" << std::endl;
      for (int i = 0; i < arraySize; i++) {
        std::cout << "Nested Loop Count: " << i << std::endl;
        for (char a = 'A'; a < 68; a++) {
          std::cout << "   " << a << std::endl;
        }
      }

    // CONDITIONS/BRANCHING: reference: https://www.w3schools.com/cpp/cpp_conditions.asp
    /* C++ supports the usual logical conditions from mathematics:
       Less than:                 a < b
       Less than or equal to:     a <= b
       Greater than:              a > b
       Greater than or equal to:  a >= b
       Equal to:                  a == b
       Not Equal to:              a != b

       C++ has the following conditional statements:
       Use if to specify a block of code to be executed, if a specified condition is true
       Use else to specify a block of code to be executed, if the same condition is false
       Use else if to specify a new condition to test, if the first condition is false
       Use switch to specify many alternative blocks of code to be executed */

    if (true)
      std::cout << "Im a true 'if' statement" << std::endl;
    else if (false)
      std::cout << "Im a false 'else if' statement" << std::endl; //will never get printed
    else
      std::cout << "Im just an 'else' statement" << std::endl;    //will never get printed

    std::string coolStatement = (true) ? "I'm a really cool short hand if (aka Ternary Operator)!" : "Meh.";
    std::cout << coolStatement << std::endl;

    switch (arraySize) {
      case 1:
        std::cout << "Monday" << std::endl;
        break;
      case 2:
        std::cout << "Tuesday" << std::endl;
        break;
      case 3:
        std::cout << "Wednesday" << std::endl;
        break;
      case 4:
        std::cout << "Thursday" << std::endl;
        break;
      case 5:
        std::cout << "Friday" << std::endl;
        break;
      case 6:
        std::cout << "Saturday" << std::endl;
        break;
      case 7:
        std::cout << "Sunday" << std::endl;
        break;
      default:
        std::cout << "You got it all wrong!" << std::endl;
    }

    // FUNCTIONS: the function call
      myFunction();
  
  return 0;
}

// Function definition
void myFunction (){
  std::cout << std::endl <<  "Hey, you just called myFunction!" << std:: endl << std::endl;
  return;
}