#ifndef CAT_H
#define CAT_H

#include <string>
using namespace std;
#include "Animal.h"

class Cat :public Animal
{
public:
	Cat(string);
	virtual void Sing() const;
private:
	string name;
};

#endif