#include "LaArrayList.h"
#include <iostream>
using namespace std;

LaArrayList::LaArrayList(eletype in[], int len) {
	if (len >= maxlen)
	{
		cout << "Sorry, your array has too many elements. Initializing failed. Aborting...\n";
		return;
	}
	Makenull();
	for (int i = 0; i < len; i++) innerlist.elements[++innerlist.last] = in[i];
}
LaArrayList::LaArrayList() {
	Makenull();
}

LaArrayList::pos LaArrayList::Makenull(LIST &tgt) {
	tgt.last = 0;
	return tgt.last;
}
LaArrayList::pos LaArrayList::Makenull() {
	return Makenull(innerlist);
}

void LaArrayList::Insert(eletype x, pos p, LIST& tgt) {
	int len = sizeof(tgt.elements) / sizeof(*(tgt.elements));
	if (p > len - 1)
	{
		cout << "Sorry, list is full, Insert Operation failed. Aborting...\n";
		return;
	}
	for (int i = tgt.last; i >= p; i--) tgt.elements[i + 1] = tgt.elements[i];
	tgt.elements[p] = x;
}
void LaArrayList::Insert(eletype x, pos p) {
	Insert(x, p, innerlist);
}

LaArrayList::pos LaArrayList::Locate(eletype x, LIST tgt) {
	for (int i = 1; i <= tgt.last; i++) if (tgt.elements[i] == x) return i;
	return -1;
}
LaArrayList::pos LaArrayList::Locate(eletype x) {
	return Locate(x, innerlist);
}

LaArrayList::eletype LaArrayList::Retrieve(pos p, LIST tgt) {
	if (p < 1)
	{
		cout << "Invalid operation. Aborting...\n";
		return -1;
	}
	if (tgt.last == 0)
	{
		cout << "Sorry, list is empty. Retrieve operation failed. Aborting...\n";
		return -1;
	}
	if (p > tgt.last)
	{
		cout << "Sorry, position p is out of border. Retrieve operation failed. Aborting...\n";
		return -1;
	}
	return tgt.elements[p];
}
LaArrayList::eletype LaArrayList::Retrieve(pos p) {
	return Retrieve(p, innerlist);
}

void LaArrayList::Delete(pos p, LIST &tgt) {
	if (p <= tgt.last && p >= 1) {
		for (int i = p; i < tgt.last; i++) tgt.elements[i] = tgt.elements[i + 1];
		tgt.last--;
	}
}
void LaArrayList::Delete(pos p) {
	Delete(p, innerlist);
}

LaArrayList::pos LaArrayList::Prevoius(pos p, LIST tgt) {
	if (p <= 1 || p > tgt.last) {
		cout << "Sorry, position doesn't have a previous node. Aborting...\n";
		return -1;
	}
	return (p - 1);
}
LaArrayList::pos LaArrayList::Prevoius(pos p) {
	return Prevoius(p, innerlist);
}

LaArrayList::pos LaArrayList::Next(pos p, LIST tgt) {
	if (p < 1 || p >= tgt.last) {
		cout << "Sorry, position doesn't have a previous node. Aborting...\n";
		return -1;
	}
	return (p + 1);
}
LaArrayList::pos LaArrayList::Next(pos p) {
	return Next(p, innerlist);
}

LaArrayList::pos LaArrayList::First(LIST tgt) {
	return 1;
}
LaArrayList::pos LaArrayList::First() {
	return First(innerlist);
}

LaArrayList::pos LaArrayList::End(LIST tgt) {
	return tgt.last;
}
LaArrayList::pos LaArrayList::End() {
	return End(innerlist);
}

void LaArrayList::showContent(LIST tgt) {
	if (isEmpty(tgt)) cout << "(Пе)";
	else for (int i = 1; i <= tgt.last; i++) cout << tgt.elements[i] << " ";
	cout << endl;
}
void LaArrayList::showContent() {
	showContent(innerlist);
}

LaArrayList::eletype* LaArrayList::getContent(LIST tgt) {
	return tgt.elements;
}
LaArrayList::eletype* LaArrayList::getContent() {
	return getContent(innerlist);
}

LaArrayList LaArrayList::operator+(const LaArrayList& tgt) {
	int len1 = this->innerlist.last, len2 = tgt.innerlist.last;
	LaArrayList mergeList;
	if (len1 + len2 <= maxlen) {
		int i = 1;
		for (i; i <= len1; i++) {
			mergeList.innerlist.elements[i] = this->innerlist.elements[i];
			mergeList.innerlist.last++;
		}
		for (i; i <= len1 + len2; i++) {
			mergeList.innerlist.elements[i] = tgt.innerlist.elements[i - len1];
			mergeList.innerlist.last++;
		}
	}
	return mergeList;
}
ostream& operator<<(ostream& out, const LaArrayList& tgt) {
	if (tgt.innerlist.last == 0) out << "(Пе)";
	else for (int i = 1; i <= tgt.innerlist.last; i++) out << tgt.innerlist.elements[i] << " ";
	return out;
}
void LaArrayList::operator=(const LaArrayList& tgt) {
	for (int i = 1; i <= tgt.innerlist.last; i++) innerlist.elements[++innerlist.last] = tgt.innerlist.elements[i];
}

bool LaArrayList::isEmpty(LIST tgt) {
	if (tgt.last == 0) return true;
	return false;
}
bool LaArrayList::isEmpty() {
	return isEmpty(innerlist);
}
