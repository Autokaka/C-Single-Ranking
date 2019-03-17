#include "stdafx.h"


#include <iostream>
using namespace std;
#include "Polynomial.h"


Polynomial::Polynomial(int length)
{
	while (length < 0)
	{
		cout << "输入的项数不符合条件，请重新输入！  ";
		cin >> length;
	}

	size = length;
	sPtr = new int[2 * size + 1];
	for (int i = 1; i <= 2 * size; i++)
		sPtr[i] = 0;
}
Polynomial::Polynomial(const Polynomial &copy)
	:size(copy.size)
{
	setPolynomial(copy.sPtr);
}
void Polynomial::setPolynomial(const int *copy_sPtr)
{
	if (sPtr != 0)
		delete[]sPtr;
	sPtr = new int[2 * size + 1];
	for (int i = 1; i <= 2 * size; i++)
		sPtr[i] = copy_sPtr[i];
}

const Polynomial Polynomial::operator+(const Polynomial &operand)
{
	Polynomial temp(size + operand.size);
	int i = 1;
	for (i; i <= 2 * size; i++)
		temp.sPtr[i] = sPtr[i];
	for (i; i <= 2 * temp.size; i++)
		temp.sPtr[i] = operand.sPtr[i - 2 * size];

    //合并同类项
	organizePolynomial(temp);
	return temp;
}
const Polynomial Polynomial::operator-(const Polynomial &operand)
{
	Polynomial temp(size + operand.size);
	for (int i = 1; i <= 2 * size; i++)
		temp.sPtr[i] = sPtr[i];
	for (int i = size + 1; i <= temp.size; i++)
	{
		temp.sPtr[2 * i - 1] = -operand.sPtr[2 * (i - size) - 1];
		temp.sPtr[2 * i] = operand.sPtr[2 * (i - size)];
	}
	//合并同类项
	organizePolynomial(temp);
	return temp;
}
const Polynomial Polynomial::operator*(const Polynomial &operand)
{
	Polynomial temp(size * operand.size);
	int cnt = 0;
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= operand.size; j++)
		{
			cnt++;
			temp.sPtr[2 * cnt - 1] = sPtr[2 * i - 1] * operand.sPtr[2 * j - 1];
			temp.sPtr[2 * cnt] = sPtr[2 * i] + operand.sPtr[2 * j];
		}
	organizePolynomial(temp);
	return temp;
}
const Polynomial &Polynomial::operator=(const Polynomial &operand)
{
	if (*this != operand)
	{
		delete[]sPtr;
		size = operand.size;
		setPolynomial(operand.sPtr);
	}
	return *this;
}
const Polynomial &Polynomial::operator+=(const Polynomial &operand)
{
	int *temp1 = new int[2 * (size + operand.size) + 1];
	int i = 1;
	for (i; i <= 2 * size; i++)
		temp1[i] = sPtr[i];
	for (i; i <= 2 * (size + operand.size); i++)
		temp1[i] = operand.sPtr[i - 2 * size];
	
	size += operand.size;
	delete[]sPtr;
	sPtr = temp1;

	//合并同类项
	organizePolynomial(*this);
	return *this;
}
const Polynomial &Polynomial::operator-=(const Polynomial &operand)
{
	int *temp1 = new int[2 * (size + operand.size) + 1];
	for (int i = 1; i <= 2 * size; i++)
		temp1[i] = sPtr[i];
	for (int i = size + 1; i <= size + operand.size; i++)
	{
		temp1[2 * i - 1] = -operand.sPtr[2 * (i - size) - 1];
		temp1[2 * i] = operand.sPtr[2 * (i - size)];
	}

	size += operand.size;
	delete[]sPtr;
	sPtr = temp1;

	//合并同类项
	organizePolynomial(*this);
	return *this;
}
const Polynomial &Polynomial::operator*=(const Polynomial &operand)
{
	int *temp2 = new int[2 * (size*operand.size) + 1];
	int cnt = 0;
	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= operand.size; j++)
		{
			cnt++;
			temp2[2 * cnt - 1] = sPtr[2 * i - 1] * operand.sPtr[2 * j - 1];
			temp2[2 * cnt] = sPtr[2 * i] + operand.sPtr[2 * j];
		}
	size *= operand.size;
	delete[]sPtr;
	sPtr = temp2;
	organizePolynomial(*this);

	return *this;
}

