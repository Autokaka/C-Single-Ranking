#ifndef LAPOINTERLIST_H
#define LAPOINTERLIST_H
#include <iostream>
using namespace std;

class LaPointerList
{
	friend ostream& operator<<(ostream& out, const LaPointerList& tgt);
	
	private:
		typedef int eletype;
		struct celltype {
			eletype element;
			celltype* next;
		};
		typedef celltype* LIST;
		LIST innerlist;
		celltype* seq2pos(int seq, LIST tgt);
		celltype* seq2pos(int seq);
	
	public:
		typedef celltype* pos;
		LaPointerList();
		LaPointerList(eletype tgt[], int len);
		void Insert(int x, LIST tgt);
		void Insert(int x);
		void Delete(int seq);
		LIST Makenull(LIST &tgt);
		LIST Makenull();
		pos End(LIST tgt);
		pos End();
		int Locate(int x, LIST tgt);
		int Locate(int x);
		pos Previous(pos p, LIST tgt);
		pos Previous(pos p);
		pos Next(pos p, LIST tgt);
		pos Next(pos p);
		pos First(LIST tgt);
		pos First();
		LaPointerList operator+(const LaPointerList& tgt);
		void operator=(const LaPointerList& tgt);
		void showContent(LIST tgt);
		void showContent();
		bool isEmpty(LIST tgt);
		bool isEmpty();
};

#endif

