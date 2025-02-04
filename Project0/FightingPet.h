#pragma once

#include <string>

using namespace std;

class FightingPet {
private:
	string name;
	int number;
	int combatPower;

public:
	// umgpt
	// prompt:
	// please write set and get functions for this class
	/* class FightingPet {
	private:
		string name;
		int number;
		int combatPower;

	public:

	};*/

    FightingPet(int number = 0, string name = "", int combatPower = 0) {
        this->name = name;
        this->number = number;
        this->combatPower = combatPower;
    }

    void setName(const std::string& newName) {
        name = newName;
    }

    void setCombatPower(int newCombatPower) {
        combatPower = newCombatPower;
    }

    string getName() const {
        return name;
    }

    void setNumber(int number) {
        this->number = number;
    }

    int getNumber() const {
        return number;
    }

    int getCombatPower() const {
        return combatPower;
    }

};