
#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
    Rectangle smallRectangle(2, 3);
    Rectangle* bigRectangle = new Rectangle(5, 10);
    cout << "length of small rectange " 
        << smallRectangle.getLength() << endl;
    cout << "length of big rectange "
        // pointers require -> notation
        << bigRectangle->getLength() << endl;
    cout << "length of big rectange "
        // dereference the pointer if you really like dot notation
        << (*bigRectangle).getLength() << endl;

    cout << bigRectangle << endl;

    // when we're done with dynamically allocated objects, free the memory
    delete bigRectangle;

    cout << bigRectangle << endl;

    // good habit to set pointers to null when you're done
    bigRectangle = nullptr;

    cout << bigRectangle << endl;

    Rectangle* rectangles = new Rectangle[5];

    cout << "length of rectangle index 0 " << rectangles[0].getLength() << endl;
    cout << "length of rectangle index 0 " << (*rectangles).getLength() << endl;





    int number = 42;

    // nullptr is a special value meaning it's empty
    int* anotherNumber = nullptr;

    anotherNumber = &number;

    cout << number << endl;

    // outputs the memory address being stored
    cout << anotherNumber << endl;

    // gets the value the pointer is pointed at
    cout << *(anotherNumber) << endl;

    (*(anotherNumber))++;

    cout << *(anotherNumber) << endl;
    cout << number << endl;

    number = 77;

    cout << *(anotherNumber) << endl;
    cout << number << endl;

    cout << "enter the number of numbers to enter" << endl;
    int numberOfValues;
    cin >> numberOfValues;


    for (int times = 0; times < 100; times++) {

        cin >> number;

        // int numbers[numberOfValues];

        // creates a dynamic array of integers
        int* values = new int[numberOfValues];

        

        for (int index = 0; index < numberOfValues; index++) {
            cout << "enter value #" << index << endl;
            int value;
            cin >> value;
            values[index] = value;
        }

        cout << values << endl;
        cout << *(values) << endl;

        int* currentValue = values;

        // pointer arithmetic
        cout << "value of current value pointer" << endl;
        cout << currentValue << endl;
        currentValue++;
        cout << "value of current value pointer after ++" << endl;
        cout << currentValue << endl;
        cout << *(currentValue) << endl;

        // take the pointer, add the index value * size of what it's storing
        // then give the value that is at that memory address
        cout << values[2] << endl;

        cout << *(values + 2) << endl;

        /* for (int index = 0; index < numberOfValues; index++) {
             cout << values[index] << endl;
         }*/

        
        // gives the memory back to the OS
        delete[] values;

    }

    cout << "enter something" << endl;
    cin >> number;

    

    
    cout << "enter something" << endl;
    cin >> number;

    cout << "Hello World!\n";
}
