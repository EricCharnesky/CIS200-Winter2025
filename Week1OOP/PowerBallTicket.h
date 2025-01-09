#pragma once

using namespace std;

#include <vector>
#include <string>

class PowerBallTicket {

private:
	vector<int> numbers;

public:

	PowerBallTicket() {
		while (numbers.size() < 5) {
			int random_number = rand() % 69 + 1;
			for (int number : numbers) {
				if (random_number == number) {
					continue;
				}
			}
			numbers.push_back(random_number);
		}

		numbers.push_back(rand() % 26 + 1);
	}

	PowerBallTicket(vector<int> numbers) {
		this->numbers = numbers;
		// TODO - make sure these are valid
	}

	vector<int> getNumbers() {
		return numbers;
	}

	string toString() {
		string toReturn = "";
		for (int number : numbers) {
			toReturn = toReturn + to_string(number) + " ";
		}
		return toReturn;
	}

	int getWinnings(PowerBallTicket winningTicket) {
		int whiteMatches = 0;

		for (int index = 0; index < 5; index++) {
			for (int winningIndex = 0; winningIndex < 5; winningIndex++) {
				if (numbers.at(index) == winningTicket.getNumbers().at(winningIndex)) {
					whiteMatches++;
					break;
				}	
			}
		}

		bool redMatches = numbers.at(5) == winningTicket.getNumbers().at(5);

		if (whiteMatches == 5 && redMatches) {
			return 1000000000;
		}
		if (whiteMatches == 5) {
			return 1000000;
		}
		if (whiteMatches == 4 && redMatches) {
			return 50000;
		}
		if (whiteMatches == 4 || (whiteMatches == 3 && redMatches)) {
			return 100;
		}
		if (whiteMatches == 3 || (whiteMatches == 2 && redMatches)) {
			return 7;
		}
		if (redMatches) {
			return 4;
		}
		return 0;
	}

};