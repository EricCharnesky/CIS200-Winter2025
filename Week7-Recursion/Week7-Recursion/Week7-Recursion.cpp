
#include <iostream>
#include <vector>

#include "MazeSolver.h"

using namespace std;

void countDownIterative(int number) {
    for (int current = number; current > 0; current--) {
        cout << number << endl;
    }
    cout << "Blastoff!" << endl;
}

void countDown(int number) {
    if (number <= 0) {
        cout << "Blastoff!" << endl;
    }
    else {
        cout << number << endl;
        countDown(number - 1);
    }
    
}

int iterativeFib(int nth) {
    // BASE CASE
    if (nth == 0 || nth == 1) {
        return nth;
    }

    int currentNth = 1;
    int previous = 0;
    int current = 1;

    while (currentNth < nth) {
        int next = previous + current;
        previous = current;
        current = next;
        currentNth++;
    }

    return current;
}

// woudl be nice as a private function
int helperRecursiveFib(int currentNth, int nth, int previous, int current) {
    // BASE CASE
    if (currentNth == nth) {
        return current;
    }
    return helperRecursiveFib(currentNth + 1, nth, current, previous + current);
}

// not recursive itself, it's helper function is
int betterRecursiveFib(int nth) {
    // BASE CASE
    if (nth == 0 || nth == 1) {
        return nth;
    }

    return helperRecursiveFib(1, nth, 0, 1);
}

int badFib(int nth) {
    // BASE CASE
    if (nth == 0 || nth == 1) {
        return nth;
    }

    return badFib(nth - 1) + badFib(nth - 2);
}

char mazeSpace() {
    if (rand() % 3 == 0) {
        return 'X';
    }
    else {
        return ' ';
    }
}

int main()
{
    vector<vector<char>> maze = {
        { 'S', 'X', 'X', 'X', ' ' },
        { ' ', ' ', ' ', ' ', ' ' },
        { ' ', 'X', ' ', 'X', ' ' },
        { ' ', 'X', ' ', 'X', 'E' },
        { ' ', 'X', ' ', ' ', ' ' },

    };

   

    

    for (int number = 0; number < 10; number++) {
        

        maze = vector<vector<char>>();
        int rows = rand() % 7 + 4;
        int columns = rand() % 7 + 4;

        for (int rowIndex = 0; rowIndex < rows; rowIndex++ ) {
            maze.push_back(vector<char>());
            for (int columnIndex = 0; columnIndex < columns; columnIndex++ ) {
                maze.at(rowIndex).push_back(mazeSpace());
            }
        }

        maze.at(0).at(0) = 'S';
        maze.at(rows - 1).at(columns - 1) = 'E';

        MazeSovler solver(maze);
        solver.solve();
   }
}
