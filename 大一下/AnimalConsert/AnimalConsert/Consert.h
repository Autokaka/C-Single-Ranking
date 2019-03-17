#ifndef CONSERT_H
#define CONSERT_H

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "Sheep.h"
#include "Cow.h"
#include "Pig.h"

class Consert
{
public:
	Consert();
	void regist();
	void Singsongs();
	~Consert();
private:
	Animal * animalPtr[10];
};

#endif

