#ifndef COW_H
#define COW_H

#include <string>
using namespace std;
#include "Animal.h"

class Cow :public Animal
{
public:
	Cow(string);
	virtual void Sing() const;
private:
	string name;
};

#endif