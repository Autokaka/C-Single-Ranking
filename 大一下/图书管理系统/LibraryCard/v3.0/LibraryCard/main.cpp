#include "stdafx.h"
#include <iostream>
#include "LibraryCard.h"
using namespace std;

int main()
{
	LibraryCard libcard;
	
	//���Խӿ�
	char exit = ' ';
	cout << "\n* ִ�����ݿ������𣿣�y/n����  ";
	cin >> exit;
	if (exit=='y')
		libcard.refreshDatabase();
	else
	{
		libcard.login();
		int currentClient = libcard.getNumber();
		libcard.withdraw(currentClient);
		libcard.printID();
	}

	for (int i = 1; i <= 3; i++)
	{
		libcard.regist();
		libcard.printID();
	}
	string shujibianhao;
	libcard.login();
	int currentClient = libcard.getNumber();
	if (currentClient)
	{
		for (int i = 1; i <= 3; i++)
		{
			cout << "\n______________________________�鼮����______________________________\n" << endl;
			cout << "\n * ��������鼮��ţ�  ";
			cin >> shujibianhao;
			libcard.borrowTag(currentClient, shujibianhao);
			libcard.printID();
		}
		for (int i = 1; i <= 3; i++)
		{
			cout << "\n______________________________�鼮�黹______________________________\n" << endl;
			cout << "\n * ���뻹���鼮��ţ�  ";
			cin >> shujibianhao;
			libcard.returnTag(currentClient, shujibianhao);
			libcard.printID();
		}
	}

	libcard.modify(currentClient);
	libcard.printID();

	system("pause");
	return 0;
}