#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

class ChecksSolver {

private:
	vector<vector<char>> board;

	int maxNumberOfJumps = 0;
	int currentNumberOfJumps = 0;

	void tryJump(int rowIndex, int columnIndex, int destinationRowIndex, int destinationColumnIndex) {
		int midRowIndex = (rowIndex + destinationRowIndex) / 2;
		int midColumnIndex = (columnIndex + destinationColumnIndex) / 2;
		
		if (destinationRowIndex >= 0 && destinationRowIndex < 8 &&
			destinationColumnIndex >= 0 && destinationColumnIndex < 8 &&
			board.at(midRowIndex).at(midColumnIndex) == 'B' &&
			board.at(destinationRowIndex).at(destinationColumnIndex) == ' ') {

			currentNumberOfJumps++;
			board.at(rowIndex).at(columnIndex) = ' ';
			board.at(midRowIndex).at(midColumnIndex) = ' ';
			board.at(destinationRowIndex).at(destinationColumnIndex) = 'W';
			getMaxJumps(destinationRowIndex, destinationColumnIndex);
			board.at(destinationRowIndex).at(destinationColumnIndex) = ' ';
			board.at(midRowIndex).at(midColumnIndex) = 'B';
			board.at(rowIndex).at(columnIndex) = 'W';
			currentNumberOfJumps--;
		}
	}

	void getMaxJumps(int rowIndex, int columnIndex) {
		if (currentNumberOfJumps > maxNumberOfJumps) {
			maxNumberOfJumps = currentNumberOfJumps;
		}
		
		// top left
		tryJump(rowIndex, columnIndex, rowIndex - 2, columnIndex - 2);
			
		// top right
		tryJump(rowIndex, columnIndex, rowIndex - 2, columnIndex + 2);

		// down left
		tryJump(rowIndex, columnIndex, rowIndex + 2, columnIndex - 2);
	
		// down right
		tryJump(rowIndex, columnIndex, rowIndex + 2, columnIndex + 2);
	}

public:

	ChecksSolver(vector<vector<char>> board) {
		if (board.size() != 8) {
			throw invalid_argument("invalid board size");
		}
		for (int index = 0; index < board.size(); index++) {
			if (board.at(index).size() != 8) {
				throw invalid_argument("invalid board size");
			}
		}

		bool piecesOnEven = false;
		bool piecesOnOdd = false;

		for (int rowIndex = 0; rowIndex < 8; rowIndex++) {
			for (int columnIndex = 0; columnIndex < 8; columnIndex++) {
				if (board.at(rowIndex).at(columnIndex) != ' ') {
					if ((rowIndex + columnIndex) % 2 == 0) {
						piecesOnEven = true;
					}
					else {
						piecesOnOdd = true;
					}
				}
			}
		}

		if (piecesOnEven && piecesOnOdd) {
			throw invalid_argument("invalid pieces on board");
		}

		this->board = board;
	}

	int getMaxJumps() {
		for (int rowIndex = 0; rowIndex < 8; rowIndex++) {
			for (int columnIndex = 0; columnIndex < 8; columnIndex++) {
				if (board.at(rowIndex).at(columnIndex) == 'W') {
					getMaxJumps(rowIndex, columnIndex);
				}
			}
		}

		return maxNumberOfJumps;
	}
};