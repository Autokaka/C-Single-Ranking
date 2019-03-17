#ifndef LAPOINTERLIST_H
#define LAPOINTERLIST_H

class LaPointerList
{
	struct celltype
	{
		int element;
		celltype* next;
	};
	typedef celltype* LIST;
	typedef celltype* pos;
	public:
		LIST mylist;
		LaPointerList();
		void Insert(int x, LIST tgt);
		LIST Makenull(LIST &tgt);
		pos End(LIST tgt);
		pos Locate(int x, LIST tgt);
		pos Previous(pos p, LIST tgt);
		
		void Delete(LIST tgt);
		
	private:
		
};

#endif

