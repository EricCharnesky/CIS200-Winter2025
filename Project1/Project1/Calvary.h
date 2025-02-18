#pragma once
#pragma once

#include "Unit.h"

class Calvary : public Unit {
private:
	const static int ATTACK_POWER = 5;
	const static double RANGE = 5;
	const static int HIT_POINTS = 10;
	const static int MAX_MOVE = 10;

public:
	Calvary(string team, int xPosition, int yPosition) : Unit(ATTACK_POWER, HIT_POINTS, team, xPosition, yPosition, RANGE, MAX_MOVE) {

	}

};