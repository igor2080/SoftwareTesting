#include<fstream>
#include<iostream>
#include<string>
#include <algorithm>
#include <sstream>

using namespace std;

string trimStart(string s)
{
	while (s[0] == ' ' || s[0] == '\t')
	{
		s.erase(0, 1);
	}

	return s;
}

void findCommands(string line, int& ifs, int& fors, int& whiles)
{
	//get rid of all strings inside line as they can contain fake if/while/for commands
	int position = line.find('"');
	while (position != -1)
	{
		line.erase(position, line.find('"', position + 1) - position + 1);
		position = line.find('"');
	}
	//separate the line into pieces that end in semicolons
	//program can have an if/while/for at the end of a line and still be valid
	//since a line can contain an entire definition of if/while/for
	//they will end in either a semicolon or a closing brace '}'
	//replace all closing braces with semicolons for easier splitting
	replace(line.begin(), line.end(), '}', ';');
	replace(line.begin(), line.end(), ')', ';');
	//get rid of all opening braces as they can be attached to the commands on a new line
	replace(line.begin(), line.end(), '{', ' ');
	replace(line.begin(), line.end(), '(', ' ');

	//turn the line into a stream to read it by a split character(;)
	stringstream lineStream(line);
	string segment;//split piece of the line

	while (getline(lineStream, segment, ';'))
	{
		segment = trimStart(segment);//get rid of leading spaces

		//if a piece starts with an else, remove it to check for "if" that can come after it
		if (segment.rfind("else", 0) == 0) {
			segment.erase(0, 4);
			segment = trimStart(segment);//there might be leading spaces after removal
		}

		//check if each piece starts with if/for/while
		//as at this point it is guaranteed to start with those if they exist
		if (segment.rfind("if", 0) == 0) {
			ifs++;
		}
		else if (segment.rfind("for", 0) == 0) {
			fors++;
		}
		else if (segment.rfind("while", 0) == 0) {
			whiles++;
		}
	}
}



int main()
{
	//example use:
	int ifs = 0, fors = 0, whiles = 0;
	fstream codeFile("codefile1.txt", ios::in);
	string codeLine = "";
	while (getline(codeFile, codeLine))
	{
		findCommands(codeLine, ifs, fors, whiles);
	}
}