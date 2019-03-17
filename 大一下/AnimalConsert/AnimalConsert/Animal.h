#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Animal
{
public:
	Animal(string);
	virtual void Sing() const = 0;
private:
	string name;
};

#endif