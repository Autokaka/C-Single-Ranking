#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
using namespace std;

class Package
{
public:
	Package(string, string, string, string, string, int, double, double);

	string getSender();
	string getReceiver();

	string getProvince();
	string getCity();
	string getAddress();
	int getPostcode();

	double getWeight();
	double getfarePerweight();

	double calculateCost();

	void print();

protected:
	void setWeight(double);

private:
	string sender;
	string receiver;

	string address;
	string city;
	string province;
	int postcode;

	double weight;
	double fareperweight;
};

#endif
