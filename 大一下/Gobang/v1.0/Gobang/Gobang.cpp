#include "stdafx.h"
#include "Gobang.h"
#include <iomanip>
#include <iostream>
using namespace std;

Gobang::Gobang(int n)
{
	while (n < 0)
	{
		cout << "��������̴�С�������������룺";
		cin >> n;
	}

	size = n;

	Goboard = new int *[size + 1];
	for (int i = 0; i <= size; i++)
		Goboard[i] = new int[size + 1];
	for (int i = 0; i <= size; i++)
		for (int j = 0; j <= size; j++)
		{
			Goboard[i][0] = i;
			Goboard[0][j] = j;
			Goboard[i][j] = 0;
		}	

	Scoreboard = new int *[size + 1];
	for (int i = 0; i <= size; i++)
		Scoreboard[i] = new int[size + 1];
	for (int i = 0; i <= size; i++)
		for (int j = 0; j <= size; j++)
		{
			Scoreboard[i][0] = i;
			Scoreboard[0][j] = j;
			Scoreboard[i][j] = 0;
		}
}

void Gobang::play()
{
	cout << "\n__________���������������~~~__________" << endl;
	
	int turn = -1;
	int gamestatus = -1;

	while (turn <= 0 || turn > 2)
	{
		cout << "\n ��ѡ��1���񡿡�ѡ��2������" << endl;
		cout << "\n��������ѡ��1���֡� ���ѡ���ǣ�  ";
		cin >> turn;
	}

	switch (turn)
	{
	case 1:
		while (gamestatus)
		{
			YouGo(1);
			gamestatus = judge();
			switch (gamestatus)
			{
			case -1:
				break;
			case 0:
				cout << "\n\n\n\n\n\n\n\n\n\n��ƽ�֣��Դ�ϲ����\n\n\n\n\n\n\n\n\n" << endl;
				break;
			case 1:
				cout << "\n\n\n\n\n\n\n\n\n\n�����1�����Լ�����ʤ����ϲ����\n\n\n\n\n\n\n\n\n" << endl;
				break;
			case 2:
				cout << "\n\n\n\n\n\n\n\n\n\n�������˻�ʤ����\n\n\n\n\n\n\n\n\n" << endl;
				break;
			}
			if (gamestatus >= 0)
				break;

			AIGo(2);
			gamestatus = judge();
			switch (gamestatus)
			{
			case -1:
				break;
			case 0:
				cout << "\n\n\n\n\n\n\n\n\n\n��ƽ�֣��Դ�ϲ����\n\n\n\n\n\n\n\n\n" << endl;
				break;
			case 1:
				cout << "\n\n\n\n\n\n\n\n\n\n�����1�����Լ�����ʤ����ϲ����\n\n\n\n\n\n\n\n\n" << endl;
				break;
			case 2:
				cout << "\n\n\n\n\n\n\n\n\n\n�������˻�ʤ����\n\n\n\n\n\n\n\n\n" << endl;
				break;
			}
			if (gamestatus >= 0)
				break;
		}
		break;
	case 2:
		while (gamestatus)
		{
			AIGo(1);
			gamestatus = judge();
			switch (gamestatus)
			{
			case -1:
				break;
			case 0:
				cout << "\n\n\n\n\n\n\n\n\n\n��ƽ�֣��Դ�ϲ����\n\n\n\n\n\n\n\n\n" << endl;
				break;
			case 1:
				cout << "\n\n\n\n\n\n\n\n\n\n�����1�����Լ�����ʤ����ϲ����\n\n\n\n\n\n\n\n\n" << endl;
				break;
			case 2:
				cout << "\n\n\n\n\n\n\n\n\n\n�������˻�ʤ����\n\n\n\n\n\n\n\n\n" << endl;
				break;
			}
			if (gamestatus >= 0)
				break;

			YouGo(2);
			gamestatus = judge();
			switch (gamestatus)
			{
			case -1:
				break;
			case 0:
				cout << "\n\n\n\n\n\n\n\n\n\n��ƽ�֣��Դ�ϲ����\n\n\n\n\n\n\n\n\n" << endl;
				break;
			case 1:
				cout << "\n\n\n\n\n\n\n\n\n\n�����1�����Լ�����ʤ����ϲ����\n\n\n\n\n\n\n\n\n" << endl;
				break;
			case 2:
				cout << "\n\n\n\n\n\n\n\n\n\n�������˻�ʤ����\n\n\n\n\n\n\n\n\n" << endl;
				break;
			}
			if (gamestatus >= 0)
				break;
		}
		break;
	}
}

