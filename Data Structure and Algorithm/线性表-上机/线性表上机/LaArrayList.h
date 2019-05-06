#ifndef LAARRAYLIST_H
#define LAARRAYLIST_H
#include <iostream>
using namespace std;

class LaArrayList
{
	static const int maxlen = 100;
	friend ostream& operator<<(ostream& out, const LaArrayList& tgt);
	
	private:
		typedef int eletype;//以后想改其他类型就把int字段改掉
		struct celltype
		{
			eletype elements[maxlen];
			int last;
		};
		typedef celltype LIST;
		LIST innerlist;

	public:
		typedef int pos;
		LaArrayList();
		LaArrayList(eletype in[], int len);
		void Insert(eletype x, pos p, LIST &tgt);
		void Insert(eletype x, pos p);
		pos Locate(eletype x, LIST tgt);
		pos Locate(eletype x);
		eletype Retrieve(pos p, LIST tgt);
		eletype Retrieve(pos p);
		void Delete(eletype x, LIST &tgt);
		void Delete(eletype x);
		pos Prevoius(pos p, LIST tgt);
		pos Prevoius(pos p);
		pos Next(pos p, LIST tgt);
		pos Next(pos p);
		pos Makenull(LIST &tgt);
		pos Makenull();
		pos First(LIST tgt);
		pos First();
		pos End(LIST tgt);
		pos End();
		void showContent(LIST tgt);
		void showContent();
		eletype* getContent(LIST tgt);
		eletype* getContent();
		LaArrayList operator+(const LaArrayList& tgt);
		void operator=(const LaArrayList& tgt);
		bool isEmpty(LIST tgt);
		bool isEmpty();
};

#endif