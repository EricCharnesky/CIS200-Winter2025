#pragma once

#include <string>

using namespace std;

class Assignment {
private:
	int maxScore;
	int score;
	string name;

public:

	// UMGPT
	// please generate set and get functions for this class
	/*class Assignment {
	private:
		int maxScore;
		int score;
		string name;

	public:

	};*/

    int getMaxScore() const {
        return maxScore;
    }

    void setMaxScore(int maxScore) {
        this->maxScore = maxScore;
    }

    int getScore() const {
        return score;
    }

    void setScore(int score) {
        this->score = score;
    }
   
    string getName() const {
        return name;
    }

    void setName(const string& name) {
        this->name = name;
    }


};