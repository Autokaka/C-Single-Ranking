#pragma once
#define maxlen 100

class LaArrayList
{
private:
	typedef int eletype;//�Ժ�����������;Ͱ�int�ֶθĵ�
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

