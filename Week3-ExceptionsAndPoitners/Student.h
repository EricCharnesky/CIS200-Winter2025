
#pragma once

#include <string>
#include "Assignment.h"

using namespace std;

class Student {
private:
	Assignment* assignemnts;
	string name;
	int currentNumberOfAssignemnts;
	int MAX_NUMBER_OF_ASSIGNMENTS = 5;
public:

	Student() {
		assignemnts = new Assignment[MAX_NUMBER_OF_ASSIGNMENTS];
		currentNumberOfAssignemnts = 0;
		name = "";
	}

	Student(const Student& student) {
		assignemnts = new Assignment[MAX_NUMBER_OF_ASSIGNMENTS];
		currentNumberOfAssignemnts = student.currentNumberOfAssignemnts;
		name = student.name;

		Assignment* assignmentsToCopy = student.assignemnts;
		for (int index = 0; index < MAX_NUMBER_OF_ASSIGNMENTS; index++) {
			assignemnts[index] = assignmentsToCopy[index];
		}
	}

	Student& operator=(const Student& student) {
		if (this != &student) {
			delete[] assignemnts;
			currentNumberOfAssignemnts = student.currentNumberOfAssignemnts;
			name = student.name;

			assignemnts = new Assignment[MAX_NUMBER_OF_ASSIGNMENTS];

			Assignment* assignmentsToCopy = student.assignemnts;
			for (int index = 0; index < MAX_NUMBER_OF_ASSIGNMENTS; index++) {
				assignemnts[index] = assignmentsToCopy[index];
			}
		}

		return *this;
	}

	// destructor
	~Student() {
		delete[] assignemnts;
	}

	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return name;
	}

	Assignment* getAssignements() {
		return assignemnts;
	}

	void addAssignemnt(Assignment& assignment) {
		if (currentNumberOfAssignemnts < MAX_NUMBER_OF_ASSIGNMENTS) {
			assignemnts[currentNumberOfAssignemnts] = assignment;
			currentNumberOfAssignemnts++;
		}
	}

};