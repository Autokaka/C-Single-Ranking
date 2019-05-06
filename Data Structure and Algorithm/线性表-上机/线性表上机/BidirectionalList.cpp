#include "BidirectionalList.h"

BidirectionalList::BidirectionalList() {
	innerlist = makeNull();
}
BidirectionalList::BidirectionalList(eletype tgt[], int len) {
	innerlist = makeNull();
	for (int i = 0; i < len; i++) Insert(tgt[i], First());
}

BidirectionalList::pos BidirectionalList::makeNull() {
	innerlist = new celltype;
	innerlist->previous = NULL;
	innerlist->next = NULL;
	return innerlist;
}

void BidirectionalList::Insert(eletype x, pos p) {
	if (isEmpty()) {
		pos add = new celltype;
		add->element = x;
		add->next = NULL;
		add->previous = p;
		p->next = add;
		return;
	}
	pos add = new celltype;
	add->element = x;
	add->next = p->next;
	add->previous = p;
	p->next->previous = add;
	p->next = add;
}
BidirectionalList::pos BidirectionalList::Locate(eletype x) {
	pos srch = innerlist;
	while (srch->next != NULL) {
		srch = srch->next;
		if (srch->element == x) return srch->previous;
	}
	return srch;
}
BidirectionalList::eletype BidirectionalList::Retrieve(pos p) {
	return p->next->element;
}
void BidirectionalList::Delete(pos p) {
	pos del = p->next;
	p->next = del->next;
	del->next->previous = p;
	delete del;
}

BidirectionalList::pos BidirectionalList::First() {
	return innerlist;
}
BidirectionalList::pos BidirectionalList::End() {
	pos srch = innerlist;
	while (srch->next != NULL) srch = srch->next;
	return srch;
}
BidirectionalList::pos BidirectionalList::Prevoius(pos p) {
	return p->previous;
}
BidirectionalList::pos BidirectionalList::Next(pos p) {
	return p->next;
}
bool BidirectionalList::isEmpty() {
	return (innerlist->next == NULL);
}

ostream& operator<<(ostream& out, const BidirectionalList& tgt) {
	BidirectionalList::pos srch = tgt.innerlist;
	while (srch->next != NULL) {
		srch = srch->next;
		cout << srch->element << " ";
	}
	return out;
}
