#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
#include "Package.h"

class TwoDayPackage : public Package
{
public:
	TwoDayPackage(string, string, string, string, string, int, double, double, double);
	
	double calculateCost();

	void print();

private:
	double twodayfare;
};
#endif

