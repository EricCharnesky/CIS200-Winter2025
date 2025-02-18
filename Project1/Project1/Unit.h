#pragma once

#include <string>
#include <cmath>

using namespace std;

class Unit {
private:
	int attackPower;
	
	double range;
	string team;

    bool shouldAttack(Unit* target) {
        return team == "choatic" ||
            (team == "us" && target->getTeam() == "them") ||
            (team == "them" && target->getTeam() == "us");
    }

protected:
    // to allow captain to change
    int hitPoints;
    int maxHitPoints;

    int	xPosition;
    int yPosition;
    int maxMove;

    bool isWithinRange(Unit* target) {
        return range >= sqrt(
            pow((xPosition - target->getXPosition()), 2) +
            pow((yPosition - target->getYPosition()), 2));
    }

public:
    Unit(int attackPower, int hitPoints, string team, int xPosition, int yPosition, double range = sqrt(2), int maxMove = 0) {
        this->attackPower = attackPower;
        this->hitPoints = hitPoints;
        maxHitPoints = hitPoints;
        this->team = team;
        this->xPosition = xPosition;
        this->yPosition = yPosition;
        this->range = range;
        this->maxMove = maxMove;
    }

    void takeDamage(int damage) {
        hitPoints -= damage;
        if (hitPoints < 0) {
            hitPoints = 0;
        }
        else if (hitPoints > maxHitPoints) {
            hitPoints = maxHitPoints;
        }
    }

	bool isAlive() {
		return hitPoints != 0;
	}

	virtual void attack(Unit* target) {
        if (isWithinRange(target) && shouldAttack(target)) {
            target->takeDamage(attackPower);
        }
	}

	virtual void move(int x, int y) {
        if (x != 0 && y != 0) {
            throw invalid_argument("Can't move both x and y");
        }
        if (abs(x) > maxMove || abs(y) > maxMove ) {
            throw invalid_argument("Can't move that far");
        }
        // with protected access
        xPosition += x;
        yPosition += y;
	}

	// umgpt prompt: write get functions for this class
    int getAttackPower() const {
        return attackPower;
    }

    int getHitPoints() const {
        return hitPoints;
    }

    int getMaxHitPoints() const {
        return maxHitPoints;
    }

    double getRange() const {
        return range;
    }

    int getXPosition() const {
        return xPosition;
    }

    int getYPosition() const {
        return yPosition;
    }

    string getTeam() const {
        return team;
    }
};