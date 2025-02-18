
#include <iostream>
#include "Square.h"
#include "Triangle.h"

using namespace std;

void printPolygonDetails(Polygon* polygon) {

    polygon->setSideLength(1, 1);
    cout << "Area: " << polygon->getArea() << endl;
    cout << "Perimeter: " << polygon->getPerimeter() << endl;
}

int main()
{
    cout << "Hello World!\n";

    Square* smallSquare = new Square(5);

    Rectangle* largeRectangle = new Rectangle(10, 20);

    printPolygonDetails(largeRectangle);
    printPolygonDetails(smallSquare);

    // arrange
    Triangle* triangle = new Triangle();
    triangle->setSideLength(0, 3);
    triangle->setSideLength(1, 4);
    triangle->setSideLength(2, 5);
    double expectedArea = 6;

    // act
    cout << "Area of our 3,4,5 triangle is: " << triangle->getArea() << endl;
    printPolygonDetails(triangle);
    double actualArea = triangle->getArea();

    // assert
    if (expectedArea != actualArea) {
        cout << "TEST FAILED - area doesn't match" << endl;
    }
}
