#pragma once

#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class TicTacToe {
private:
	vector<vector<char>> board;
	char currentPlayer;

	bool isTied() {
		// assuming there isn't a winner, that's someone else's problem to check
		for (vector<char> row : board) {
			for (char space : row) {
				if (space == ' ') {
					return false;
				}
			}
		}
		return true;
	}

	bool hasWinnerByDiagonal() {
		return board[1][1] != ' '
			&& ( (board[0][0] == board[1][1] && board[0][0] == board[2][2])
			|| (board[0][2] == board[1][1] && board[0][2] == board[2][0]) );
			
	}

	bool hasWinnerByColumn() {
		for (int columnIndex = 0; columnIndex < 3; columnIndex++ ) {
			if (board[0][columnIndex] != ' ' && board[0][columnIndex] == board[1][columnIndex] && board[0][columnIndex] == board[2][columnIndex]) {
				return true; 
			}
		}
		return false;
	}

	bool hasWinnerByRow() {
		for (vector<char> row : board) {
			if (row[0] != ' ' && row[0] == row[1] && row[0] == row[2]) {
				return true;
			}
		}
		return false;
	}

	bool hasWinner() {
		return hasWinnerByRow() || hasWinnerByColumn() || hasWinnerByDiagonal();
	}

public:
	TicTacToe() {
		board = vector<vector<char>>();
		for (int rowNumber = 0; rowNumber < 3; rowNumber++) {
			vector<char> row = { ' ', ' ', ' ' };
			board.push_back(row);
		}
		currentPlayer = 'X';
	}

	bool isGameOver() {
		return hasWinner() || isTied();
	}

	string display() {
		string result = "";
		result += string(1, board[0][0]) + "|" + string(1, board[0][1]) + "|" + string(1, board[0][2]) + "\n";
		result += "-----\n";
		result += string(1, board[1][0]) + "|" + string(1, board[1][1]) + "|" + string(1, board[1][2]) + "\n";
		result += "-----\n";
		result += string(1, board[2][0]) + "|" + string(1, board[2][1]) + "|" + string(1, board[2][2]) + "\n";
		return result;
	}

	void markBoard(int rowIndex, int columnIndex) {
		if (isGameOver()) {
			throw invalid_argument("game is over!");
		}

		// vector already checks for 'valid' index and will throw
		if (board[rowIndex][columnIndex] != ' ') {
			throw invalid_argument("space not empty!");
		}
		board[rowIndex][columnIndex] = currentPlayer;

		// WAT
		//currentPlayer = 'X' ? currentPlayer == 'O' : 'O';

		if (currentPlayer == 'X') {
			currentPlayer = 'O';
		}
		else {
			currentPlayer = 'X';
		}
	}

	char getCurrentPlayer() {
		return currentPlayer;
	}

};