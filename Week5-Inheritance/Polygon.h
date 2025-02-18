#pragma once

#include <string>
#include <stdexcept>

using namespace std;

class Polygon {
private:
	double* sideLengths;
	int numberOfSides;

	void checkIndex(int sideIndex)
	{
		if (sideIndex < 0 || sideIndex >= numberOfSides) {
			throw invalid_argument("Invalid index");
		}
	}

public:
	Polygon(int numberOfSides) {
		this->numberOfSides = numberOfSides;
		sideLengths = new double[numberOfSides];
	}

	~Polygon() {
		delete[] sideLengths;
	}

	int getNumberOfSides() {
		return numberOfSides;
	}

	double getSideLength(int sideIndex) {
		checkIndex(sideIndex);
		return sideLengths[sideIndex];
	}

	virtual void setSideLength(int sideIndex, double sideLength) {
		checkIndex(sideIndex);
		if (sideLength < 0) {
			throw invalid_argument("Length can not be negative");
		}
		sideLengths[sideIndex] = sideLength;
	}

	double getPerimeter() {
		double perimeter = 0;
		for (int index = 0; index < numberOfSides; index++) {
			perimeter += sideLengths[index];
		}
		return perimeter;
	}

	// doesn't have an implementation
	virtual double getArea() = 0;

	// TODO Add copy constructor and copy assignment operator
};