#pragma once

#include "Rectangle.h"

class Square : public Rectangle {
private:

public:
	Square(int width) : Rectangle(width, width) {

	}

	void setWidth(int width) override {
		Rectangle::setHeight(width);
		Rectangle::setWidth(width);
	}

	void setHeight(int height) override {
		Rectangle::setHeight(height);
		Rectangle::setWidth(height);
	}
};