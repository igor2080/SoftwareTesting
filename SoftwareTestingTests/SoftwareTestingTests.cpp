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
		TEST_METHOD(T5_2)
		{
			int ifs = 0, fors = 0, whiles = 0;
			string codeFile = "#include<iostream>"s +
				"#include<fstream>" +
				"using namespace std;" +
				"int main() {" +
				"    fstream f(\"textfilein.txt\",ios::in);" +
				"    string s = \"\\\"\";" +
				"    int lines=0,digits=0;" +
				"    while (getline(f,s)) {" +
				"        cout<<s<<endl;" +
				"        for (int i=0;i<s.length();++i)" +
				"            if (s[i]>='0' and s[i]<='9')" +
				"                digits++;" +
				"        lines++;" +
				"    }" +
				"    cout<<lines<<endl;" +
				"    cout<<digits<<endl;" +
				"    f.close();" +
				"}";
			int expectedIfs = 0, expectedFors = 0, expectedWhiles = 1;
			findCommands(codeFile, ifs, fors, whiles);
			Assert::AreEqual(expectedIfs, ifs);
			Assert::AreEqual(expectedFors, fors);
			Assert::AreEqual(expectedWhiles, whiles);

		}
		TEST_METHOD(T5_3)
		{
			int ifs = 0, fors = 0, whiles = 0;
			string codeFile = "#include <iostream>"s +
				"#include <vector>" +
				"using namespace std;" +
				"string SumOfTwoStrings(string a, string b)" +
				"{" +
				"	bool firstLarger, firstNegative = false, secondNegative = false, resultIsNegative = false;" +
				"	if (a[0] == '-')" +
				"	{" +
				"		firstNegative = true;" +
				"		a.erase(0, 1);" +
				"	}" +
				"	if (b[0] == '-')" +
				"	{" +
				"		secondNegative = true;" +
				"		b.erase(0, 1);" +
				"	}" +
				"	firstLarger = a.size() > b.size();" +
				"	int zerocount = 0;" +
				"	string zeroes = "";" +
				"	if (firstLarger)" +
				"		zerocount = a.size() - b.size();" +
				"	else" +
				"		zerocount = b.size() - a.size();" +
				"	for (int i = 0; i < zerocount; i++)" +
				"		zeroes += \"0\";" +
				"	if (firstLarger)" +
				"		b = zeroes + b;" +
				"	else" +
				"		a = zeroes + a;" +
				"	for (int i = 0; i < a.size(); i++)" +
				"	{" +
				"		if (a[i] > b[i])" +
				"		{" +
				"			firstLarger = true;" +
				"			break;" +
				"		}" +
				"		if (b[i] > a[i])" +
				"		{" +
				"			firstLarger = false;" +
				"			break;" +
				"		}" +
				"	}" +
				"	if ((firstNegative && secondNegative) || (firstLarger && firstNegative) || (!firstLarger && secondNegative))" +
				"		resultIsNegative = true;" +
				"	char digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };" +
				"	string sum = "";" +
				"	int mathResult = 0;" +
				"	int carry = 0;" +
				"	int ldigit = 0, rdigit = 0;" +
				"	if (firstNegative == secondNegative)" +
				"	{" +
				"		for (int i = a.size() - 1; i >= 0; i--)" +
				"		{" +
				"			mathResult = ((a[i] - '0') + carry + (b[i] - '0'));" +
				"			sum = digits[mathResult % 10] + sum;" +
				"			if (mathResult > 9)" +
				"				carry = 1;" +
				"		}" +
				"	}" +
				"	else" +
				"	{" +
				"		for (int i = a.size() - 1; i >= 0; i--)" +
				"		{" +
				"			if (firstLarger)" +
				"			{" +
				"				ldigit = (a[i] - '0');" +
				"				rdigit = (b[i] - '0');" +
				"			}" +
				"			else" +
				"			{" +
				"				ldigit = (b[i] - '0');" +
				"				rdigit = (a[i] - '0');" +
				"			}" +
				"			if (carry == 1)" +
				"			{" +
				"				ldigit = 10 + ldigit;" +
				"				carry = 0;" +
				"			}" +
				"			else if (carry == -1)" +
				"			{" +
				"				ldigit--;" +
				"				carry = 0;" +
				"			}" +
				"			if (ldigit < rdigit)" +
				"			{" +
				"				ldigit = 10 + ldigit;" +
				"				carry = -1;" +
				"			}" +
				"			mathResult = ldigit - rdigit;" +
				"			sum = digits[mathResult % 10] + sum;" +
				"			if (mathResult > 9)" +
				"				carry = 1;" +
				"		}" +
				"	}" +
				"	if (carry == 1)" +
				"		sum = digits[carry] + sum;" +
				"	while (sum[0] == '0')" +
				"	{" +
				"		sum.erase(0, 1);" +
				"	}" +
				"	if (resultIsNegative)" +
				"		sum = \" - \" + sum;" +
				"	return sum;" +
				"}" +
				"int main() {" +
				"	" +
				"	return 0;" +
				"}";
			int expectedIfs = 16, expectedFors = 4, expectedWhiles = 1;
			findCommands(codeFile, ifs, fors, whiles);
			Assert::AreEqual(expectedIfs, ifs);
			Assert::AreEqual(expectedFors, fors);
			Assert::AreEqual(expectedWhiles, whiles);
		}
		TEST_METHOD(T5_4)
		{
			int ifs = 0, fors = 0, whiles = 0;
			string codeFile = "int main(){int restart = 1;while(restart!=0){int a=-1; int b=-1;string g = \"text\" + 5;int c=0; if(true) c++;cout<<\"please enter first dimension of array(greater than 0): \";while(a<0)cin>>a;cout<<\"please enter second dimension of array(greater than 0): \";while(b<0)cin>>b;int** matrix = new int* [a];for (int i = 0; i < a; i++){matrix[i] = new int[b];}for (int i = 0; i < a; i++){for (int j = 0; j < b; j++){cout<<\"enter number for location (\"<<(i+1)<<\"),(\"<<(j+1)<<\"):\";cin >> matrix[i][j];}}}";
			int expectedIfs = 1, expectedFors = 3, expectedWhiles = 3;
			findCommands(codeFile, ifs, fors, whiles);
			Assert::AreEqual(expectedIfs, ifs);
			Assert::AreEqual(expectedFors, fors);
			Assert::AreEqual(expectedWhiles, whiles);
		}
	};
}
