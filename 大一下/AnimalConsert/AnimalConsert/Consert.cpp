#include "stdafx.h"
#include "Consert.h"
#include <iostream>
using namespace std;


Consert::Consert()
{
	for (int i = 0; i < 10; i++)
		animalPtr[i] = nullptr;
	regist();
}

void Consert::regist()
{
	int Animallist[10];
	for (int i = 0; i < 10; i++)
		Animallist[i] = 0;
	cout << "请输入相应动物代号：" << endl;
	cout << "0.Quit" << endl;
	cout << "1.Cat" << endl;
	cout << "2.Dog" << endl;
	cout << "3.Sheep" << endl;
	cout << "4.Cow" << endl;
	cout << "5.Pig" << endl;
	cout << "__________________________________________" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "请输入动物代号：  ";
		cin >> Animallist[i];
		if (Animallist[i] == 0)
			break;
		if (Animallist[i] < 0 || Animallist[i] > 5)
		{
			cout << "Wrong code. Input again!" << endl;
			i--;
			continue;
		}

		cout << "动物名字叫做：  ";
		string name;
		cin >> name;
		switch (Animallist[i])
		{
		case 1:
			animalPtr[i] = new Cat(name);
			break;
		case 2:
			animalPtr[i] = new Dog(name);
			break;
		case 3:
			animalPtr[i] = new Sheep(name);
			break;
		case 4:
			animalPtr[i] = new Cow(name);
			break;
		case 5:
			animalPtr[i] = new Pig(name);
			break;
		}
	}
}

void Consert::Singsongs()
{
	for (int i = 0; i < 10; i++)
		if (animalPtr[i] != nullptr)
			animalPtr[i]->Sing();
}

Consert::~Consert()
{
	for (int i = 0; i < 10; i++)
	{
		if (animalPtr[i] != nullptr);
			delete animalPtr[i];
	}
}
