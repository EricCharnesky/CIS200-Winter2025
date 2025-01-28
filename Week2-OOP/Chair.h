#include <string>

using namespace std;

#pragma once
class Chair {

private:
	string color;
	int heightInCM;

public:
	Chair(string color, int heightInCM) {
		this->color = color;
		setHeightInCM(heightInCM);
	}

	/*
	*
	* um gpt
	write get and set methods for the attributes of this class

class Chair {

private:
	string color;
	int heightInCM;

public:
	Chair(string color, int heightInCM) {
		this->color = color;
		this->heightInCM = heightInCM;
	}
	*/

	string getColor() const {
		return color;
	}

	void setColor(const string& newColor) {
		color = newColor;
	}

	int getHeightInCM() const {
		return heightInCM;
	}

	void setHeightInCM(int newHeightInCM) {
		if (newHeightInCM < 0) {
			throw invalid_argument("height can't be negative");
		}
		heightInCM = newHeightInCM;
	}
};

bool operator==(const Chair& lhs, const Chair& rhs) {
	return (lhs.getHeightInCM() == rhs.getHeightInCM()) &&
		(lhs.getColor() == rhs.getColor());
}

bool operator!=(const Chair& lhs, const Chair& rhs) {
	return !(lhs == rhs);
}

bool operator<(const Chair& lhs, const Chair& rhs) {
	return lhs.getHeightInCM() < rhs.getHeightInCM();
}

bool operator<=(const Chair& lhs, const Chair& rhs) {
	return lhs.getHeightInCM() <= rhs.getHeightInCM();
}

// consider being lazy, not <= means it is >
bool operator>(const Chair& lhs, const Chair& rhs) {
	return lhs.getHeightInCM() > rhs.getHeightInCM();
}

bool operator>=(const Chair& lhs, const Chair& rhs) {
	return lhs.getHeightInCM() >= rhs.getHeightInCM();
}



