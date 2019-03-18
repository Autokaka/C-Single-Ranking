#include <iostream>
#include "LaPointerList.h"
using namespace std;

int main()
{
	LaPointerList list;
	for (int i = 0; i < 10; i++)
	{
		list.Insert(i);
	}
	list.showContent();
	return 0;
}