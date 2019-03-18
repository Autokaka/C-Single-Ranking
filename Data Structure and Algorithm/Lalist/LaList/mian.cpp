#include <iostream>
#include "LaPointerList.h"
using namespace std;

int main()
{
	LaPointerList la;
	for (int i = 0; i < 10; i++) la.Insert(i, la.mylist);
	la.Delete(la.Locate(5, la.mylist));
	la.showContent(la.mylist);
}