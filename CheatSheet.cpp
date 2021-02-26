#include <iostream>
#include <string>
#include <memory>

// Entity class just to view how Smart Pointers work, see referenced video
class Entity {
    public:
      Entity() {std::cout << "Created Entity!" << std::endl;}
     ~Entity() {std::cout << "Deleted Entity!" << std::endl;}
};

// Reference: https://docs.microsoft.com/en-us/cpp/cpp/?view=msvc-160
int main() {
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
        {
            /* The simplest smart pointer is the "unique_ptr"
               It cannot be copied and is limited to it's scope, but very low overhead.
               It auto-deletes once it exits the scope it's in. */
            // std::unique_ptr<Entity> myEntity = std::make_unique<Entity>();
//!!!! ... had to comment out code above because won't compile in C++11, will fix later
            /* Another smart pointer is the "shared_ptr"
               It won't auto delete once leaving scope because it has a reference 
               counter and deletes once references to that pointer are gone. It
               has more overhead than a "unique_ptr", so "unique_ptr"s should have
               first preference when using smart pointers.
               Also, you can make copies of "shared_ptr"s. */
            // std::shared_ptr<Entity> mySharedEntity = std::make_shared<Entity>();
//!!!! ... had to comment out code above because won't compile in C++11, will fix later
        }

    // ARRAYS:
      /* An array is a sequence of objects of the same type that occupy a contiguous 
      area of memory. Traditional C-style arrays are the source of many bugs, but are 
      still common, especially in older code bases. In modern C++, we strongly recommend 
      using std::vector or std::array instead of C-style arrays described in this section. 
      Both of these standard library types store their elements as a contiguous block of 
      memory. However, they provide much greater type safety, and support iterators that 
      are guaranteed to point to a valid location within the sequence. */
      // original array, better to use containers
      static const int arraySize = 5;
      int myArray[arraySize] = {1, 2, 3, 4, 5}; // created on the stack, deletes once exiting the scope.
      for (int i = 0; i < 5; i++) {std::cout << myArray[i] << std::endl;}
      myArray[0] = 6;
      std::cout << myArray[0] << std::endl << std::endl;

      int* anotherArray = new int[arraySize];   // created on the heap
      for (int i = 0; i < 5; i++) {
          anotherArray[i] = i;
          std::cout << anotherArray[i] << std::endl;
      }
      delete[] anotherArray;                    // to delete from heap, must do

    // EXPRESSIONS:


    // STATEMENTS:


    // LOOPS:


    // BRANCHING:


    // FUNCTIONS:
  
  
  
  return 0;
}