#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using std::ostream;
using std::istream;

class Polynomial
{
	friend ostream &operator<<(ostream &, const Polynomial &);
public:
	Polynomial(int = 0);
	Polynomial(const Polynomial &);
	void setPolynomial(const int *);

	void insertPolynomial();

	const Polynomial operator+(const Polynomial &);
	const Polynomial operator-(const Polynomial &);
	const Polynomial operator*(const Polynomial &);
	const Polynomial &operator=(const Polynomial &);
	const Polynomial &operator+=(const Polynomial &);
	const Polynomial &operator-=(const Polynomial &);
	const Polynomial &operator*=(const Polynomial &);

	const bool operator==(const Polynomial &);
	const bool operator!=(const Polynomial &);

	~Polynomial();
private:
	void organizePolynomial(Polynomial &);
	int *sPtr;
	int size;//项的个数
};

#endif