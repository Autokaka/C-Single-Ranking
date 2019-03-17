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
	cout << "\n * 注册成功！\n" << endl;
	
	//读取已有用户数
	ifstream history("ClientNum.txt");
	if (!history.is_open())
	{
		cout << "   Failed to open ClientID.txt!";
		exit(1);
	}
	history >> Number;
	//存入信息
	ofstream out("ClientID.txt", ios::app);
	if (out.is_open())
	{
		out << left << setw(20) << ++Number << setw(20) << Name << setw(20) << Password << setw(20) << Level << setw(20) << Limit << setw(20) << endl;
		out.close();
	}
	ofstream refresh("ClientNum.txt");
	if (refresh.is_open())
	{
		refresh << Number;
		refresh.close();
	}
}

bool LibraryCard::login()
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
	while (getline(check, Name))
	{
		check >> left >> setw(20) >> Number >> setw(20) >> Name >> setw(20) >> Password;
		if (Number == bianhao)
		{
			cout << "\n * 请输入密码：  ";
			cin >> mima;
			if (mima != Password)
			{
				for (int i = 1; i <= 3; i++)
				{
					cout << "\n   密码错误，请重新输入：  ";
					cin >> mima;
					if (mima == Password)
					{
						cout << "\n * 登录成功！\n" << endl;
						return true;
					}
				}
				cout << "\n * 您已经输错三次密码，本次登录失败！\n" << endl;
				return false;
			}
			else
			{
				cout << "\n * 登录成功！\n" << endl;
				return true;
			}
		}
	}
	cout << "\n * 您还没有注册，请注册以后再登录！\n" << endl;
	return false;
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
	cout << left << setw(20) << "读者编号" << setw(20) << "姓名" << setw(20) << "密码" << setw(20) << "借阅等级" << setw(20) << "借书数限制" << setw(20) << "借书编号" << endl;
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
	ofstream refreshNum("ClientNum.txt");
	if (refreshNum.is_open())
	{
		refreshNum << 0;
		refreshNum.close();
	}
}