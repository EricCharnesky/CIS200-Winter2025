#pragma once

#include <vector>

using namespace std;

class MazeSovler {
private:
	vector<vector<char>> maze;

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
			print();
		}
		else {
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
		}
	}

public:
	MazeSovler(vector<vector<char>> maze){
		this->maze = maze;
	}

	void print() {
		for (vector<char> row : maze) {
			for (char space : row) {
				cout << space;
			}
			cout << endl;
		}
	}

	void solve() {
		// TODO - Find Start
		solve(0, 0);
	}
};