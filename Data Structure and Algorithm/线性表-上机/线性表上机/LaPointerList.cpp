#include "LaPointerList.h"

LaPointerList::LaPointerList()
{
	innerlist = Makenull();
}
LaPointerList::LaPointerList(eletype tgt[], int len) {
	innerlist = Makenull();
	for (int i = 0; i < len; i++) Insert(tgt[i]);
}

LaPointerList::LIST LaPointerList::Makenull(LIST &tgt)
{
	tgt = new celltype;
	tgt->next = NULL;
	return tgt;
}
LaPointerList::LIST LaPointerList::Makenull()
{
	return Makenull(innerlist);
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
	Insert(x, innerlist);
}

void LaPointerList::Delete(int seq)
{
	pos p = seq2pos(seq);
	pos del = p->next;
	p->next = del->next;
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
	return End(innerlist);
}

int LaPointerList::Locate(int x, LIST tgt)
{
	int dep = -1;
	pos srch = tgt;
	while (srch->next != NULL)
	{
		if (dep == -1) dep = 0;
		srch = srch->next;
		dep++;
		if (srch->element == x) break;
	}
	return dep;
}
int LaPointerList::Locate(int x)
{
	return Locate(x, innerlist);
}
//返回位置的前一个节点
LaPointerList::pos LaPointerList::seq2pos(int seq, LIST tgt) {
	pos srch = tgt;
	if (seq != -1) {
		int cnt = 0;
		while (cnt != (seq - 1)) {
			srch = srch->next;
			cnt++;
		}
	}
	return srch;
}
LaPointerList::pos LaPointerList::seq2pos(int seq) {
	return seq2pos(seq, innerlist);
}

LaPointerList::pos LaPointerList::Previous(pos p, LIST tgt)
{
	pos srch = tgt;
	if (p != tgt->next) 
	{
		while (srch->next != p) srch = srch->next;
		if (srch != End(tgt)) return srch;
	}
	return NULL;
}
LaPointerList::pos LaPointerList::Previous(pos p)
{
	return Previous(p, innerlist);
}

LaPointerList::pos LaPointerList::Next(pos p, LIST tgt)
{
	if (p->next != NULL) return p->next;
	return NULL;
}
LaPointerList::pos LaPointerList::Next(pos p)
{
	return Next(p, innerlist);
}

LaPointerList::pos LaPointerList::First(LIST tgt)
{
	return tgt;
}
LaPointerList::pos LaPointerList::First()
{
	return First(innerlist);
}

LaPointerList LaPointerList::operator+(const LaPointerList& tgt) {
	LaPointerList merge;
	pos srch = this->innerlist;
	while (srch->next != NULL) {
		srch = srch->next;
		merge.Insert(srch->element);
	}
	srch = tgt.innerlist;
	while (srch->next != NULL) {
		srch = srch->next;
		merge.Insert(srch->element);
	}
	return merge;
}
ostream& operator<<(ostream& out, const LaPointerList& tgt)
{
	LaPointerList::pos srch = tgt.innerlist;
	if (srch->next == NULL) {
		out << "(空)";
		return out;
	}
	while (srch->next != NULL)
	{
		srch = srch->next;
		out << srch->element << " ";
	}
	return out;
}
void LaPointerList::operator=(const LaPointerList& tgt) {
	pos srch = tgt.innerlist;
	while (srch->next != NULL)
	{
		srch = srch->next;
		Insert(srch->element);
	}
}

void LaPointerList::showContent(LIST tgt)
{
	pos srch = tgt;
	if (srch->next == NULL) {
		cout << "(空)\n";
		return;
	}
	while (srch->next != NULL)
	{
		srch = srch->next;
		cout << srch->element << " ";
	}
	cout << endl;
}
void LaPointerList::showContent()
{
	showContent(innerlist);
}

bool LaPointerList::isEmpty(LIST tgt) {
	return (End(tgt) == First(tgt));
}
bool LaPointerList::isEmpty() {
	return isEmpty(innerlist);
}
