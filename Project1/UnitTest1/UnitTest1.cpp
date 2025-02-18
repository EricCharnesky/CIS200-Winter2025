#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Unit.h"
#include "../Project1/Infantry.h"
#include "../Project1/Captain.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestUnitAttackWorks)
		{
			// Arrange
			Unit* attacker = new Unit(10, 5, "us", 0, 0);
			Unit* target = new Unit(5, 5, "them", 1, 1);
			int expectedHitPoints = 0;

			// Act
			attacker->attack(target);
			int actualHitPoints = target->getHitPoints();

			// Assert
			Assert::AreEqual(expectedHitPoints, actualHitPoints);

		}

		TEST_METHOD(TestUnitAttackWontAttackOutOfRange)
		{
			// Arrange
			Unit* attacker = new Unit(10, 5, "us", 0, 0);
			Unit* target = new Unit(5, 5, "them", 2, 2);
			int expectedHitPoints = 5;

			// Act
			attacker->attack(target);
			int actualHitPoints = target->getHitPoints();

			// Assert
			Assert::AreEqual(expectedHitPoints, actualHitPoints);

		}

		TEST_METHOD(TestUnitAttackWontAttackSameTeam)
		{
			// Arrange
			Unit* attacker = new Unit(10, 5, "us", 0, 0);
			Unit* target = new Unit(5, 5, "us", 1, 1);
			int expectedHitPoints = 5;

			// Act
			attacker->attack(target);
			int actualHitPoints = target->getHitPoints();

			// Assert
			Assert::AreEqual(expectedHitPoints, actualHitPoints);

		}


		TEST_METHOD(TestInfantryMove)
		{
			// Arrange
			int expectedXPosition = 1;
			int expectedYPosition = 0;
			Infantry* infantry = new Infantry("", 0, 0);

			// Act
			infantry->move(1, 0);
			int actualXPosition = infantry->getXPosition();
			int actualYPosition = infantry->getYPosition();

			// Assert
			Assert::AreEqual(expectedXPosition, actualXPosition);
			Assert::AreEqual(expectedYPosition, actualYPosition);
		}

		TEST_METHOD(TestInfantryWontMoveTooFar)
		{
			// Arrange
			int expectedXPosition = 0;
			int expectedYPosition = 0;
			Infantry* infantry = new Infantry("", 0, 0);
			string actualError = "";
			string expectedError = "Can't move that far";

			// Act
			try {
				infantry->move(10, 0);
			}
			catch (invalid_argument ex) {
				actualError = ex.what();
			}
			
			int actualXPosition = infantry->getXPosition();
			int actualYPosition = infantry->getYPosition();

			// Assert
			Assert::AreEqual(expectedXPosition, actualXPosition);
			Assert::AreEqual(expectedYPosition, actualYPosition);
			Assert::AreEqual(expectedError, actualError);
		}

		TEST_METHOD(TestInfantryWontMoveBothXAndY)
		{
			// Arrange
			int expectedXPosition = 0;
			int expectedYPosition = 0;
			Infantry* infantry = new Infantry("", 0, 0);
			string actualError = "";
			string expectedError = "Can't move both x and y";

			// Act
			try {
				infantry->move(10, 10);
			}
			catch (invalid_argument ex) {
				actualError = ex.what();
			}

			int actualXPosition = infantry->getXPosition();
			int actualYPosition = infantry->getYPosition();

			// Assert
			Assert::AreEqual(expectedXPosition, actualXPosition);
			Assert::AreEqual(expectedYPosition, actualYPosition);
			Assert::AreEqual(expectedError, actualError);
		}

		TEST_METHOD(TestCaptainHeal)
		{
			// Arrange
			Infantry* attacker = new Infantry("them", 0, 0);
			Infantry* target = new Infantry("us", 1, 1);
			Captain* captain = new Captain("us", 2, 2);
			attacker->attack(target);
			int expectedHitPoints = 5;

			// Act
			captain->attack(target);
			int actualHitPoints = target->getHitPoints();

			
			// Assert
			Assert::AreEqual(expectedHitPoints, actualHitPoints);
			
		}
	};
}
