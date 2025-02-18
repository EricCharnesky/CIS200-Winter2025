#pragma once

#pragma once

#include "Unit.h"
#include <stdexcept>

class Infantry : public Unit {
private:
	const static int ATTACK_POWER = 5;
	const static int HIT_POINTS = 5;
	const static int MAX_MOVE = 5;

public:
	Infantry(string team, int xPosition, int yPosition) : Unit(ATTACK_POWER, HIT_POINTS, team, xPosition, yPosition, sqrt(2), MAX_MOVE) {

	}

};