void Gobang::YouGo(int num)
{
	int x = 0;
	int y = 0;

	cout << "\n��ѡ�� " << num << "�����Լ������壺  ";
	cin >> x >> y;
	while (x < 1 || x > size || y < 1 || y > size || Goboard[x][y] != 0)
	{
		cout << "��ǰ�������겻����Ҫ������Ѿ����ӣ����������룺  ";
		cin >> x >> y;
	}
	Draw(x, y, num);
}

void Gobang::AIGo(int num)
{
	//��������
	AIdefend(num, 2);
	//Ѱ��������Defnd����Ժ��Զ�����

}
void Gobang::AIdefend(int num, int level)//���ӵķ���������ֵ
{
	for (int hang = 1; hang <= size; hang++)
		for (int lie = 1; lie <= size; lie++)
			if (Goboard[hang][lie] != num && Goboard[hang][lie] != 0)
				for (int direction = 1; direction <= 4; direction++)
					for (int space = 1; space <= size; space++)
						if (ComboCheck(hang, lie, direction, space) > Scoreboard[hang][lie])
							Scoreboard[hang][lie] = ComboCheck(hang, lie, direction, space);

	for (int arry = 4; arry >= level; arry--)
		for (int space = 1; space <= size; space++)
			for (int hang = 1; hang <= size; hang++)
				for (int lie = 1; lie <= size; lie++)
					for (int direction = 1; direction <= 4; direction++)
					{
						if (arry == Scoreboard[hang][lie] && ComboCheck(hang, lie, direction, space) == arry)//ȷʵ���������������ô���п���������ӵ�����
						{
							switch (direction)
							{
							case 1:
							{
								if (hang - 4 * space < 1 || lie + 4 * space > size)
									break;

								int i = 4;//����ұ�
								for (i; i >= arry; i--)
								{
									if (Goboard[hang - i * space][lie + i * space] == num)//���ҷ�����
										break;
									if (i == arry)//���ҷ�����
									{
										Draw(hang - arry * space, lie + arry * space, num);
										return;
									}
								}

								if (hang + space <= size && lie - space >= 1)//���δԽ��
									if (Goboard[hang + space][lie - space] == 0)
									{
										if (hang + 2 * space <= size && lie - 2 * space >= 1 && Goboard[hang + 2 * space][lie - 2 * space] != num && Goboard[hang + 2 * space][lie - 2 * space] != 0)
										{
											Draw(hang + space, lie - space, num);
											return;
										}
										else
											if (arry < 4)
												break;
											else
											{
												Draw(hang + space, lie - space, num);
												return;
											}
									}
							}
							break;
							case 2:
							{
								if (lie + 4 * space > size)
									break;

								int i = 4;//����ұ�
								for (i; i >= arry; i--)
								{
									if (Goboard[hang][lie + i * space] == num)//���ҷ�����
										break;
									if (i == arry)//���ҷ�����
									{
										Draw(hang, lie + arry * space, num);
										return;
									}
								}

								if (lie - space >= 1)//���δԽ��
									if (Goboard[hang][lie - space] == 0)
									{
										if (lie - 2 * space >= 1 && Goboard[hang][lie - 2 * space] != num && Goboard[hang][lie - 2 * space] != 0)
										{
											Draw(hang, lie - space, num);
											return;
										}
										else
											if (arry < 4)
												break;
											else
											{
												Draw(hang, lie - space, num);
												return;
											}
									}
							}
							break;
							case 3:
							{
								if (hang + 4 * space > size || lie + 4 * space > size)
									break;

								int i = 4;//����ұ�
								for (i; i >= arry; i--)
								{
									if (Goboard[hang + i * space][lie + i * space] == num)//���ҷ�����
										break;
									if (i == arry)//���ҷ�����
									{
										Draw(hang + arry * space, lie + arry * space, num);
										return;
									}
								}

								if (hang - space >= 1 && lie - space >= 1)//���δԽ��
									if (Goboard[hang - space][lie - space] == 0)
									{
										if (hang - 2 * space >= 1 && lie - 2 * space >= 1 && Goboard[hang - 2 * space][lie - 2 * space] != num && Goboard[hang + 2 * space][lie - 2 * space] != 0)
										{
											Draw(hang - space, lie - space, num);
											return;
										}
										else
											if (arry < 4)
												break;
											else
											{
												Draw(hang - space, lie - space, num);
												return;
											}
									}
							}
							break;
							case 4:
							{
								if (hang + 4 * space > size)
									break;

								int i = 4;//����ұ�
								for (i; i >= arry; i--)
								{
									if (Goboard[hang + i * space][lie] == num)//���ҷ�����
										break;
									if (i == arry)//���ҷ�����
									{
										Draw(hang + arry * space, lie, num);
										return;
									}
								}

								if (arry < 4)
									break;

								if (hang - space >= 1)//���δԽ��
									if (Goboard[hang - space][lie] == 0)
									{
										if (hang - 2 * space >= 1 && Goboard[hang - 2 * space][lie] != num && Goboard[hang - 2 * space][lie] != 0)
										{
											Draw(hang - space, lie, num);
											return;
										}
										else
											if (arry < 4)
												break;
											else
											{
												Draw(hang - space, lie, num);
												return;
											}
									}
							}
							break;
							}
						}
					}
					cout << "\n��@��@��@��@��@��@��AI�������ģʽ����@��@��@��@��@��" << endl;
	AIinvade(num, 3);
}
void Gobang::AIinvade(int num, int level)//���ӵĽ���ע����ֵ
{
	for (int hang = 1; hang <= size; hang++)
		for (int lie = 1; lie <= size; lie++)
			if (Goboard[hang][lie] == num)
				for (int direction = 1; direction <= 4; direction++)
					for (int space = 1; space <= size; space++)
						if (ComboCheck(hang, lie, direction, space) > Scoreboard[hang][lie])
							Scoreboard[hang][lie] = 10 + ComboCheck(hang, lie, direction, space);

	for (int arry = 4; arry >= level; arry--)
		for (int space = 1; space <= size; space++)
			for (int hang = 1; hang <= size; hang++)
				for (int lie = 1; lie <= size; lie++)
					for (int direction = 1; direction <= 4; direction++)
					{
						if ((arry + 10) == Scoreboard[hang][lie] && ComboCheck(hang, lie, direction, space) == arry)//ȷʵ���������������ô���п���������ӵ�����
						{
							switch (direction)
							{
							case 1:
							{
								if (hang - 4 * space < 1 || lie + 4 * space > size)
									break;

								int i = 4;//����ұ�
								for (i; i >= arry; i--)
								{
									if (Goboard[hang - i * space][lie + i * space] != num && Goboard[hang + i * space][lie + i * space] != 0)//�е�������
										break;
									if (i == arry && Goboard[hang - i * space][lie + i * space] == 0)//�޵з�����
									{
										Draw(hang - arry * space, lie + arry * space, num);
										return;
									}
								}

								if (hang + space <= size && lie - space >= 1)//���δԽ��
									if (Goboard[hang + space][lie - space] == 0)
									{
										Draw(hang + space, lie - space, num);
										return;
									}
								
							}
							break;
							case 2:
							{
								if (lie + 4 * space > size)
									break;

								int i = 4;//����ұ�
								for (i; i >= arry; i--)
								{
									if (Goboard[hang][lie + i * space] != num && Goboard[hang][lie + i * space] != 0)//�е�������
										break;
									if (i == arry && Goboard[hang][lie + i * space] == 0)//�޵з�����
									{
										Draw(hang, lie + arry * space, num);
										return;
									}
								}

								if (lie - space >= 1)//���δԽ��
									if (Goboard[hang][lie - space] == 0)
									{
										Draw(hang, lie - space, num);
										return;
									}
							}
							break;
							case 3:
							{
								if (hang + 4 * space > size || lie + 4 * space > size)
									break;

								int i = 4;//����ұ�
								for (i; i >= arry; i--)
								{
									if (Goboard[hang + i * space][lie + i * space] != num && Goboard[hang + i * space][lie + i * space] != 0)//�е�������
										break;
									if (i == arry && Goboard[hang + i * space][lie + i * space] == 0)//�޵з�����
									{
										Draw(hang + arry * space, lie + arry * space, num);
										return;
									}
								}

								if (hang - space >= 1 && lie - space >= 1)//���δԽ��
									if (Goboard[hang - space][lie - space] == 0)
									{
										Draw(hang - space, lie - space, num);
										return;
									}
							}
							break;
							case 4:
							{
								if (hang + 4 * space > size)
									break;

								int i = 4;//����ұ�
								for (i; i >= arry; i--)
								{
									if (Goboard[hang + i * space][lie] != num && Goboard[hang + i * space][lie] != 0)//�е�������
										break;
									if (i == arry && Goboard[hang + i * space][lie] == 0)//�޵з�����
									{
										Draw(hang + arry * space, lie, num);
										return;
									}
								}								

								if (hang - space >= 1)//���δԽ��
									if (Goboard[hang - space][lie] == 0)
									{
										Draw(hang - space, lie, num);
										return;
									}
							}
							break;
							}
						}
					}

					if (level >= 2)
					{
						level--;
						AIinvade(num, level);
					}
					else
						cout << "\n���Ķ��֣�" << num << " ������һ�֣���������������ȥ��bug����������������\n" << endl;
}
void Gobang::Draw(int hang, int lie, int num)
{
	Goboard[hang][lie] = num;
	cout << "\nѡ�� " << num << " ������λ�ã�  " << "�� " << hang << " , " << lie << " ��" << endl;
	print();
}
/*�����ýӿ�*/void Gobang::printScore()
{
	cout << "\n��@��@��@����������Ȩ��ϵͳ(AI�ӽǷ����Լ��Ŀ�����.����Խ��,������Խ��,Խ��ȫ.)��@��@��@��\n" << endl;
	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j <= size; j++)
			cout << setw(4) << Scoreboard[i][j] << setw(4);
		cout << endl << endl;
	}
}

