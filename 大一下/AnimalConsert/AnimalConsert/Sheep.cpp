#include "stdafx.h"
#include "Sheep.h"
#include <iostream>
using namespace std;

Sheep::Sheep(string animalname)
	:Animal(animalname)
{
	name = animalname;
}

void Sheep::Sing() const
{
	cout << "ÎÒÊÇÐ¡Ñò " << name << " ßãßãßã~" << endl;
}
