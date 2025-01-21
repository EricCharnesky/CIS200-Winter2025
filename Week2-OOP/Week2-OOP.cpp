
#include <iostream>

#include "Chair.h"

int main()
{
    std::cout << "Hello World!\n";

    Chair ericsChair("Red", 50);
    Chair bobsChair("blue", 50);
    Chair matchingChair("Red", 50);

    // meh
    while (true) {

        cout << "Enter the hight in cm for Eric's chair" << endl;
        int height;
        cin >> height;

        try {
            ericsChair.setHeightInCM(height);
            break;
        }
        catch (const invalid_argument& ex) {
            cout << ex.what() << endl;
        }
        catch (const runtime_error ex) {
            cout << ex.what() << endl;
        }
    }
   


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
