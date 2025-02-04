
#include <iostream>
#include "Square.h"

using namespace std;

void printRectangleDetails(Rectangle* rectangle) {

    rectangle->setHeight(1);
    cout << "Area: " << rectangle->getArea() << endl;
    cout << "Perimeter: " << rectangle->getPerimeter() << endl;
}

int main()
{
    cout << "Hello World!\n";

    Square* smallSquare = new Square(5);

    Rectangle* largeRectangle = new Rectangle(10, 20);

    printRectangleDetails(largeRectangle);
    printRectangleDetails(smallSquare);
}
