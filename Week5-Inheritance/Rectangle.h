#pragma once

#include <stdexcept>
#include "Polygon.h"

using namespace std;

class Rectangle : public Polygon {
private:

public:
	Rectangle(int height, int width) : Polygon(4) {
		setHeight(height);
		setWidth(width);
	}

	virtual void setWidth(int width) {
		if (width < 0) {
			throw invalid_argument("can't be negative");
		}
		setSideLength(0, width);
	}

	virtual void setHeight(int height) {
		if (height < 0) {
			throw invalid_argument("can't be negative");
		}
		setSideLength(1, height);
	}

	int getHeight() {
		return getSideLength(1);
	}

	int getWidth() {
		return getSideLength(0);
	}

	void setSideLength(int sideIndex, double sideLength) override {
		if (sideIndex == 0 || sideIndex == 2) {
			Polygon::setSideLength(0, sideLength);
			Polygon::setSideLength(2, sideLength);
		}
		else{
			Polygon::setSideLength(1, sideLength);
			Polygon::setSideLength(3, sideLength);
		}
	}

	double getArea() override {
		return getSideLength(0) * getSideLength(1);
	}

};