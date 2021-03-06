// 08_07_Miners_LIST_+_Class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> //for std::cout
#include <string>
#include <sstream>
#include <iomanip>     
#include <list>           
#include <iterator> //for std::ostream_iterator
#include <algorithm> //for std::copy    

using namespace std;

class Mineral
{
private:
	string nameResource;
	double quantity;
public:
	Mineral(string nameResource, double quantity) :
		nameResource(nameResource), quantity(quantity) {}

	string getMineralName() const
	{
		return this->nameResource;
	}
	double getQuantity() const
	{
		return this->quantity;
	}
	void setResourceQuantity(double newQuantity)
	{
		this->quantity += newQuantity;
	}
	string getInfo() const {
		ostringstream info;
		info << this->nameResource << " -> " << this->quantity;
		return info.str();
	}
};

static list<Mineral> dataMinerals;

bool ResourceIsInData(string resource)
{
	for (auto it = dataMinerals.begin(); it != dataMinerals.end(); it++)
	{
		if (it->getMineralName() == resource)
		{
			return true;
		}
	}
	return false;
}

void AddNewQuantity(string resource, double quantity)
{
	for (auto it = dataMinerals.begin(); it != dataMinerals.end(); it++)
	{
		if (it->getMineralName() == resource)
		{
			it->setResourceQuantity(quantity);
		}
	}
}

void PrintList()
{
	for (auto it = dataMinerals.begin(); it != dataMinerals.end(); it++)
	{
		cout << it->getInfo() << endl;
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	string input;
	cin >> input;
	while (input != "stop")
	{
		string resource;
		double quantity;
		resource = input;
		cin >> quantity;

		if (ResourceIsInData(resource))
		{
			AddNewQuantity(resource, quantity);
		}
		else
		{
			Mineral mineral(resource, quantity);
			dataMinerals.push_back(mineral);
		}
		cin >> input;
	}
	PrintList();
	return 0;
}

