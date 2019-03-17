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
	cout << "\n   ע��ɹ���\n" << endl;
	
	//��ȡ�����û���
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
	//������Ϣ
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

	cout << "\n__________________________________________________�û���¼__________________________________________________\n" << endl;
	cout << "\n * ���������Ķ��߱�ţ�  ";
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
			cout << "\n * ���������룺  ";
			cin >> mima;
			for (int i = 1; i <= 3; i++)
			{
				if (mima != Password)
				{
					cout << "\n   ����������������룺  ";
					cin >> mima;
				}
				if (Password == mima)
					break;
				if (i == 3)
				{
					cout << "\n   ����������Σ����ε�¼��Ч��\n" << endl;
					Number = 0;
					return;
				}
			}
			cout << "\n   ��¼�ɹ���\n" << endl;
			return;
		}
	}
	cout << "\n   ����û��ע�ᣬ��ע���Ժ��ٵ�¼��\n" << endl;
	Number = 0;
	return;
}
int LibraryCard::getNumber()
{
	return Number;
}

void LibraryCard::modify(int duzhebianhao)
{
	cout << "\n__________________________________________________�˻��޸�__________________________________________________\n" << endl;
	cout << "\n * ��ǰ�����û���  " << duzhebianhao << endl << endl;
	int command;
	string mima;
	cout << "\n * ��������Ҫ�޸ĵ����ݣ�1.���� 2.���룩��  ";
	cin >> command;
	switch (command)
	{
	case 1:
	{
		string xingming;
		cout << "\n * �������µ�������  ";
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
		cout << "\n   ���߱�Ų����ڣ��˻���Ϣ�޸�ʧ�ܣ�\n" << endl;
	}
	break;
	case 2:
	{
		string mima;
		cout << "\n * �������µ����룺  ";
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
		cout << "\n   ���߱�Ų����ڣ��˻���Ϣ�޸�ʧ�ܣ�\n" << endl;
	}
	break;
	}
	cout << "\n   �˻���Ϣ�޸ĳɹ���\n" << endl;
}

void LibraryCard::withdraw(int duzhebianhao)
{
	cout << "\n__________________________________________________�˻�ע��__________________________________________________\n" << endl;
	cout << "\n * ��ǰ�����û���  " << duzhebianhao << endl << endl;
	char confirm;
	cout << "\n * ��ȷ��Ҫע����ȷ���Ժ�Ĳ��������棺  ";
	cin >> confirm;
	if (confirm != 'y')
	{
		cout << "\n   ������ȡ����\n" << endl;
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
	cout << "\n * ��ǰ�����û���  " << duzhebianhao << endl << endl;
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
			cout << "\n   ����ɹ���\n" << endl;
			return;
		}
		inout >> left >> setw(100) >> Bookcode;
	}
	cout << "\n   ����ʧ�ܣ�\n" << endl;
}

void LibraryCard::returnTag(int duzhebianhao, string shujibianhao)
{
	cout << "\n * ��ǰ�����û���  " << duzhebianhao << endl << endl;
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
			cout << "\n   ����ɹ���\n" << endl;
			return;
		}
		inout >> left >> setw(100) >> Bookcode;
	}
	cout << "\n   ����ʧ�ܣ�\n" << endl;
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
	cout << left << setw(20) << "���߱��" << setw(20) << "����" << setw(20) << "����" << setw(20) << "���ĵȼ�" << setw(20) << "����������" << setw(20) << "����ͼ��" << endl;
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