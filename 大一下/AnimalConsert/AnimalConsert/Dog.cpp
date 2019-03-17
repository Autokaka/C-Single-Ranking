#include "stdafx.h"
#include "Dog.h"
#include <iostream>
using namespace std;

Dog::Dog(string animalname)
	:Animal(animalname)
{
	name = animalname;
}

void Dog::Sing() const
{
	cout << "ÎÒÊÇÐ¡¹· " << name << " ÍôÍôÍô~" << endl;
}
