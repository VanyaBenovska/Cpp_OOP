// 09_00_OOP_SmartArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

typedef int DataType;

class SmartArray
{
private:
	int length;
	DataType * data;   //масив

public:
	SmartArray() :     //празен конструктор, който го инициализира с 0 елементи
		length(0),
		data(new DataType[0])  //за да знаем че винаги имаме инициализиране масив, а не да правим if == 0;
							   //не заделя 0 байта; заделя 0 байта + мета информация	
	{}

	SmartArray(int length) :
		length(length),
		data(new DataType[length])
	{}

	DataType getElement(int index)
	{
		ensureIndexInBounds(index); //директно чупи кода ако индексът е вън
		return this->data[index];
	}

	int getLength() const
	{
		//трябва ни , когато ще пишем цикли или обхождаме this-> data
		return this->length;
	}

	void setElement(int index, DataType value)
	{
		ensureIndexInBounds(index); //директно чупи кода ако индексът е вън
		this->data[index] = value;
	}

	void changeLength(int newLength)
	{
		DataType * newData = new DataType[newLength](); //със () ЗАНУЛЯВАМЕ паметта!!!

		copyData(this->data, this->length, newData, newLength); //има такава функция в std! която копира

		delete[] this->data; //не изтриваме променливата , а даннните към които тази променлива сочи!

		this->data = newData; //пренасочвам указателя от към старата памет, да сочи към новата
		this->length = newLength;
	}

	string toString()
	{
		stringstream stringResult;
		for (int i = 0; i < this->length; i++)
		{
			stringResult << this->data[i] << " ";
		}
		return stringResult.str();
	}

	DataType& operator[] (int index)
	{
		return this->data[index];
	}

private:
	void ensureIndexInBounds(int index)
	{
		if (index < 0 || index >= this->length)
		{
			throw "Index out of bounds";  //това ще ни счупи програмата но ще ни каже каво й е
										  //ще хвърли char pointer , това е String, който е char pointer
		}
	}

	//private:  нямаме НИКАКВА нужда да викаме copyData от външен код! 
	//Може nqkoj da si q haresa i da stane mazalo, kato q promenim
	//примерно да изнесем проверката другаде; И изведнъж външният код на някой се чупи.
	static void copyData(DataType * source, int sourceLength,
		DataType * dest, int destLength)
	{
		//има такава функция в std! която копира
		for (int i = 0; i < sourceLength && i < destLength; i++)
		{
			dest[i] = source[i];
		}
	}
};


int main()
{
	SmartArray arr;
	arr.changeLength(2);
	//arr.data[0] = 3;
	arr.setElement(0, 3);

	//cout << arr.data[0] << endl;
	//cout << arr.data[1] << endl;

	arr.changeLength(3);
	//arr.data[2] = 44;
	arr.setElement(2, 44);

	//cout << arr.data[0] << endl;
	//cout << arr.data[1] << endl;
	//cout << arr.data[2] << endl;

	cout << "*****************" << endl;
	cout << arr.toString() << endl;

	arr.changeLength(1);
	cout << arr.toString() << endl;

	//EНКАПСУЛАЦИЯ!  ако няма такава, т..е., ako всичко e public:
	//ако kажем:
	//arr.length = 15;   ??? достъпва НЕ наша памет
	//ИЛИ
	//arr.data = NULL;  ГЪРМИ!
	//НЕ Е ХУБАВО ВЪНШЕН КОД ДА НИ БЪРКА В private нещата!!!

	//ОВЪРЛОУДВНЕ НА ОПЕРАТОР []

	arr[0] = 69;
	cout << arr.toString() << endl;

	return 0;
}

