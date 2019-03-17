#include "stdafx.h"
#include "Pig.h"
#include <iostream>
using namespace std;

Pig::Pig(string animalname)
	:Animal(animalname)
{
	name = animalname;
}

void Pig::Sing() const
{
	cout << "ÎÒÊÇÐ¡Öí " << name << " ºßºßºß~" << endl;
}
