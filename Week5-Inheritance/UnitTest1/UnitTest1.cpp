#include "pch.h"
#include "CppUnitTest.h"
#include "../Triangle.h"
#include "../Rectangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		// naming the function to what it's testing
		TEST_METHOD(TestTriangleArea)
		{
			// Arrange - setup all the variable we need for testing
			double expectedArea = 6;
			Triangle triangle;
			triangle.setSideLength(0, 3);
			triangle.setSideLength(1, 4);
			triangle.setSideLength(2, 5);

			// Act - call the code we're testing
			double actualArea = triangle.getArea();

			// Assert - did we get what we expected
			Assert::AreEqual(expectedArea, actualArea);


		}

		TEST_METHOD(TestRectangleSetWidthNegativeThrows)
		{
			// Arrange - setup all the variable we need for testing
			Rectangle rectangle(10, 4);
			string expectedError = "can't be negative";
			string actcualError = "";

			// Act - call the code we're testing
			try {
				rectangle.setWidth(-5);
			}
			catch (invalid_argument ex) {
				actcualError = ex.what();
			}
			

			// Assert - did we get what we expected
			Assert::AreEqual(expectedError, actcualError);


		}

		TEST_METHOD(TestRectangleSetWidthSetsBothSides)
		{
			// Arrange - setup all the variable we need for testing
			Rectangle rectangle(10, 4);
			double expectedWidth = 5;

			// Act - call the code we're testing
			rectangle.setWidth(expectedWidth);
			double actualSide0 = rectangle.getSideLength(0);
			double actualSide2 = rectangle.getSideLength(2);


			// Assert - did we get what we expected
			Assert::AreEqual(expectedWidth, actualSide0);
			Assert::AreEqual(expectedWidth, actualSide2);


		}
	};
}
