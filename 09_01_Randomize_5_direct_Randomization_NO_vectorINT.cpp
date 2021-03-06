// 09_01_Randomize_5_direct_Randomization_NO_vectorINT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> //for std::cout
#include <string>
#include <sstream>
#include <iomanip>     
#include <cctype>      //char toupper, tolower  
#include <set>           
#include <iterator> //for std::ostream_iterator
#include <random>
#include <vector>
// random_shuffle 
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using namespace std;

//int myrandom(int i) { return std::rand() % i; }

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
		delete[] this->container;
		this->container = newSmartLinearContainer_withIncreasedLength;
		IncreaseLength();
		AddNewElement_asLastElement(element);
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
	void CopyThisContainerToVector(vector<string>& v)
	{		
		for (int i = 0; i < this->length; i++)
		{
			v.push_back((this->container)[i]);
		}		
	}	
	void CopyRandomizedVector_toThisContainer(vector<string> & v)
	{
		for (int i = 0; i < this->length; i++)
		{
			(this->container)[i] = v[i];
		}
	}
	void RandomizeStringVector(vector<string>& v)
	{
		//VER 1  std::random_shuffle
		//VER 2
		std::random_device rd;
		std::mt19937 g(rd());
		shuffle(v.begin(), v.end(), g);
	}

public:
	~StringsLinearContainerAbleToRandomize()
	{}
	string getInfo_inLine() const
	{
		ostringstream oss;
		for (int i = 0; i < this->length - 1; i++)
		{
			oss << this->container[i] << ", ";
		}
		oss << this->container[this->length - 1];
		return oss.str();
	}

	string getInfo_inColumn() const
	{
		ostringstream oss;
		for (int i = 0; i < this->length; i++)
		{
			oss << (this->container)[i] << endl;
		}
		return oss.str();
	}
	void randomizeContainer()
	{
		vector<string> vStrContainer;
		CopyThisContainerToVector(vStrContainer);
		RandomizeStringVector(vStrContainer);
		CopyRandomizedVector_toThisContainer(vStrContainer);
	}
	string randomize_and_getInfo_inColumn()
	{
		vector<string> vStrContainer;
		CopyThisContainerToVector(vStrContainer);
		RandomizeStringVector(vStrContainer);		
		CopyRandomizedVector_toThisContainer(vStrContainer);
		return getInfo_inColumn();
	}
	string randomize_and_getInfo_inLine()
	{
		vector<string> vStrContainer;
		CopyThisContainerToVector(vStrContainer);
		RandomizeStringVector(vStrContainer);
		CopyRandomizedVector_toThisContainer(vStrContainer);		
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
	char command;
	cout << "Enter \"r\" for randomize and print, OR \"e\" to Exit: ";
	cin >> command;
	while (command != 'e')
	{
		//cout << dataContainer.randomize_and_getInfo_inColumn();
		dataContainer.randomizeContainer();
		cout << dataContainer.getInfo_inColumn();
		cout << "Enter \"r\" for randomize and print, OR \"e\" to Exit: ";
		cin >> command;
	}
	//StringsLinearContainerAbleToRandomize * p = &dataContainer;
	/*if (dataContainer.getLength() > 0)
	{*/
	//delete p;
	//}
	cout << endl;
	return 0;
}

