#ifndef CURSORLIST_H
#define CURSORLIST_H
#include <iostream>
using namespace std;

class CursorList
{
	static const int maxlen = 100;
	friend ostream& operator<<(ostream& out, const CursorList& tgt);

private:
	typedef int eletype;
	typedef struct {
		eletype element;
		int next;
	} space;
	typedef int pos, cursor;
	cursor available, head;

	static bool isFirstInit;
	static space SPACE[maxlen];
	static void initSpace();
public:
	CursorList();
	CursorList(eletype tgt[], int len);

	cursor getNode();
	void freeNode(cursor tgt);

	void Insert(eletype x, pos p);
	void Delete(pos p);

	cursor First();
	cursor End();

	bool isEmpty();
	bool isFull();

	CursorList operator+(const CursorList& tgt);
};

#endif

