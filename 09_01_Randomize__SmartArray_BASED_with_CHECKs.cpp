// 09_01_Randomize__SmartArray_BASED_with_CHECKs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<sstream>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;

typedef string DataType;

class SmartArray
{
private:
	int length;
	DataType * data;
public:
	SmartArray() :
		length(0),
		data(new DataType[0])
	{}

	int getLength() const
	{
		return this->length;
	}

	void setNextElement(DataType value)
	{
		changeLength();
		this->data[(this->length - 1)] = value;
	}

	void changeLength()
	{
		DataType * newData = new DataType[(this->length + 1)]();

		copyData(this->data, this->length, newData, (this->length + 1));

		delete[] this->data;

		this->data = newData;
		this->length++;
	}

	string toString()
	{
		stringstream stringResult;
		for (int i = 0; i < this->length; i++)
		{
			stringResult << this->data[i] << endl;
		}
		return stringResult.str();
	}

	/*DataType& operator[] (int index)
	{
	return this->data[index];
	}*/
	string randomize_and_getInfo_inColumn()
	{
		//VER 1  std::random_shuffle
		//GLOBAL: // random generator function:
		// //int myrandom(int i) { return std::rand() % i; }

		//std::srand(unsigned(std::time(0)));
		//std::vector<int> myvector;

		// // set some values:
		//for (int i = 1; i<10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

		// // using built-in random generator:
		//std::random_shuffle(myvector.begin(), myvector.end());

		// // using myrandom:
		//std::random_shuffle(myvector.begin(), myvector.end(), myrandom);

		//***

		//VER 2
		std::random_device rd;
		std::mt19937 g(rd());

		vector<int> vIndices;
		CopyIndicesToVector(vIndices);

		//CHECK:
		//PrintVectorInt(vIndices);

		//vector<string> vContainer = CopyContainerToVector();
		shuffle(vIndices.begin(), vIndices.end(), g);

		//CHECK:
		//cout << "SHUFFLED VECTOR OF INDICES: ";
		//PrintVectorInt(vIndices);

		CopyContainer_UsingRandomizedIndices(vIndices);
		//CHECK:
		//cout << "Copied SHUFFLED CONTAINER ******** qsing randomized INDICES: ";
		//cout << getInfo_inLine() << endl;

		return toString();
	}
private:
	/*void ensureIndexInBounds(int index)
	{
	if (index < 0 || index >= this->length)
	{
	throw "Index out of bounds";
	}
	}*/
	static void copyData(DataType * source, int sourceLength,
		DataType * dest, int destLength)
	{
		for (int i = 0; i < sourceLength && i < destLength; i++)
		{
			dest[i] = source[i];
		}
	}
	void CopyIndicesToVector(vector<int> & vIndices)
	{
		for (int i = 0; i < this->length; i++)
		{
			vIndices.push_back(i);
		}
	}
	void CopyContainer_UsingRandomizedIndices(vector<int> & vIndices)
	{
		DataType * tempOldContainer = new DataType[this->length]();
		copyData(this->data, this->length,
			tempOldContainer, this->length);
		RandomizeContainer(tempOldContainer, vIndices);
		delete[] tempOldContainer;
	}
	void RandomizeContainer(DataType * tempOldContainer, vector<int>& vIndices)
	{
		for (int i = 0; i < this->length; i++)
		{
			(this->data)[i] = tempOldContainer[vIndices[i]];
		}
	}
};


int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	SmartArray arr;

	arr.setNextElement("Beautiful Day");
	cout << arr.toString() << endl;
	cout << arr.toString() << endl;

	SmartArray dataContainer;
	string line;
	getline(cin, line);
	istringstream iss(line);
	string word;
	while (iss >> word)
	{
		dataContainer.setNextElement(word);
	}

	//CHECK:
	//cout << dataContainer.toString() << endl;

	char command;
	cout << "Enter \"r\" for randomize and print, OR \"e\" to Exit: ";
	cin >> command;
	while (command != 'e')
	{
		cout << dataContainer.randomize_and_getInfo_inColumn();
		cout << endl;
		cout << "Enter \"r\" for randomize and print, OR \"e\" to Exit: ";
		cin >> command;
	}

	return 0;
}

