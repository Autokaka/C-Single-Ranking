#include "stdafx.h"
#include <iostream>
#include "LibraryCard.h"
using namespace std;

int main()
{
	LibraryCard libcard;
	
	//���Խӿ�
	int currentClient;
	char exit = ' ';
	cout << "\n* ִ�����ݿ������𣿣�y/n����  ";
	cin >> exit;
	if (exit=='y')
		libcard.refreshDatabase();
	else
	{
		libcard.login();
		currentClient = libcard.getNumber();
		libcard.withdraw(currentClient);
		libcard.printID(currentClient);
	}

	for (int i = 1; i <= 3; i++)
		libcard.regist();
	string shujibianhao;
	libcard.login();
	currentClient = libcard.getNumber();
	if (currentClient)
	{
		for (int i = 1; i <= 3; i++)
		{
			cout << "\n______________________________�鼮����______________________________\n" << endl;
			cout << "\n * ��������鼮��ţ�  ";
			cin >> shujibianhao;
			libcard.borrowTag(currentClient, shujibianhao);
			libcard.printID(currentClient);
		}
		for (int i = 1; i <= 3; i++)
		{
			cout << "\n______________________________�鼮�黹______________________________\n" << endl;
			cout << "\n * ���뻹���鼮��ţ�  ";
			cin >> shujibianhao;
			libcard.returnTag(currentClient, shujibianhao);
			libcard.printID(currentClient);
		}
	}

	libcard.modify(currentClient);
	libcard.printID(currentClient);

	system("pause");
	return 0;
}