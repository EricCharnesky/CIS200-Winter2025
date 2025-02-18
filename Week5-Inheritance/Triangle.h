#pragma once

#include <math.h>
#include "Polygon.h"

using namespace std;

class Triangle : public Polygon {
private:
public:
	Triangle() : Polygon(3) {

	}

	double getArea() {
		double semiPerimeter = getPerimeter() / 2;
		return sqrt(semiPerimeter
			* (semiPerimeter - getSideLength(0))
			* (semiPerimeter - getSideLength(1))
			* (semiPerimeter - getSideLength(2))
		);

	}
};