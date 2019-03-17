#include "stdafx.h"
#include "stdlib.h"



#include <iostream>
using namespace std;
#include "IntergerSet.h"

int main()
{
	IntergerSet set1;
	IntergerSet set2;

	for(int i=1; i<=3; i++)
		cout << ".\n";
	cout << "__________当前__________\n";
	cout << "数组1："; set1.printSet(); 
	cout << endl;
	cout << "数组2："; set2.printSet(); 
	cout << endl;

	cout << "__________赋值__________\n"
		 << "数组1：\n"; set1.insertElement();
	cout << endl;
	cout << "数组2：\n"; set2.insertElement();
	cout << endl;

	cout << "__________删值__________\n"
		 << "数组1：\n"; set1.deleteElement();
	cout << endl;
	cout << "数组2：\n"; set2.deleteElement();
	cout << endl;

	cout << "__________求并集__________\n"; 
	IntergerSet set3 = set1 + set2;
	set3.printSet();

	system("pause");
	return 0;
}