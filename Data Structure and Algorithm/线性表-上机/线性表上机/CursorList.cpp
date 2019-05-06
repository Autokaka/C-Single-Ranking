#include "CursorList.h"

bool CursorList::isFirstInit(true);
CursorList::space CursorList::SPACE[maxlen];
CursorList::CursorList() {
	if (CursorList::isFirstInit) initSpace();
	available = 0;
	head = getNode();
}
CursorList::CursorList(eletype tgt[], int len) {
	if (CursorList::isFirstInit) initSpace();
	available = 0;
	head = getNode();
	for (int i = 0; i < len; i++) Insert(tgt[i], End());
}
void CursorList::initSpace() {
	for (int i = 0; i < maxlen - 1; i++) CursorList::SPACE[i].next = i + 1;
	CursorList::SPACE[maxlen - 1].next = -1;
	CursorList::isFirstInit = false;
}

CursorList::cursor CursorList::getNode() {
	if (isFull()) return -1;
	cursor get = CursorList::SPACE[available].next;
	CursorList::SPACE[available].next = CursorList::SPACE[get].next;
	CursorList::SPACE[get].next = -1;
	return get;
}
void CursorList::freeNode(cursor tgt) {
	CursorList::SPACE[tgt].next = CursorList::SPACE[available].next;
	CursorList::SPACE[available].next = tgt;
}

void CursorList::Insert(eletype x, pos p) {
	if (!isFull()) {
		cursor get = getNode();
		CursorList::SPACE[get].element = x;
		CursorList::SPACE[get].next = CursorList::SPACE[p].next;
		CursorList::SPACE[p].next = get;
	}
}
void CursorList::Delete(pos p) {
	if (CursorList::SPACE[p].next != -1) {
		cursor del = CursorList::SPACE[p].next;
		CursorList::SPACE[p].next = CursorList::SPACE[del].next;
		freeNode(del);
	}
}

CursorList::cursor CursorList::First() {
	return head;
}
CursorList::cursor CursorList::End() {
	cursor srch = head;
	while (CursorList::SPACE[srch].next != -1) srch = CursorList::SPACE[srch].next;
	return srch;
}

bool CursorList::isEmpty() {
	return (CursorList::SPACE[head].next == -1);
}
bool CursorList::isFull() {
	return (CursorList::SPACE[available].next == -1);
}

CursorList CursorList::operator+(const CursorList& tgt) {
	CursorList merge;
	merge.head = head;
	CursorList::SPACE[End()].next = CursorList::SPACE[tgt.head].next;
	freeNode(tgt.head);
	return merge;

}
ostream& operator<<(ostream& out, const CursorList& tgt) {
	if (tgt.head == -1) out << "(Пе)";
	else {
		CursorList::cursor srch = tgt.head;
		while (CursorList::SPACE[srch].next != -1) {
			srch = CursorList::SPACE[srch].next;
			out << CursorList::SPACE[srch].element << " ";
		}
	}
	return out;
}
