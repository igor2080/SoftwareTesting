#include "pch.h"
#include "CppUnitTest.h"
#include "../SoftwareTesting/SoftwareTesting.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SoftwareTestingTests
{
	TEST_CLASS(SoftwareTestingTests)
	{
	public:

		TEST_METHOD(T3_1)
		{
			vector<int> input{ 1, 1, -35544, -846, 8, 8, 43689214, 0, 8, -245667, 0 };

			string ExpectedResult =
				"Modified vector: 43689224 18 11 10 -836 -35534 -245657 \n"//extra space before newline
				"Sum of the elements: 43407236\n"
				"Maximum element: 43689224\n"
				"Minimum element: -245657\n"
				"Average of the elements: 6.20103e+06\n"
				"Number of even numbers: 5\n"
				"Number of odd numbers: 2\n";


			stringstream ActualResult;

			manipulateVector(input, ActualResult);

			Assert::AreEqual(ExpectedResult, ActualResult.str());

		}
	};
}