int Gobang::judge()//(-1:��δ�ֳ�ʤ��)(0:ƽ��)(1:���1��ʤ)(2:���2��ʤ)
{
	for (int hang = 1; hang <= size; hang++)
	{ 
		for (int lie = 1; lie <= size; lie++)
		{
			for (int direction = 1; direction <= 4; direction++)
			{
				for (int space = 1; space <= size; space++)
				{
					if (Goboard[hang][lie] != 0 && ComboCheck(hang, lie, direction, space) == 5)
								return Goboard[hang][lie];
				}
			}
		}
	}

	for (int i = 1; i <= size; i++)
		for (int j = 1; j <= size; j++)
			if (Goboard[i][j] == 0)
				return -1;
	return 0;
}

//����ĳ�㴦ĳ�������������Ŀ
int Gobang::ComboCheck(int hang, int lie, int direction, int space)
{
	if (space < 1 || hang < 1 || hang > size || lie < 1 || lie > size || Goboard[hang][lie] == 0)
		return 0;

	switch (direction)
	{
	case 1://����->����
	{
		int cnt = 0;
		int num = Goboard[hang][lie];

		for (int i = 0; i <= 4; i++)
			if (hang - i * space < 1 || lie + i * space > size)
				break;
			else
				if (Goboard[hang - i * space][lie + i * space] != num)
					break;
				else 
					cnt++;
		return cnt;
	}
	break;
	case 2://��->��
	{
		int cnt = 0;
		int num = Goboard[hang][lie];

		for (int i = 0; i <= 4; i++)
			if (lie + i * space > size)
				break;
			else
				if (Goboard[hang][lie + i * space] != num)
					break;
				else
					cnt++;

		return cnt;
	}
	break;
	case 3://����->����
	{
		int cnt = 0;
		int num = Goboard[hang][lie];

		for (int i = 0; i <= 4; i++)
			if (hang + space * 4 > size || lie + space * 4 > size)
				break;
			else
				if (Goboard[hang + i * space][lie + i * space] != num)
					break;
				else
					cnt++;

		return cnt;
	}
	case 4://��->��
	{
		int cnt = 0;
		int num = Goboard[hang][lie];

		for (int i = 0; i <= 4; i++)
			if (hang + space * 4 > size)
				break;
			else
				if (Goboard[hang + i * space][lie] != num)
					break;
				else
					cnt++;

		return cnt;
	}
	break;
	}
}

void Gobang::print()
{
	cout << endl;
	for (int i = 1; i <= size; i++)
		cout << "__";
	cout << "����ǰ���̡�";
	for (int i = 1; i <= size; i++)
		cout << "__";
	cout << endl << endl;

	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j <= size; j++)
		{
			if (i == 0 || j == 0)
				cout << setw(4) << Goboard[i][j] << setw(4);
			else
			{
				switch (Goboard[i][j])
				{
				case 0:
					cout << setw(4) << "ʮ" << setw(4);
					break;
				case 1:
					cout << setw(4) << "��" << setw(4);
					break;
				case 2:
					cout << setw(4) << "��" << setw(4);
					break;
				}
			}
		}
		cout << endl << endl;
	}
}

Gobang::~Gobang()
{
	for (int i = 0; i <= size; i++)
		delete[]Goboard[i];
	delete[]Goboard;

	for (int i = 0; i <= size; i++)
		delete[]Scoreboard[i];
	delete[]Scoreboard;
}