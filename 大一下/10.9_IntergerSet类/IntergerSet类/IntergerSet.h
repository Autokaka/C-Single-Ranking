#ifndef INTERGERSET_H
#define INTERGERSET_H

class IntergerSet
{
public:
	IntergerSet(int=100);

	void insertElement();
	void deleteElement();

	IntergerSet unionOfSets(IntergerSet);
	IntergerSet intersectionOfSets(IntergerSet);

	IntergerSet operator+(IntergerSet);

	bool isEqualTo(IntergerSet);
	void printSet() const;
private:
	int *Set;
	int nMax;
};

#endif