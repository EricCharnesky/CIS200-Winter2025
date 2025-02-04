#pragma once

#include <string>
#include <stdexcept>
#include "FightingPet.h"


using namespace std;

class Trainer {

private:
	string name;
	int level;
	int experiencePoints;
	int maxNumberOfFightingPets;
	int currentNumberOfFightingPets;
	FightingPet* fightingPets;
public:
	Trainer() {
		name = "";
		level = 1;
		experiencePoints = 0;
		maxNumberOfFightingPets = 5;
		currentNumberOfFightingPets = 0;
		fightingPets = new FightingPet[maxNumberOfFightingPets];
	}

	~Trainer() {
		delete[] fightingPets;
	}

	Trainer(const Trainer& trainer) {
		name = trainer.name;
		level = trainer.level;
		experiencePoints = trainer.experiencePoints;
		maxNumberOfFightingPets = trainer.maxNumberOfFightingPets;
		currentNumberOfFightingPets = trainer.currentNumberOfFightingPets;

		fightingPets = new FightingPet[maxNumberOfFightingPets];
		for (int index = 0; index < currentNumberOfFightingPets; index++) {
			fightingPets[index] = trainer.fightingPets[index];
		}
	}

	Trainer& operator=(const Trainer& trainer) {
		if (this != &trainer) {
			name = trainer.name;
			level = trainer.level;
			experiencePoints = trainer.experiencePoints;
			maxNumberOfFightingPets = trainer.maxNumberOfFightingPets;
			currentNumberOfFightingPets = trainer.currentNumberOfFightingPets;

			delete[] fightingPets;

			fightingPets = new FightingPet[maxNumberOfFightingPets];
			for (int index = 0; index < currentNumberOfFightingPets; index++) {
				fightingPets[index] = trainer.fightingPets[index];
			}
		}

		return *this;
	}

	FightingPet& getFightingPet(int index) {
		if (index < 0 || index >= currentNumberOfFightingPets) {
			invalid_argument("invalid index");
		}
		return fightingPets[index];
	}

	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return name;
	}

	int getCurrentNumberOfFightingPets() {
		return currentNumberOfFightingPets;
	}

	void setMaxNumberOfFightingPets(int maxNumberOfFightingPets) {
		this->maxNumberOfFightingPets = maxNumberOfFightingPets;
	}

	int getMaxNumberOfFightingPets() {
		return maxNumberOfFightingPets;
	}

	int getLevel() {
		return level;
	}

	int getExperiencePoints() {
		return experiencePoints;
	}

	void addExperiencePoints(int experiencePoints) {
		this->experiencePoints += experiencePoints;
		if (this->experiencePoints > level * 1000) {
			level++;
			experiencePoints = 0;
		}
	}

	void addFightingPet(FightingPet& fightingPet) {
		if (currentNumberOfFightingPets == maxNumberOfFightingPets) {
			throw invalid_argument("Can't have more pets");
		}
		fightingPets[currentNumberOfFightingPets] = fightingPet;
		currentNumberOfFightingPets++;
	}

	void addMoreFightingPetStorage() {
		maxNumberOfFightingPets *= 2;
		FightingPet* newFightingPets = new FightingPet[maxNumberOfFightingPets];
		for (int index = 0; index < currentNumberOfFightingPets; index++) {
			newFightingPets[index] = fightingPets[index];
		}

		delete[] fightingPets;
		fightingPets = newFightingPets;
	}
};