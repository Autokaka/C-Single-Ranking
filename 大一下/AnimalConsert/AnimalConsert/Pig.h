#ifndef PIG_H
#define PIG_H

#include <string>
using namespace std;
#include "Animal.h"

class Pig :public Animal
{
public:
	Pig(string);
	virtual void Sing() const;
private:
	string name;
};

#endif