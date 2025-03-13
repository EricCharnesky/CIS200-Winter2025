#include "pch.h"
#include "CppUnitTest.h"

#include "..\Project2\CheckersSolver.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethodChecksSolver)
		{
			// Arrange
			vector<vector<char>> board = {
				{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				{ ' ', 'B', ' ', 'B', ' ', 'B', ' ', ' '},
				{ ' ', ' ', ' ', ' ', 'W', ' ', 'W', ' '},
				{ ' ', 'B', ' ', 'B', ' ', 'B', ' ', ' '},
				{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
				{ ' ', ' ', ' ', ' ', ' ', 'B', ' ', ' '},
				{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
			};

			ChecksSolver sovler(board);
			int expectedMaxJumps = 6;

			// Act
			int actualMaxJumps = sovler.getMaxJumps();

			// Assert
			Assert::AreEqual(expectedMaxJumps, actualMaxJumps);

		}
	};
}
