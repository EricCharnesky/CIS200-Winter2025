#pragma once

#include <stdexcept>

using namespace std;

class Rectangle {
private:
	int height;
	int width;
public:
	Rectangle(int height, int width) {
		setHeight(height);
		setWidth(width);
	}

	virtual void setWidth(int width) {
		if (width < 0) {
			throw invalid_argument("can't be negative");
		}
		this->width = width;
	}

	virtual void setHeight(int height) {
		if (height < 0) {
			throw invalid_argument("can't be negative");
		}
		this->height = height;
	}

	int getHeight() {
		return height;
	}

	int getWidth() {
		return width;
	}

	int getPerimeter() {
		return (height + width) * 2;
	}

	int getArea() {
		return height * width;
	}

};