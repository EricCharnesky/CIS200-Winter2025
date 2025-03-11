
#include <iostream>
#include <vector>

#include <stdexcept>

#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

using namespace std;



int main()
{
    DoublyLinkedList<int> doublyLinkedNumbers;

    doublyLinkedNumbers.addFront(10);
    doublyLinkedNumbers.addFront(15);
    doublyLinkedNumbers.addLast(40);

    while (!doublyLinkedNumbers.isEmpty()) {
        cout << doublyLinkedNumbers.removeFront() << endl;
    }

    doublyLinkedNumbers.addFront(10);
    doublyLinkedNumbers.addFront(15);
    doublyLinkedNumbers.addLast(40);

    while (!doublyLinkedNumbers.isEmpty()) {
        cout << doublyLinkedNumbers.removeBack() << endl;
    }


    vector<int> numbers = { 1, 2, 3, 4, 5 };

    SinglyLinkedList<int> stackOfNumbers;

    stackOfNumbers.push(10);
    stackOfNumbers.push(20);
    stackOfNumbers.push(50);

    while (!stackOfNumbers.isEmpty()) {
        cout << stackOfNumbers.pop() << endl;
    }

    numbers.push_back(6);

    // average performance O - O(1) pushback
    // worst case perforamnce O(n)

    int numbersArray[10];

    cout << numbersArray[10] << endl;

    cout << "Hello World!\n";
}
