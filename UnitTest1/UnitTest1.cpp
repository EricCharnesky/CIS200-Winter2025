#include "pch.h"
#include "CppUnitTest.h"
#include "..\Week1OOP\PowerBallTicket.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethodGetWinningsJackpot)
		{
			// Arrange - seting up what we need to test
			int expectedWinnings = 1000000000;
			vector<int> numbers = { 1,2,3,4,5,6 };
			vector<int> winningNumbers = { 5,4,3,2,1,6 };

			PowerBallTicket ticket = PowerBallTicket(numbers);
			PowerBallTicket winningTicket = PowerBallTicket(winningNumbers);

			// Act - calling the code we're testing and getting results
			int actualWinnings = ticket.getWinnings(winningTicket);

			// Assert - did we get what we expect
			Assert::AreEqual(expectedWinnings, actualWinnings);


		}

		TEST_METHOD(TestMethodGetWinningsMillion)
		{
			// Arrange - seting up what we need to test
			int expectedWinnings = 1000000;
			vector<int> numbers = { 1,2,3,4,5,7 };
			vector<int> winningNumbers = { 1,2,3,4,5,6 };

			PowerBallTicket ticket = PowerBallTicket(numbers);
			PowerBallTicket winningTicket = PowerBallTicket(winningNumbers);

			// Act - calling the code we're testing and getting results
			int actualWinnings = ticket.getWinnings(winningTicket);

			// Assert - did we get what we expect
			Assert::AreEqual(expectedWinnings, actualWinnings);
		}

		TEST_METHOD(TestMethodGetWinningsFiftyK)
		{
			// Arrange - seting up what we need to test
			int expectedWinnings = 50000;
			vector<int> numbers = { 1,2,3,4,6,6 };
			vector<int> winningNumbers = { 1,2,3,4,5,6 };

			PowerBallTicket ticket = PowerBallTicket(numbers);
			PowerBallTicket winningTicket = PowerBallTicket(winningNumbers);

			// Act - calling the code we're testing and getting results
			int actualWinnings = ticket.getWinnings(winningTicket);

			// Assert - did we get what we expect
			Assert::AreEqual(expectedWinnings, actualWinnings);
		}

		TEST_METHOD(TestMethodGetWinningsHundred1)
		{
			// Arrange - seting up what we need to test
			int expectedWinnings = 100;
			vector<int> numbers = { 1,2,3,4,6,7 };
			vector<int> winningNumbers = { 1,2,3,4,5,6 };

			PowerBallTicket ticket = PowerBallTicket(numbers);
			PowerBallTicket winningTicket = PowerBallTicket(winningNumbers);

			// Act - calling the code we're testing and getting results
			int actualWinnings = ticket.getWinnings(winningTicket);

			// Assert - did we get what we expect
			Assert::AreEqual(expectedWinnings, actualWinnings);
		}

		TEST_METHOD(TestMethodGetWinningsHundred2)
		{
			// Arrange - seting up what we need to test
			int expectedWinnings = 100;
			vector<int> numbers = { 1,2,3,7,6,6 };
			vector<int> winningNumbers = { 1,2,3,4,5,6 };

			PowerBallTicket ticket = PowerBallTicket(numbers);
			PowerBallTicket winningTicket = PowerBallTicket(winningNumbers);

			// Act - calling the code we're testing and getting results
			int actualWinnings = ticket.getWinnings(winningTicket);

			// Assert - did we get what we expect
			Assert::AreEqual(expectedWinnings, actualWinnings);
		}

		TEST_METHOD(TestMethodGetWinningsSeven1)
		{
			// Arrange - seting up what we need to test
			int expectedWinnings = 7;
			vector<int> numbers = { 1,2,3,7,6,7 };
			vector<int> winningNumbers = { 1,2,3,4,5,6 };

			PowerBallTicket ticket = PowerBallTicket(numbers);
			PowerBallTicket winningTicket = PowerBallTicket(winningNumbers);

			// Act - calling the code we're testing and getting results
			int actualWinnings = ticket.getWinnings(winningTicket);

			// Assert - did we get what we expect
			Assert::AreEqual(expectedWinnings, actualWinnings);
		}

		TEST_METHOD(TestMethodGetWinningsSeven2)
		{
			// Arrange - seting up what we need to test
			int expectedWinnings = 7;
			vector<int> numbers = { 1,2,8,7,6,6 };
			vector<int> winningNumbers = { 1,2,3,4,5,6 };

			PowerBallTicket ticket = PowerBallTicket(numbers);
			PowerBallTicket winningTicket = PowerBallTicket(winningNumbers);

			// Act - calling the code we're testing and getting results
			int actualWinnings = ticket.getWinnings(winningTicket);

			// Assert - did we get what we expect
			Assert::AreEqual(expectedWinnings, actualWinnings);
		}

		TEST_METHOD(TestMethodGetWinningsFour)
		{
			// Arrange - seting up what we need to test
			int expectedWinnings = 4;
			vector<int> numbers = { 10,9,8,7,6,6 };
			vector<int> winningNumbers = { 1,2,3,4,5,6 };

			PowerBallTicket ticket = PowerBallTicket(numbers);
			PowerBallTicket winningTicket = PowerBallTicket(winningNumbers);

			// Act - calling the code we're testing and getting results
			int actualWinnings = ticket.getWinnings(winningTicket);

			// Assert - did we get what we expect
			Assert::AreEqual(expectedWinnings, actualWinnings);
		}

		TEST_METHOD(TestMethodGetWinningsZero)
		{
			// Arrange - seting up what we need to test
			int expectedWinnings = 0;
			vector<int> numbers = { 10,9,8,7,6,5 };
			vector<int> winningNumbers = { 1,2,3,4,5,6 };

			PowerBallTicket ticket = PowerBallTicket(numbers);
			PowerBallTicket winningTicket = PowerBallTicket(winningNumbers);

			// Act - calling the code we're testing and getting results
			int actualWinnings = ticket.getWinnings(winningTicket);

			// Assert - did we get what we expect
			Assert::AreEqual(expectedWinnings, actualWinnings);
		}
	};
}
