#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

#define MAXDIGITS 1000
#define PLUS 1
#define MINUS -1
#define LL long long

class bignum
{
	char digits[MAXDIGITS];
	int signbit;
	int lastdigit;
public:
	bignum();
	bignum(LL);
	bignum(char *);
	void digit_left_move(int d);
	void zero_justify()
	{
		int i;
		for (i = lastdigit; i >= 0; i--)
			if (digits[i] == '0')
				lastdigit--;
			else
				break;
	}
	bignum operator+(bignum &);
	bignum operator-(bignum &);
	bignum operator*(bignum &);
	friend int compare(const bignum &, const bignum &);//Î´Íê³É 
	friend ostream &operator<<(ostream &,const bignum &);
};

bignum::bignum()
{
	lastdigit = 0;
	for (int i = 0; i < MAXDIGITS; i++)
		digits[i] = '0';
}

bignum::bignum(LL k)
{
	bignum();
	if (k < 0)
		signbit = -1;
	else
		signbit = 1;
	lastdigit = -1;
	while (k)
	{
		digits[++lastdigit] = k % 10 + '0';
		k /= 10;
	}
}

bignum::bignum(char *s)
{
	bignum();
	int i;
	if (s[0] == '-')
	{
		signbit = -1;
		lastdigit = strlen(s) - 2;
		for (i = 1; i <= lastdigit + 1; i++)
			digits[i] = s[lastdigit - i];
	}	
	else
	{
		signbit = 1;
		lastdigit = strlen(s) - 1;
		for (i = 0; i < lastdigit + 1; i++)
			digits[i] = s[lastdigit - i];
	}	
}

bignum bignum::operator+(bignum &a)
{
	bignum c;
	int i, carry, t;
	if (signbit == a.signbit)
	{
		c.signbit = signbit;
		c.lastdigit = max(lastdigit, a.lastdigit) + 1;
		carry = 0;
		for (i = 0; i < c.lastdigit; i++)
		{
			t = digits[i] - '0' + a.digits[i] - '0' + carry;
			c.digits[i] = t % 10 + '0';
			carry = t / 10;
		}
		c.zero_justify();
	}
	else
	{
		if (signbit == MINUS)
		{
			signbit = PLUS;
			//c = a - *this;
			signbit = MINUS;
		}
		else
		{
			a.signbit = PLUS;
			//c = *this - a;
			a.signbit = MINUS;
		}
	}
	return c;
}

bignum bignum::operator-(bignum &a)
{
	if (signbit == MINUS || a.signbit == MINUS)
	{
		
	}
}

/*int compare(const bignum &a, const bignum &b)
{
	if (a.signbit == PLUS && b.signbit == MINUS)
		return PLUS;
	if (a.signbit ==  && b.signbit == PLUS)
		return MINUS;
	
	if (a.lastdigit > b.lastdigit)
		return PLUS * 
		
}*/

ostream &operator<<(ostream &cout,const bignum &bn)
{
	int i;
	if (bn.signbit == MINUS)
		cout << '-';
	for (i = bn.lastdigit; i >= 0; i--)
		cout << bn.digits[i];
}

int main()
{
	bignum bn("1234567");
	cout << bn << endl;
	bignum bn1(2345678);
	cout << bn1 << endl;
	
	cout << bn << " + " << bn1 << " = " << bn + bn1 << endl;
	return 0;
}

