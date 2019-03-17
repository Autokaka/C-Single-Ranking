#include "stdafx.h"
#include "LibraryCard.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


LibraryCard::LibraryCard()
{
	Number = 0;
	Name = "NULL";
	Password = "NULL";
	Level = 3;
	Limit = 5;
	Bookcode = "NULL";
}

void LibraryCard::regist()
{
	string xingming;
	string mima;

	cout << "\n__________________________________________________用户注册__________________________________________________\n" << endl;
	cout << "\n * 请输入您的姓名(用户姓名只能为字母且【4<=字符<=20】,空格算入姓名长度)：  ";
	getline(cin, xingming);
	setName(xingming);
	cout << "\n * 请输入您的密码(密码仅能包含正常的英文以及符号且【4<=字符<=20】)：  ";
	getline(cin, mima);
	setPassword(mima);
	cout << "\n * 请确认您的密码：  ";
	getline(cin, mima);
	while (Password != mima)
	{
		cout << "\n   密码与之前输入的不匹配，请重新输入：";
		getline(cin, mima);
	}
	cout << "\n   注册成功！\n" << endl;
	
	//读取已有用户数
	Number = 0;
	string content;
	ifstream history("ClientID.txt");
	if (!history.is_open())
	{
		cout << "   Failed to open ClientID.txt!";
		exit(1);
	}
	while (getline(history, content))
		Number++;
	//存入信息
	ofstream out("ClientID.txt", ios::app);
	if (out.is_open())
	{
		out << left << setw(20) << ++Number << setw(20) << Name << setw(20) << Password << setw(20) << Level << setw(20) << Limit << setw(100) << Bookcode << endl;
		out.close();
	}
}

void LibraryCard::login()
{
	int bianhao;
	string mima;

	cout << "\n__________________________________________________用户登录__________________________________________________\n" << endl;
	cout << "\n * 请输入您的读者编号：  ";
	cin >> bianhao;
	ifstream check("ClientID.txt");
	if (!check.is_open())
	{
		cout << "   Failed to open ClientID.txt!";
		exit(1);
	}
	while (!check.eof())
	{
		check >> left >> setw(20) >> Number >> setw(20) >> Name >> setw(20) >> Password >> setw(20) >> Level >> setw(20) >> Limit >> setw(100) >> Bookcode;
		if (Number == bianhao)
		{
			cout << "\n * 请输入密码：  ";
			cin >> mima;
			for (int i = 1; i <= 3; i++)
			{
				if (mima != Password)
				{
					cout << "\n   密码错误，请重新输入：  ";
					cin >> mima;
				}
				if (Password == mima)
					break;
				if (i == 3)
				{
					cout << "\n   您已输错三次，本次登录无效！\n" << endl;
					Number = 0;
					return;
				}
			}
			cout << "\n   登录成功！\n" << endl;
			return;
		}
	}
	cout << "\n   您还没有注册，请注册以后再登录！\n" << endl;
	Number = 0;
	return;
}
int LibraryCard::getNumber()
{
	return Number;
}

