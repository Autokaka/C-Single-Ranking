#include <iostream>
using namespace std;
#include "LaPointerList.h"

LaPointerList::LaPointerList()
{
	mylist = new celltype;
}

LaPointerList::LIST LaPointerList::Makenull(LIST &tgt)
{
	tgt = new celltype;
	tgt->next = NULL;
	return tgt;
}
LaPointerList::LIST LaPointerList::Makenull()
{
	Makenull(mylist);
}

void LaPointerList::Insert(int x, LIST tgt)
{
	LIST add = Makenull(add);
	add->element = x;
	add->next = tgt->next;
	tgt->next = add;
}
void LaPointerList::Insert(int x)
{
	Insert(x, mylist);
}

void LaPointerList::Delete(LIST tgt)
{
	LIST del = tgt->next;
	tgt->next = del->next;
	del = Makenull(del);
}

LaPointerList::pos LaPointerList::End(LIST tgt)
{
	LIST srch = tgt;
	if (srch->next != NULL) srch = srch->next;
	return srch;
}
LaPointerList::pos LaPointerList::End()
{
	End(mylist);
}

LaPointerList::pos LaPointerList::Locate(int x, LIST tgt)
{
	pos srch = tgt;
	while (srch->next != NULL)
	{
		if (srch->next->element != x) srch = srch->next;
		else return srch;
	}
	cout << "Sorry, " << x << "is not in the list. Aborting...\n";
}

LaPointerList::pos LaPointerList::Previous(pos p, LIST tgt)
{
	if (p != tgt->next) 
	{
		pos srch = tgt;
		while (srch->next != p) srch = srch->next;
		if (srch != End(tgt)) return srch;
		else cout << "Sorry, position " << p << " is not in the list. Aborting...\n";
	}
	cout << "Sorry, position " << p << "has no former element. Aborting...\n";
}

LaPointerList::pos LaPointerList::Next(pos p, LIST tgt)
{
	if (p->next != NULL) return p->next;
	cout << "Sorry, position " << p << "has no latter element. Aborting...\n";
}

LaPointerList::pos LaPointerList::First(LIST tgt)
{
	return tgt;
}

void LaPointerList::showContent(LIST tgt)
{
	pos srch = tgt->next;
	bool said = false;
	while (srch != NULL)
	{
		cout << srch->element << " ";
		said = true;
		srch = srch->next;
	}
	if (!said) cout << "(null)";
}