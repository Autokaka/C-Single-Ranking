#include "stdafx.h"


#include <iostream>
using namespace std;
#include "Complex.h"


Complex::Complex(double realPart, double imaginaryPart)
	:real(realPart),imaginary(imaginaryPart)
{
}

Complex Complex::operator+(const Complex &operand2) const
{
	return Complex(real + operand2.real, imaginary + operand2.imaginary);
}
Complex Complex::operator-(const Complex &operand2) const
{
	return Complex(real - operand2.real, imaginary - operand2.imaginary);
}
Complex Complex::operator*(const Complex &operand2) const
{
	return Complex(real*operand2.real - imaginary * operand2.imaginary, real * operand2.imaginary + imaginary * operand2.real);
}
bool Complex::operator==(const Complex &operand2) const
{
	return (real == operand2.real&&imaginary == operand2.imaginary);
}
bool Complex::operator!=(const Complex &operand2) const
{
	return !(real == operand2.real&&imaginary == operand2.imaginary);
}

ostream &operator<<(ostream &output, const Complex &operand)
{
	output << "(" << operand.real << "," << operand.imaginary << ")";
	return output;
}
istream &operator>>(istream &input, Complex &operand)
{
	input >> operand.real;
	input.ignore();
	input >> operand.imaginary;
	return input;
}