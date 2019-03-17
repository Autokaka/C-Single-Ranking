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

	cout << "\n__________________________________________________�û�ע��__________________________________________________\n" << endl;
	cout << "\n * ��������������(�û�����ֻ��Ϊ��ĸ�ҡ�4<=�ַ�<=20��,�ո�������������)��  ";
	getline(cin, xingming);
	setName(xingming);
	cout << "\n * ��������������(������ܰ���������Ӣ���Լ������ҡ�4<=�ַ�<=20��)��  ";
	getline(cin, mima);
	setPassword(mima);
	cout << "\n * ��ȷ���������룺  ";
	getline(cin, mima);
	while (Password != mima)
	{
		cout << "\n   ������֮ǰ����Ĳ�ƥ�䣬���������룺";
		getline(cin, mima);
	}
	cout << "\n * ע��ɹ���\n" << endl;
	
	//��ȡ�����û���
	ifstream history("ClientNum.txt");
	if (!history.is_open())
	{
		cout << "   Failed to open ClientID.txt!";
		exit(1);
	}
	history >> Number;
	//������Ϣ
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

	cout << "\n__________________________________________________�û���¼__________________________________________________\n" << endl;
	cout << "\n * ���������Ķ��߱�ţ�  ";
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
			cout << "\n * ���������룺  ";
			cin >> mima;
			if (mima != Password)
			{
				for (int i = 1; i <= 3; i++)
				{
					cout << "\n   ����������������룺  ";
					cin >> mima;
					if (mima == Password)
					{
						cout << "\n * ��¼�ɹ���\n" << endl;
						return true;
					}
				}
				cout << "\n * ���Ѿ�����������룬���ε�¼ʧ�ܣ�\n" << endl;
				return false;
			}
			else
			{
				cout << "\n * ��¼�ɹ���\n" << endl;
				return true;
			}
		}
	}
	cout << "\n * ����û��ע�ᣬ��ע���Ժ��ٵ�¼��\n" << endl;
	return false;
}

void LibraryCard::setName(string xingming)
{
	while (xingming.length() == 0)
	{
		cout << "\n   �����������Ϊ�գ����������룺  ";
		getline(cin, xingming);
	}
	while (xingming.length() < 4 || xingming.length() > 20)
	{
		cout << "\n   ��������������Ȳ���꣬���������룺  ";
		getline(cin, xingming);
	}

	for (unsigned int i = 0; i < xingming.length(); i++)
	{
		if (!((xingming[i] >= 'a' && xingming[i] <= 'z') || (xingming[i] >= 'A' && xingming[i] <= 'Z') || xingming[i] == ' '))
		{
			cout << "\n   ���������������Υ���ַ������������룺  ";
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
			cout << "\n   ����������뺬��Υ���ַ������������룺  ";
			getline(cin, mima);
			i = -1;
		}
	}

	while (mima.length() == 0)
	{
		cout << "\n   �����������Ϊ�գ����������룺  ";
		getline(cin, mima);
		setPassword(mima);
	}
	while (mima.length() < 4 || mima.length() > 20)
	{
		cout << "\n   ����������볤�Ȳ���꣬���������룺  ";
		getline(cin, mima);
		setPassword(mima);
	}

	Password = mima;
}

void LibraryCard::printID()
{
	cout << "\n__________________________________________________�û���Ϣ__________________________________________________\n" << endl;
	cout << left << setw(20) << "���߱��" << setw(20) << "����" << setw(20) << "����" << setw(20) << "���ĵȼ�" << setw(20) << "����������" << setw(20) << "������" << endl;
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