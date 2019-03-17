#include "stdafx.h"
#include <iostream>
#include "LibraryCard.h"
using namespace std;

int main()
{
	LibraryCard libcard;
	
	//测试接口
	int currentClient;
	char exit = ' ';
	cout << "\n* 执行数据库清理吗？（y/n）：  ";
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
			cout << "\n______________________________书籍借阅______________________________\n" << endl;
			cout << "\n * 输入借书书籍编号：  ";
			cin >> shujibianhao;
			libcard.borrowTag(currentClient, shujibianhao);
			libcard.printID(currentClient);
		}
		for (int i = 1; i <= 3; i++)
		{
			cout << "\n______________________________书籍归还______________________________\n" << endl;
			cout << "\n * 输入还书书籍编号：  ";
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