void LibraryCard::modify(int duzhebianhao)
{
	cout << "\n__________________________________________________账户修改__________________________________________________\n" << endl;
	cout << "\n * 当前操作用户：  " << duzhebianhao << endl << endl;
	int command;
	string mima;
	cout << "\n * 请输入您要修改的内容（1.姓名 2.密码）：  ";
	cin >> command;
	switch (command)
	{
	case 1:
	{
		string xingming;
		cout << "\n * 请输入新的姓名：  ";
		cin >> xingming;
		setName(xingming);
		string newName = Name;
		fstream inout("ClientID.txt");
		if (!inout.is_open())
		{
			cout << "   Failed to open ClientID.txt!";
			exit(1);
		}
		while (!inout.eof())
		{
			inout >> left >> setw(20) >> Number;
			if (Number == duzhebianhao)
			{
				int i = 1;
				for (i; i <= 100000000; i *= 10)
					if (Number / i != 0 && Number / (i * 10) == 0)
						break;
				inout.seekp(20 - i, ios::cur);
				inout << left << setw(20) << newName << setw(20) << Password << setw(20) << Level << setw(20) << Limit << setw(100) << Bookcode << endl;
				break;
			}
			inout >> left >> setw(20) >> Name >> setw(20) >> Password >> setw(20) >> Level >> setw(20) >> Limit >> setw(100) >> Bookcode;
		}
		cout << "\n   读者编号不存在，账户信息修改失败！\n" << endl;
	}
	break;
	case 2:
	{
		string mima;
		cout << "\n * 请输入新的密码：  ";
		cin >> mima;
		setPassword(mima);
		string newPassword = Password;
		fstream inout("ClientID.txt");
		if (!inout.is_open())
		{
			cout << "   Failed to open ClientID.txt!";
			exit(1);
		}
		while (!inout.eof())
		{
			inout >> left >> setw(20) >> Number >> setw(20) >> Name;
			if (Number == duzhebianhao)
			{
				inout.seekp(20 - Name.length(), ios::cur);
				inout << left << setw(20) << newPassword << setw(20) << Level << setw(20) << Limit << setw(100) << Bookcode << endl;
				break;
			}
			inout >> left >> setw(20) >> Password >> setw(20) >> Level >> setw(20) >> Limit >> setw(100) >> Bookcode;
		}
		cout << "\n   读者编号不存在，账户信息修改失败！\n" << endl;
	}
	break;
	}
	cout << "\n   账户信息修改成功！\n" << endl;
}

void LibraryCard::withdraw(int duzhebianhao)
{
	cout << "\n__________________________________________________账户注销__________________________________________________\n" << endl;
	cout << "\n * 当前操作用户：  " << duzhebianhao << endl << endl;
	char confirm;
	cout << "\n * 您确定要注销吗？确认以后的操作不可逆：  ";
	cin >> confirm;
	if (confirm != 'y')
	{
		cout << "\n   操作已取消！\n" << endl;
		return;
	}
	fstream inout("ClientID.txt");
	if (!inout.is_open())
	{
		cout << "   Failed to open ClientID.txt!";
		exit(1);
	}
	while (!inout.eof())
	{
		int begin = inout.tellp();
		inout >> left >> setw(20) >> Number >> setw(20) >> Name >> setw(20) >> Password >> setw(20) >> Level >> setw(20) >> Limit >> setw(100) >> Bookcode;
		if (Number == duzhebianhao)
		{
			int ending = inout.tellp();
			int i = 1;
			for (i; i <= 100000000; i *= 10)
				if (Number / i != 0 && Number / (i * 10) == 0)
					break;
			inout.seekp(begin - ending + 99 - i, ios::cur);
			inout << left << setw(20) << -1 << setw(20) << Name << setw(20) << Password << setw(20) << Level << setw(20) << Limit << setw(100) << Bookcode << endl;
			break;
		}
	}
}

void LibraryCard::borrowTag(int duzhebianhao, string shujibianhao)
{
	cout << "\n * 当前操作用户：  " << duzhebianhao << endl << endl;
	fstream inout("ClientID.txt");
	if (!inout.is_open())
	{
		cout << "   Failed to open ClientID.txt!";
		exit(1);
	}
	while (!inout.eof())
	{
		inout >> left >> setw(20) >> Number >> setw(20) >> Name >> setw(20) >> Password >> setw(20) >> Level >> setw(20) >> Limit;
		int begin = inout.tellp();
		if (Number == duzhebianhao)
		{
			inout >> left >> setw(100) >> Bookcode;
			inout.seekp(begin - inout.tellp(), ios::cur);
			if (Bookcode == "NULL")
				Bookcode = shujibianhao;
			else
				Bookcode += ('|' + shujibianhao);
			int i = 1;
			for (i; i <= 100000000; i *= 10)
				if (Limit / i != 0 && Limit / (i * 10) == 0)
					break;
			inout.seekp(20 - i, ios::cur);
			inout << left << setw(100) << Bookcode << endl;
			cout << "\n   借书成功！\n" << endl;
			return;
		}
		inout >> left >> setw(100) >> Bookcode;
	}
	cout << "\n   借书失败！\n" << endl;
}

