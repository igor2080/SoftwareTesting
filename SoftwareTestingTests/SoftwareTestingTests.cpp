#include "pch.h"
#include "CppUnitTest.h"
#include "../SoftwareTesting/SoftwareTesting.cpp"
#include<fstream>
#include<iostream>
#include<string>
#include <algorithm>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SoftwareTestingTests
{
	TEST_CLASS(SoftwareTestingTests)
	{

	public:
		TEST_METHOD(T5_1)
		{
			int ifs = 0, fors = 0, whiles = 0;
			string codeFile = "int main()"s +
				"{" +
				"	int restart = 1;" +
				"	while(restart!=0)" +
				"	{" +
				"		int a=-1; int b=-1;" +
				"		string g = \"text\" + 5;" +
				"		int c=0; if(true) c++;" +
				"		cout<<\"please enter first dimension of array(greater than 0) : \";" +
				"		while(a<0)" +
				"			cin>>a;" +
				"		cout<<\"please enter second dimension of array(greater than 0) : \";" +
				"		while(b<0)" +
				"			cin>>b;" +
				"		int** matrix = new int* [a];" +
				"		for (int i = 0; i < a; i++)" +
				"		{" +
				"			matrix[i] = new int[b];" +
				"		}" +
				"		for (int i = 0; i < a; i++)" +
				"		{" +
				"			for (int j = 0; j < b; j++)" +
				"			{" +
				"				cout<<\"enter number for location(\"<<(i+1)<<\"), (\"<<(j+1)<<\") : \";" +
				"				cin >> matrix[i][j];" +
				"			}" +
				"		}" +
				"}";
			int expectedIfs = 1, expectedFors = 3, expectedWhiles = 3;
			findCommands(codeFile, ifs, fors, whiles);
			Assert::AreEqual(expectedIfs, ifs);
			Assert::AreEqual(expectedFors, fors);
			Assert::AreEqual(expectedWhiles, whiles);

		}
	};
}
