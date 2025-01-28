using namespace std;

#include <iostream>
#include <iomanip>
#include <locale>
#include <format> // C++20

#include "PowerBallTicket.h"

int main()
{
	// TESTING WITHOUT VISUAL STUDIO

	// Arrange - seting up what we need to test
	int expectedWinnings = 1000000000;
	vector<int> numbers = { 1,2,3,4,5,6 };
	vector<int> winningNumbers = { 1,2,3,4,5,6 };

	PowerBallTicket ticket = PowerBallTicket(numbers);
	PowerBallTicket winningTicketTest = PowerBallTicket(winningNumbers);

	// Act - calling the code we're testing and getting results
	int actualWinnings = ticket.getWinnings(winningTicketTest);

	// Assert - did we get what we expect
	if (expectedWinnings == actualWinnings) {
		cout << "Jackpot test PASSES" << endl;
	}
	else {
		cout << "Jackpot test FAILS" << endl;
	}






	cout << "Hello World!" << endl;

	PowerBallTicket winningTicket;

	cout << winningTicket.toString() << endl;

	//vector<int> luckyNumbers = { 1, 2, 3, 4, 5, 6 };

	//PowerBallTicket luckyTicket(luckyNumbers);

	//cout << luckyTicket.toString() << endl;

	
	


	int tickets;
	cout << "How many tickets do you want to buy?" << endl;
	cin >> tickets;

	int totalSpent = tickets * 2;
	int totalWon = 0;

	for (int ticket = 0; ticket < tickets; ticket++) {
		PowerBallTicket newTicket;
		//cout << newTicket.toString() << endl;
		totalWon += newTicket.getWinnings(winningTicket);

	}
	// used UMGPT
	// prompt: how do you make output in c++ have digit seperators and no decimals
	// prompt: use the C++11 introduced a new feature called the thousands separator,

	// Use std::locale to specify the locale with digit separator
	//std::locale::global(std::locale("en_US.UTF-8"));
	//std::cout.imbue(std::locale());

	// Print number with thousands separator
	//std::cout << std::format("{:L}", number) << std::endl;


	cout << "You spent $" << totalSpent << endl;
	cout << "You won $" << totalWon << endl;
	cout << "Your net loss is $" << totalWon - totalSpent << endl;

	return 0;
}
