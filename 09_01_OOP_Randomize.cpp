// 09_01_OOP_Randomize.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> //for std::cout
#include <string>
#include <sstream>
#include <iomanip>     
#include <cctype>      //char toupper, tolower  
#include <set>           
#include <iterator> //for std::ostream_iterator
#include <algorithm> //for std::copy      
#include <random>
#include <vector>

// random_shuffle example
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using namespace std;

//KOДЪТ РАБОТИ С CHARs АКО СЕ ПОЛЗВА ИЗВЕЖДАНЕ С iterator!!!!!  string * container  Е С-STRING!!!!!!!! 
//но, ако се ползва for (int i = 0; i < this->length; i ++) {}, ИЗВЕЖДА ДУМИТЕ!!!!!!!!!!!
//!!!!! AKO СЕ ПОЛЗВА ОБХОЖДАНЕ С Iterator , ИЗВЕЖДА ПО CHAR-ове!!!!!!!!!!!!!!!!!
/*string getInfo_inColumn() const
{
ostringstream oss;
for (auto it = container->begin(); it != container->end(); it++)
{
oss << *it << endl;
}
return oss.str();
}*/

//Welcome to SoftUni and have fun learning programming
//CONTAINER + 1 element MORE : W, e, l, c, o, m, e, Length : 1
//CONTAINER + 1 element MORE : W, e, l, c, o, m, e, Length : 2
//CONTAINER + 1 element MORE : W, e, l, c, o, m, e, Length : 3
//CONTAINER + 1 element MORE : W, e, l, c, o, m, e, Length : 4
//CONTAINER + 1 element MORE : W, e, l, c, o, m, e, Length : 5
//CONTAINER + 1 element MORE : W, e, l, c, o, m, e, Length : 6
//CONTAINER + 1 element MORE : W, e, l, c, o, m, e, Length : 7
//CONTAINER + 1 element MORE : W, e, l, c, o, m, e, Length : 8
//W, e, l, c, o, m, e,
//Enter "r" for randomize and print, OR "e" to Exit :

// random generator function:
int myrandom(int i) { return std::rand() % i; }

void PrintVectorInt(vector<int>vIndices)
{
	for (int i = 0; i < vIndices.size(); i++)
	{
		cout << vIndices[i] << ", ";
	}
}

class StringsLinearContainerAbleToRandomize
{
private:
	int length;
	string * container;
public:
	StringsLinearContainerAbleToRandomize() :
		length(0),
		container(new string[0])
	{}

	void includeNextElement(string element)
	{		
		string * newSmartLinearContainer_withIncreasedLength = new string[(this->length + 1)]();
		CopyElementsFromThis(newSmartLinearContainer_withIncreasedLength);

		//CHECK:
		//cout << getInfo_inLine() << endl;

		delete[] this->container;
		this->container = newSmartLinearContainer_withIncreasedLength;
		IncreaseLength();
		AddNewElement_asLastElement(element);

		//CHECK:
		//cout << "CONTAINER + 1 element MORE: ";
		//cout << getInfo_inLine();
		//cout << "Length: " << this->length << endl;
	}
	int getLength()
	{
		return this->length;
	}
private:
	void IncreaseLength()
	{
		this->length++;
	}
	void CopyElements(string * oldContainer, string * newContainer)
	{
		for (int i = 0; i < this->length; i++)
		{
			newContainer[i] = oldContainer[i];
		}
	}
	void CopyElementsFromThis(string * newContainer)
	{
		for (int i = 0; i < this->length; i++)
		{
			newContainer[i] = (this->container)[i];
		}
	}
	void AddNewElement_asLastElement(string element)
	{
		this->container[this->length - 1] = element;
	}
	vector <string> CopyContainerToVector() const
	{
		vector<string> v;
		for (int i = 0; i < this->length; i++)
		{
			v.push_back((this->container)[i]);
		}
		return v;
	}
	void CopyVectorToContainer_and_deleteOldContainer(vector<string>v)
	{
		for (int i = 0; i < this->length; i++)
		{
			(this->container)[i] = v[i];
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
		string * tempOldContainer = new string[this->length]();
		CopyElements(this->container, tempOldContainer);
		RandomizeContainer(tempOldContainer, vIndices);
		delete[] tempOldContainer;
	}
	void RandomizeContainer(string * tempOldContainer, vector<int>& vIndices)
	{
		for (int i = 0; i < this->length; i++)
		{
			(this->container)[i] = tempOldContainer[vIndices[i]];
		}
	}

public:
	//~SmartLinearContainer()
	//{
	//	cout << "~SmartLinearContainer: " << getInfo_inLine();
	//}
	string getInfo_inLine() const
	{
		ostringstream oss;
		for (int i = 0; i < this -> length; i ++)
		{
			oss << this->container[i] << ", ";
		}
		return oss.str();
	}
	//!!!!! AKO СЕ ПОЛЗВА ОБХОЖДАНЕ С Iterator , ИЗВЕЖДА ПО CHAR-ове!!!!!!!!!!!!!!!!!

	/*string getInfo_inColumn_BY_CHARs() const
	{
		ostringstream oss;
		for (auto it = container->begin(); it != container->end(); it++)
		{
			oss << *it << endl;
		}
		return oss.str();
	}*/
	string getInfo_inColumn() const
	{
		ostringstream oss;
		for (int i = 0; i < this -> length; i++)
		{
			oss << (this->container)[i] << endl;
		}
		return oss.str();
	}
	void randomize()
	{
		std::random_device rd;
		std::mt19937 g(rd());

		vector<string> v = CopyContainerToVector();
		shuffle(v.begin(), v.end(), g);
		CopyVectorToContainer_and_deleteOldContainer(v);
	}
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

		//vector<string> vContainer = CopyContainerToVector();
		shuffle(vIndices.begin(), vIndices.end(), g);

		//CHECK:
		//cout << "SHUFFLED VECTOR OF INDICES: ";
		//PrintVectorInt(vIndices);

		CopyContainer_UsingRandomizedIndices(vIndices);
		//CHECK:
		//cout << "Copied SHUFFLED CONTAINER ******** qsing randomized INDICES: ";
		//cout << getInfo_inLine() << endl;

		return getInfo_inColumn();
	}
	string randomize_and_getInfo_inLine()
	{
		std::random_device rd;
		std::mt19937 g(rd());

		vector<string> v = CopyContainerToVector();
		shuffle(v.begin(), v.end(), g);
		CopyVectorToContainer_and_deleteOldContainer(v);
		return getInfo_inLine();
	}

};

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	StringsLinearContainerAbleToRandomize dataContainer;

	string line;
	getline(cin, line);
	istringstream iss(line);
	string word;
	while (iss >> word)
	{
		dataContainer.includeNextElement(word);
	}

	//CHECK:
	//cout << dataContainer.getInfo_inLine() << endl;

	char command;
	cout << "Enter \"r\" for randomize and print, OR \"e\" to Exit: ";
	cin >> command;
	while (command != 'e')
	{
		cout << dataContainer.randomize_and_getInfo_inColumn();
		cout << "Enter \"r\" for randomize and print, OR \"e\" to Exit: ";
		cin >> command;
	}

	/*if (dataContainer.getLength() > 0)
	{*/
	//delete dataContainer;
	//}
	cout << endl;
	return 0;
}

