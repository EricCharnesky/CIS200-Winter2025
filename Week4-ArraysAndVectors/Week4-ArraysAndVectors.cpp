

#include <iostream>
#include <vector>

#include "TicTacToe.h"

using namespace std;

int main()
{

    vector<string> classes = {  };

    string input = "";

    auto number = 42;

    while (input != "quit") {
        cout << "Enter a class or quit" << endl;
        cin >> input;
        if (input != "quit") {
            classes.push_back(input);
        }
    }

    
    // read only
    for (string course : classes) {
        cout << course << endl;
    }

    // can modify what's stored at the given index
    for (int index = 0; index < classes.size(); index++) {
        cout << classes[index] << endl;
    }

    

    //for (vector<string>::iterator it = classes.begin(); it != classes.end(); it++) {
    for (auto it = classes.begin(); it != classes.end(); it++) {
        cout << *it << endl;
        
        // can assign to the value pointed at by the iterator
        // *it = "test";
    }

    cout << "What do you want to drop?" << endl;

    cin >> input;
   
    vector<string>::iterator iteratorToErase;
    for (auto it = classes.begin(); it != classes.end(); it++) {
        if (input == *it) {
            iteratorToErase = it;
        }

        // can assign to the value pointed at by the iterator
        // *it = "test";
    }

    classes.erase(iteratorToErase);

    for (string course : classes) {
        cout << course << endl;
    }


    /*int randomIndex = rand() % classes.size();

    cout << "Class today: " << classes.at(randomIndex) << endl;

    classes.pop_back();

    randomIndex = rand() % classes.size();

    cout << "Class today: " << classes.at(randomIndex) << endl;*/






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
