#pragma once
#define maxlen 100

class LaArrayList
{
private:
	typedef int eletype;//以后想改其他类型就把int字段改掉
	struct LIST
	{
		eletype elements[maxlen];
		int last;
	};
	LIST L;
	typedef int pos;
	

public:
	LaArrayList();
	void Insert(eletype x, pos p, LIST &tgt);
	void Insert(eletype x, pos p);
	pos Locate(eletype x, LIST tgt);
	pos Locate(eletype x);

};

