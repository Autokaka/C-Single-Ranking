#ifndef DOG_H
#define DOG_H

#include <string>
using namespace std;
#include "Animal.h"

class Dog :public Animal
{
public:
	Dog(string);
	virtual void Sing() const;
private:
	string name;
};

#endif