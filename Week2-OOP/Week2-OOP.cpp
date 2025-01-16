
#include <iostream>

#include "Chair.h"

int main()
{
    std::cout << "Hello World!\n";

    Chair ericsChair("Red", 50);
    Chair bobsChair("blue", 50);
    Chair matchingChair("Red", 50);

    if (ericsChair == bobsChair) {
        cout << "Equal!" << endl;
    }
    else {
        cout << "not Equal!" << endl;
    }

    if (ericsChair == matchingChair) {
        cout << "Equal!" << endl;
    }
    else {
        cout << "not Equal!" << endl;
    }
}
