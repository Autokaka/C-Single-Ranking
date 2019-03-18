#ifndef LAPOINTERLIST_H
#define LAPOINTERLIST_H

class LaPointerList
{
	private:
		struct celltype
		{
			int element;
			celltype* next;
		};
		typedef celltype* LIST;
		typedef celltype* pos;
		LIST mylist;
	
	public:
		LaPointerList();
		void Insert(int x, LIST tgt);
		void Insert(int x);
		void Delete(LIST tgt);
		LIST Makenull(LIST &tgt);
		LIST Makenull();
		pos End(LIST tgt);
		pos End();
		pos Locate(int x, LIST tgt);
		pos Locate(int x);
		pos Previous(pos p, LIST tgt);
		pos Previous(pos p);
		pos Next(pos p, LIST tgt);
		pos Next(pos p);
		pos First(LIST tgt);
		pos First();
		void showContent(LIST tgt);
		void showContent();
};

#endif

