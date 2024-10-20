#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
#include "pch.h"
#include "CppUnitTest.h"

        extern "C" {
            void setLength(int input, int* length);
            void setWidth(int input, int* width);
            int getPerimeter(int* length, int* width);
            int getArea(int* length, int* width);
        }

        using namespace Microsoft::VisualStudio::CppUnitTestFramework;

        namespace RectangleUnitTest
        {
            // SetLength Tests
            TEST_CLASS(SetLengthTests)
            {
            public:
                // Test Case 1: Usual Input
                TEST_METHOD(TestSetLength_UsualInput)
                {
                    int length = 0;
                    setLength(45, &length);  // Usual valid input
                    Assert::AreEqual(45, length); // Verify that length was set to 45
                }

                // Test Case 2: Minimum Edge Case
                TEST_METHOD(TestSetLength_MinEdgeCase)
                {
                    int length = 0;
                    setLength(1, &length);  // Minimum valid input
                    Assert::AreEqual(1, length); // Verify that length was set to 1
                }

                // Test Case 3: Unusual/Special Case (Out of Range)
                TEST_METHOD(TestSetLength_OutOfRange)
                {
                    int length = 0;
                    setLength(150, &length);  // Out of range value
                    Assert::AreNotEqual(150, length);  // Verify that length was not set to 150 (the function should handle this)
                }
            };

            // SetWidth Tests
            TEST_CLASS(SetWidthTests)
            {
            public:
                // Test Case 1: Usual Input
                TEST_METHOD(TestSetWidth_UsualInput)
                {
                    int width = 0;
                    setWidth(30, &width);  // Usual valid input
                    Assert::AreEqual(30, width); // Verify that width was set to 30
                }

                // Test Case 2: Maximum Edge Case
                TEST_METHOD(TestSetWidth_MaxEdgeCase)
                {
                    int width = 0;
                    setWidth(99, &width);  // Maximum valid input
                    Assert::AreEqual(99, width); // Verify that width was set to 99
                }

                // Test Case 3: Unusual/Special Case (Negative Value)
                TEST_METHOD(TestSetWidth_NegativeInput)
                {
                    int width = 0;
                    setWidth(-10, &width);  // Negative value
                    Assert::AreNotEqual(-10, width);  // Verify that width was not set to -10 (the function should handle this)
                }
            };

            // Perimeter Tests
            TEST_CLASS(RectanglePerimeterTests)
            {
            public:
                // Test Case: Regular Input
                TEST_METHOD(TestPerimeter_RegularInput)
                {
                    int length = 10;
                    int width = 5;
                    int result = getPerimeter(&length, &width);
                    Assert::AreEqual(30, result); // Perimeter = 2 * (10 + 5) = 30
                }
            };

            // Area Tests
            TEST_CLASS(RectangleAreaTests)
            {
            public:
                // Test Case: Regular Input
                TEST_METHOD(TestArea_RegularInput)
                {
                    int length = 10;
                    int width = 5;
                    int result = getArea(&length, &width);
                    Assert::AreEqual(50, result); // Area = 10 * 5 = 50
                }
            };
        }