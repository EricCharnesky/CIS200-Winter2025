#pragma once
#include <stdexcept>

using namespace std;

class Rectangle {
private:
	int length;
	int width;
public:
	Rectangle(int length = 0, int width = 0) {
		setLength(length);
		setWidth(width);
	}

	void setLength(int length) {
		if (length < 0) {
			throw invalid_argument("length can't be less than 0");
		}
		this->length = length;
	}

	void setWidth(int width) {
		if (width < 0) {
			throw invalid_argument("width can't be less than 0");
		}
		this->width = width;
	}

	int getLength() {
		return this->length;
	}

	int getWidth() {
		return this->width;
	}


};