#include <iostream>
using namespace std;
#include "LaPointerList.h"

LaPointerList::LaPointerList()
{
	mylist = Makenull(mylist);
}

LaPointerList::LIST LaPointerList::Makenull(LIST &tgt)
{
	tgt = new celltype;
	tgt->next = NULL;
	return tgt;
}

void LaPointerList::Insert(int x, LIST tgt)
{
	LIST add = Makenull(add);
	add->element = x;
	add->next = tgt->next;
	tgt->next = add;
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
		return srch;
	}
	cout << "Sorry, position " << p << "has no former element. Aborting...\n";
}