void LibraryCard::returnTag(int duzhebianhao, string shujibianhao)
{
	cout << "\n * 当前操作用户：  " << duzhebianhao << endl << endl;
	fstream inout("ClientID.txt");
	if (!inout.is_open())
	{
		cout << "   Failed to open ClientID.txt!";
		exit(1);
	}
	while (!inout.eof())
	{
		inout >> left >> setw(20) >> Number >> setw(20) >> Name >> setw(20) >> Password >> setw(20) >> Level >> setw(20) >> Limit;
		int begin = inout.tellp();
		if (Number == duzhebianhao)
		{
			inout >> left >> setw(100) >> Bookcode;
			inout.seekp(begin - inout.tellp(), ios::cur);
			string temp;
			int num[16] = { 0 };
			int cnt = 0;
			for (int i = 0; i <= Bookcode.length(); i++)
			{
				if (Bookcode[i] == '|' || i == Bookcode.length())
				{
					num[++cnt] = atoi(temp.c_str());
					temp = "";
				}
				else
					temp += Bookcode[i];
			}
			for (int i = 1; i <= 15; i++)
			{
				temp = to_string(num[i]);
				if (temp == shujibianhao)
					num[i] = 0;
			}
			Bookcode = "NULL";
			for (int i = 1; i <= 15; i++)
			{
				if (num[i])
				{
					temp = to_string(num[i]);
					if (Bookcode == "NULL")
						Bookcode = temp;
					else
						Bookcode += '|' + temp;
				}
			}
			int i = 1;
			for (i; i <= 100000000; i *= 10)
				if (Limit / i != 0 && Limit / (i * 10) == 0)
					break;
			inout.seekp(20 - i, ios::cur);
			inout << left << setw(100) << Bookcode << endl;
			cout << "\n   还书成功！\n" << endl;
			return;
		}
		inout >> left >> setw(100) >> Bookcode;
	}
	cout << "\n   还书失败！\n" << endl;
}

void LibraryCard::setName(string xingming)
{
	while (xingming.length() == 0)
	{
		cout << "\n   您输入的姓名为空，请重新输入：  ";
		getline(cin, xingming);
	}
	while (xingming.length() < 4 || xingming.length() > 20)
	{
		cout << "\n   您输入的姓名长度不达标，请重新输入：  ";
		getline(cin, xingming);
	}

	for (unsigned int i = 0; i < xingming.length(); i++)
	{
		if (!((xingming[i] >= 'a' && xingming[i] <= 'z') || (xingming[i] >= 'A' && xingming[i] <= 'Z') || xingming[i] == ' '))
		{
			cout << "\n   您输入的姓名含有违规字符，请重新输入：  ";
			getline(cin, xingming);
			setName(xingming);
		}
	}
	Name = xingming;
}

void LibraryCard::setPassword(string mima)
{
	for (unsigned int i = 0; i < mima.length(); i++)
	{
		if (mima[i] == ' ')
		{
			cout << "\n   您输入的密码含有违规字符，请重新输入：  ";
			getline(cin, mima);
			i = -1;
		}
	}

	while (mima.length() == 0)
	{
		cout << "\n   您输入的密码为空，请重新输入：  ";
		getline(cin, mima);
		setPassword(mima);
	}
	while (mima.length() < 4 || mima.length() > 20)
	{
		cout << "\n   您输入的密码长度不达标，请重新输入：  ";
		getline(cin, mima);
		setPassword(mima);
	}

	Password = mima;
}

void LibraryCard::printID()
{
	cout << "\n__________________________________________________用户信息__________________________________________________\n" << endl;
	cout << left << setw(20) << "读者编号" << setw(20) << "姓名" << setw(20) << "密码" << setw(20) << "借阅等级" << setw(20) << "借书数限制" << setw(20) << "借阅图书" << endl;
	string Client;
	ifstream in("ClientID.txt");
	if (!in.is_open())
	{
		cout << "Failed to open ClientID.txt!";
		exit(1);
	}
	while (!in.eof())
	{
		getline(in, Client);
		cout << Client << endl;
	}
}

void LibraryCard::refreshDatabase()
{
	ofstream refreshClient("ClientID.txt");
	if (refreshClient.is_open())
	{
		refreshClient << "";
		refreshClient.close();
	}
}