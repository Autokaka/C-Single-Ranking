#include "stdafx.h"
#include "Cat.h"
#include <iostream>
using namespace std;

Cat::Cat(string animalname)
	:Animal(animalname)
{
	name = animalname;
}

void Cat::Sing() const
{
	cout << "ÎÒÊÇÐ¡Ã¨ " << name << " ß÷ß÷ß÷~" << endl;
}
