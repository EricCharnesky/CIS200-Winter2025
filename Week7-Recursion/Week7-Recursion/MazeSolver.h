#pragma once

#include <vector>

using namespace std;

class MazeSovler {
private:
	vector<vector<char>> maze;
	int numberOfMoves;
	int numberOfMovesUntilSolution;
	string solution;

	bool canGo(int rowIndex, int columnIndex) {
		return !(rowIndex < 0 || rowIndex >= maze.size() ||
			columnIndex < 0 || columnIndex >= maze.at(rowIndex).size() ||
			!( maze.at(rowIndex).at(columnIndex) == ' ' ||
				maze.at(rowIndex).at(columnIndex) == 'E' ) );
	}

	void solve(int rowIndex, int columnIndex) {
		//print();
		//cout << endl;

		// BASE CASE
		if (maze.at(rowIndex).at(columnIndex) == 'E') {
			if (numberOfMoves < numberOfMovesUntilSolution) {
				numberOfMovesUntilSolution = numberOfMoves;
				solution = toString();
			}
		}
		else {
			numberOfMoves++;
			maze.at(rowIndex).at(columnIndex) = '.';

			// up
			if (canGo(rowIndex - 1, columnIndex)) {
				solve(rowIndex - 1, columnIndex);
			}

			// down
			if (canGo(rowIndex + 1, columnIndex)) {
				solve(rowIndex + 1, columnIndex);
			}

			// left
			if (canGo(rowIndex, columnIndex - 1)) {
				solve(rowIndex, columnIndex - 1);
			}

			// right
			if (canGo(rowIndex, columnIndex + 1)) {
				solve(rowIndex, columnIndex + 1);
			}

			// UNDO
			maze.at(rowIndex).at(columnIndex) = ' ';
			numberOfMoves--;
		}
	}

public:
	MazeSovler(vector<vector<char>> maze){
		this->maze = maze;
		numberOfMoves = 0;
		numberOfMovesUntilSolution = INT_MAX;
		solution = "";
	}

	string toString() {
		string result = "";
		for (vector<char> row : maze) {
			for (char space : row) {
				result += space;
			}
			result += '\n';
		}
		return result;
	}

	void solve() {
		// TODO - Find Start
		solve(0, 0);
		if (numberOfMovesUntilSolution < INT_MAX) {
			cout << solution;
			cout << "Solved in " << numberOfMovesUntilSolution << " moves!" << endl;

		}
		else {
			cout << toString() << endl;
			cout << "no solution found!" << endl;
		}
		cout << endl;
	}
};