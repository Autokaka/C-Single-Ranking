#include "stdafx.h"
#include "Cow.h"
#include <iostream>
using namespace std;

Cow::Cow(string animalname)
	:Animal(animalname)
{
	name = animalname;
}

void Cow::Sing() const
{
	cout << "ÎÒÊÇÐ¡Å£ " << name << " ßèßèßè~" << endl;
}
