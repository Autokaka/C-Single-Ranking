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
	cout << "__________��ǰ__________\n";
	cout << "����1��"; set1.printSet(); 
	cout << endl;
	cout << "����2��"; set2.printSet(); 
	cout << endl;

	cout << "__________��ֵ__________\n"
		 << "����1��\n"; set1.insertElement();
	cout << endl;
	cout << "����2��\n"; set2.insertElement();
	cout << endl;

	cout << "__________ɾֵ__________\n"
		 << "����1��\n"; set1.deleteElement();
	cout << endl;
	cout << "����2��\n"; set2.deleteElement();
	cout << endl;

	cout << "__________�󲢼�__________\n"; 
	IntergerSet set3 = set1 + set2;
	set3.printSet();

	system("pause");
	return 0;
}