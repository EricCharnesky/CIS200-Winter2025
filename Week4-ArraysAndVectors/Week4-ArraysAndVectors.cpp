

#include <iostream>
#include <vector>

#include "TicTacToe.h"

using namespace std;

int main()
{
    TicTacToe game;
    int row;
    int column;

    while (!game.isGameOver()) {
        cout << game.display() << endl;
        cout << game.getCurrentPlayer() << "'s turn." << endl;
        cout << "Enter a row index and a column index to mark " << endl;
        cin >> row >> column;
        try {
            game.markBoard(row, column);
        }
        catch (invalid_argument ex) {
            cout << ex.what() << endl;
        }
        
    }
    cout << "Game over!" << endl;
    cout << game.display() << endl;

}