const bool Polynomial::operator==(const Polynomial &operand)
{
	if (size != operand.size)
		return false;
	for (int i = 1; i <= 2 * size; i++)
		if (sPtr[i] != operand.sPtr[i])
			return false;
	return true;
}
const bool Polynomial::operator!=(const Polynomial &operand)
{
	return !(operator==(operand));
}

void Polynomial::insertPolynomial()
{
	cout << "\n * 输入您的多项式（格式：系数+空格+参数.支持连续输入.）\n";
	for (int i = 1; i <= size; i++)
	{
		cout << "\n第 " << i << " 项：  ";
		cin >> sPtr[2 * i - 1] >> sPtr[2 * i];
		cout << endl;
	}

	//合并同类项
	organizePolynomial(*this);
}

void Polynomial::organizePolynomial(Polynomial &operand)
{
	for (int i = 1; i <= operand.size - 1; i++)
		for (int j = operand.size; j >= i + 1; j--)
			if (operand.sPtr[2 * j] == operand.sPtr[2 * i] && !(operand.sPtr[2 * j] == 0 && operand.sPtr[2 * j - 1] == 0))
			{
				operand.sPtr[2 * i - 1] += operand.sPtr[2 * j - 1];
				operand.sPtr[2 * j] = operand.sPtr[2 * j - 1] = 0;
			}

	int delnum = 0;
	for (int i = 1; i <= operand.size; i++)
		if (operand.sPtr[2 * i - 1] == 0)
			delnum++;

	int *temp2 = new int[2 * (operand.size - delnum) + 1];
	for (int i = 1; i <= 2 * (operand.size - delnum); i++)
		temp2[i] = 0;

	int cnt = 1;
	for (int i = 1; i <= operand.size; i++)
		if (operand.sPtr[2 * i - 1] != 0)
		{
			temp2[cnt] = operand.sPtr[2 * i - 1];
			temp2[cnt + 1] = operand.sPtr[2 * i];
			cnt += 2;
		}

	operand.size -= delnum;
	delete[]operand.sPtr;
	operand.sPtr = temp2;

}

ostream &operator<<(ostream &output, const Polynomial &operand)
{
	if (&operand.sPtr == 0)
	{
		output << "(空)";
		return output;
	}
	for (int i = 1; i <= operand.size; i++)
		if (operand.sPtr[2 * i])
		{
			if (i == 1)
			{
				if (operand.sPtr[2 * i - 1] < 0)
					output << " - " << -operand.sPtr[2 * i - 1] << "x^" << operand.sPtr[2 * i];
				else
					output << operand.sPtr[2 * i - 1] << "x^" << operand.sPtr[2 * i];
			}
			else
			{
				if (operand.sPtr[2 * i - 1] < 0)
					output << " - " << -operand.sPtr[2 * i - 1] << "x^" << operand.sPtr[2 * i];
				else
					output << " + " << operand.sPtr[2 * i - 1] << "x^" << operand.sPtr[2 * i];
			}
		}
		else
		{
			if (i == 1)
			{
				if (operand.sPtr[2 * i - 1] < 0)
					output << " - " << -operand.sPtr[2 * i - 1];
				else
					output << operand.sPtr[2 * i - 1];
			}
			else
			{
				if (operand.sPtr[2 * i - 1] < 0)
					output << " - " << -operand.sPtr[2 * i - 1];
				else
					output << " + " << operand.sPtr[2 * i - 1];
			}
		}
	output << endl;
	return output;
}

Polynomial::~Polynomial()
{
	delete[]sPtr;
}
