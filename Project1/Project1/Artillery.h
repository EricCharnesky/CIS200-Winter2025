#pragma once

#pragma once

#include "Unit.h"
#include <stdexcept>

class Artillery : public Unit {
private:
	const static int ATTACK_POWER = 10;
	const static double RANGE = 10.0;
	const static int HIT_POINTS = 1;
	const static int MAX_MOVE = 1;

public:
	Artillery(string team, int xPosition, int yPosition) : Unit(ATTACK_POWER, HIT_POINTS, team, xPosition, yPosition, RANGE, MAX_MOVE) {

	}

};