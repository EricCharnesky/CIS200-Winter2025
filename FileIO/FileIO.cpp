

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    string filename;

    cout << "Enter the name of your shopping list" << endl;

    cin >> filename;

    ifstream inputFileStream;

    inputFileStream.open(filename);
    if (!inputFileStream.is_open()) {
        cout << "Could not open file" << endl;
        return 1; // 1 indicates error
    }

    vector<string> items;

    string fileContents;

    
    getline(inputFileStream, fileContents);
    
    while (!inputFileStream.fail()) {
        
        items.push_back(fileContents);
        getline(inputFileStream, fileContents);
    }
    if (!inputFileStream.eof()) {
        cout << "Input failure before reaching end of file." << endl;
    }

    

    // Done with file, so close it
    inputFileStream.close();


    cout << "Current items in list: " << endl;
    for (string item : items) {
        cout << item << endl;
    }

    string item;

    cout << "Enter the name of an item to add or QUIT: " << endl;
    cin >> item;

    ofstream outputFileStream;

    while (item != "QUIT") {
        outputFileStream.open(filename, ios_base::app);
        outputFileStream << item << endl;

        cout << "Enter the name of an item to add or QUIT: " << endl;
        cin >> item;

    }

}
