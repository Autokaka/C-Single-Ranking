#ifndef SHEEP_H
#define SHEEP_H

#include <string>
using namespace std;
#include "Animal.h"

class Sheep :public Animal
{
public:
	Sheep(string);
	virtual void Sing() const;
private:
	string name;
};

#endif