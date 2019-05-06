#include "Polynome.h"
#include <vector>

Polynome::Polynome()
{
	innpoly = makeNull(innpoly);
}

void Polynome::Insert(eletype coef, int expo) {
	if (coef == 0) return;
	pos srch = innpoly;
	while (srch->next != NULL) {
		srch = srch->next;
		if (srch->expo == expo) {
			srch->coef += coef;
			return;
		}
	}
	LIST add = new celltype;
	add->coef = coef;
	add->expo = expo;
	add->next = innpoly->next;
	innpoly->next = add;
}
void Polynome::Delete(pos p) {
	pos del = p->next;
	p->next = del->next;
	delete del;
}
Polynome::LIST Polynome::makeNull(LIST tgt) {
	tgt = new celltype;
	tgt->next = NULL;
	return tgt;
}
void Polynome::align() {
	pos srch = innpoly;
	vector<pos> del;
	while (srch->next != NULL) {
		if (srch->next->coef == 0) {
			del.push_back(srch);
			srch = srch->next;
			continue;
		}
		srch = srch->next;
		pos srch2 = srch;
		while (srch2->next != NULL) {
			srch2 = srch2->next;
			if (srch->expo == srch2->expo && srch2->coef != 0) {
				srch->coef += srch2->coef;
				srch2->coef = 0;
			}
		}
	}
	for (int i = 0; i < del.size(); i++) Delete(del[i]);
}

Polynome Polynome::operator+(const Polynome& tgt) {
	Polynome merge = Polynome();
	pos srch = innpoly;
	while (srch->next != NULL) {
		srch = srch->next;
		merge.Insert(srch->coef, srch->expo);
	}
	srch = tgt.innpoly;
	while (srch->next != NULL) {
		srch = srch->next;
		merge.Insert(srch->coef, srch->expo);
	}
	return merge;
}
Polynome Polynome::operator*(const Polynome& tgt) {
	Polynome merge = Polynome();
	pos srch = innpoly;
	while (srch->next != NULL) {
		srch = srch->next;
		pos srch2 = tgt.innpoly;
		while (srch2->next != NULL) {
			srch2 = srch2->next;
			merge.Insert(srch->coef * srch2->coef, srch->expo + srch2->expo);
		}
	}
	merge.align();//合并同类项
	return merge;
}
ostream& operator<<(ostream& out, const Polynome& tgt)
{
	Polynome::pos srch = tgt.innpoly;
	while (srch->next != NULL) {
		srch = srch->next;
		if (srch->coef == 0) continue;
		out << (srch->coef > 0 ? "+" : "-");
		if (srch->coef != 1) out << (srch->coef > 0? srch->coef : -srch->coef);
		if (srch->expo != 0) {
			out << "x";
			if (srch->expo == 1) continue;
			out << (srch->expo < 0 ? "^(-" : "^");
			if (srch->expo < 0) out << -srch->expo << ")";
			else out << srch->expo;
		}
	}
	out << " ";
	return out;
}
void Polynome::operator=(const Polynome& tgt) {
	pos srch = tgt.innpoly;
	innpoly = makeNull(innpoly);
	while (srch->next != NULL)
	{
		srch = srch->next;
		Insert(srch->coef, srch->expo);
	}
}
bool Polynome::isEmpty() {
	return (innpoly->next == NULL);
}
