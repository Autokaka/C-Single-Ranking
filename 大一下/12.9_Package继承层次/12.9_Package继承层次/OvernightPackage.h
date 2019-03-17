#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
#include "Package.h"

class OvernightPackage : public Package
{
public:
	OvernightPackage(string, string, string, string, string, int, double, double, double);

	double calculateCost();
	void print();

private:
	double overnightfare;
};

#endif