#include "stdafx.h"
#include <iostream>
#include "LibraryCard.h"
using namespace std;

int main()
{
	LibraryCard libcard;
	/*���Խӿ�*/libcard.refreshDatabase();
	for (int i = 1; i <= 3; i++)
	{
		libcard.regist();
		libcard.printID();
	}
	libcard.login();

	system("pause");
	return 0;
}