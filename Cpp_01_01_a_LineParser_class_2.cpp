// Cpp_01_01_a_LineParser_class_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<sstream>
#include <vector>
using namespace std;

typedef vector<int> IntSmartArray;
typedef vector<string> StringSmartArray;
typedef vector<char> CharSmartArray;

class LineParser {
private:
	string line;

public:
	LineParser() {}
	//LineParser(string line) : line(line) {}

	LineParser(const string& line) : line(line) {}

private:
	int CountElements(string line)
	{
		string strtoken;
		istringstream iss(line);
		int numberTokens = 0;
		while (iss >> strtoken)
		{
			numberTokens++;
		}
		return numberTokens;
	}


public:
	IntSmartArray getNumbers() const
	{
		IntSmartArray arr;
		istringstream iss(this->line);
		int number;
		while (iss >> number)
		{
			arr.push_back(number);
		}
		return arr;
	}
	StringSmartArray getStrings() const
	{
		StringSmartArray arr;
		istringstream iss(this->line);
		string strToken;
		while (iss >> strToken)
		{
			arr.push_back(strToken);
		}
		return arr;
	}
	CharSmartArray getChars() const
	{
		CharSmartArray arr;
		for (int i = 0; i < this->line.size(); i++)
		{
			if (this->line[i] != ' ')
			{
				arr.push_back(this->line[i]);
			}
		}
		return arr;
	}
	void changeLine(const string& line)
	{
		this->line = line;
	}
};

void PrintResultStringArray(StringSmartArray result_String_Array)
{
	cout << "RESULT STRING TOKENS: ";
	for (int i = 0; i < result_String_Array.size() - 1; i++)
	{
		cout << result_String_Array[i] << ", ";
	}
	cout << result_String_Array[result_String_Array.size() - 1] << endl;
}

void PrintResultIntArray(IntSmartArray result_int_Array)
{
	cout << "RESULT INT TOKENS: ";
	for (int i = 0; i < result_int_Array.size() - 1; i++)
	{
		cout << result_int_Array[i] << ", ";
	}
	cout << result_int_Array[result_int_Array.size() - 1] << endl;
}

void PrintResultCharArray(CharSmartArray result_char_Array)
{
	cout << "RESULT CHAR TOKENS: ";
	for (int i = 0; i < result_char_Array.size() - 1; i++)
	{
		cout << result_char_Array[i] << ", ";
	}
	cout << result_char_Array[result_char_Array.size() - 1] << endl;
}

int main()
{
	//bool sameSequence = true;
	cout << "Enter sequence of numbers OR \".\" to end program: ";
	string line;
	getline(cin, line);
	LineParser lineparser(line);

	while (line != ".") 
	{
		if (line != "s") {
			lineparser.changeLine(line);
			string strtoken;
			istringstream iss(line);
			int numberTokens = 0;
			while (iss >> strtoken)
			{
				numberTokens++;
			}	
			string changeSequence;
			//Change sequence of numbers:
			/*cout << "Would you like to change sequence? Enter y/n: ";
			getline(cin, changeSequence);
			if (changeSequence == "y")
			{
				getline(cin, line);
				lineparser.changeLine(line);
			}*/

			cout << "Parse to which type elements: string, int or char?";
			string command;
			getline(cin, command);

			if (command == "string")
			{
				cout << "String is parsed to STRING tokens: " << endl;
				StringSmartArray resultArray = lineparser.getStrings();
				PrintResultStringArray(resultArray);
			}
			else if (command == "int")
			{
				cout << "String is parsed to INT tokens: " << endl;
				IntSmartArray resultArray = lineparser.getNumbers();
				PrintResultIntArray(resultArray);
			}
			else if (command == "char")
			{
				cout << "String is parsed to CHAR tokens: " << endl;
				CharSmartArray resultArray = lineparser.getChars();
				PrintResultCharArray(resultArray);
			}
		}
		else
		{
			cout << "Parse to which type elements: string, int or char?";
			string command;
			getline(cin, command);

			if (command == "string")
			{
				cout << "String is parsed to STRING tokens: " << endl;
				StringSmartArray resultArray = lineparser.getStrings();
				PrintResultStringArray(resultArray);
			}
			else if (command == "int")
			{
				cout << "String is parsed to INT tokens: " << endl;
				IntSmartArray resultArray = lineparser.getNumbers();
				PrintResultIntArray(resultArray);
			}
			else if (command == "char")
			{
				cout << "String is parsed to CHAR tokens: " << endl;
				CharSmartArray resultArray = lineparser.getChars();
				PrintResultCharArray(resultArray);
			}
		}
		cout << "Enter sequence of numbers OR \"s\" for same sequence and another parse; OR \".\" to end program: ";		
		getline(cin, line);
	}

	return 0;
}

