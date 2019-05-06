#ifndef POLYNOME_H
#define POLYNOME_H
#include <iostream>
using namespace std;

class Polynome
{
	friend ostream& operator<<(ostream& out, const Polynome& tgt);

private:
	typedef double eletype;
	struct celltype {
		eletype coef;//ϵ��
		int expo;//ָ��
		celltype* next;//��һ���
	};
	typedef celltype* LIST;
	typedef celltype* pos;
	LIST innpoly;

	LIST makeNull(LIST tgt);
	bool isEmpty();
	void align();
	void Delete(pos p);

public:
	Polynome();
	void Insert(eletype coef, int expo);
	Polynome operator+(const Polynome& tgt);
	Polynome operator*(const Polynome& tgt);
	void operator=(const Polynome& tgt);
};

#endif

