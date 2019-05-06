#ifndef BIDIRECTIONALLIST_H
#define BIDIRECTIONALLIST_H
#include <iostream>
using namespace std;

class BidirectionalList
{
	friend ostream& operator<<(ostream& out, const BidirectionalList& tgt);

private:
	typedef int eletype;
	struct celltype{
		eletype element;
		celltype* next, * previous;
	};
	typedef celltype* LIST;
	LIST innerlist;

public:
	typedef celltype* pos;
	pos makeNull();

	BidirectionalList();
	BidirectionalList(eletype tgt[], int len);
	void Insert(eletype x, pos p);
	void Delete(pos p);
	pos Locate(eletype x);
	eletype Retrieve(pos p);
	pos Prevoius(pos p);
	pos Next(pos p);
	pos First();
	pos End();
	BidirectionalList operator+(const BidirectionalList& tgt);
	void operator=(const BidirectionalList& tgt);
	bool isEmpty();
};

#endif

