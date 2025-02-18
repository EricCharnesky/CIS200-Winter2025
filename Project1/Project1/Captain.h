#pragma once

#include "Infantry.h"

class Captain : public Infantry{
private:
	const static int ATTACK_POWER = 1;
	const static int HIT_POINTS = 20;
public:

	Captain(string team, int xPosition, int yPositon) : Infantry(team, xPosition, yPositon) {
		hitPoints = HIT_POINTS;
		maxHitPoints = HIT_POINTS;
	}

	void attack(Unit* target) {
		if (isWithinRange(target) && target->getTeam() == getTeam()) {
			target->takeDamage(target->getMaxHitPoints() * -1);
		}
	}

};