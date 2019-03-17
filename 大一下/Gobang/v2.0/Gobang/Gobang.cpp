#include "stdafx.h"
#include "Gobang.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>
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

void Gobang::AIGo(int num)//num���Լ��ĺ���
{
	//�ж��Լ��ǲ����Ѿ�ҪӮ��
	for (int hang = 1; hang <= size; hang++)
		for (int lie = 1; lie <= size; lie++)
			for (int space = 1; space <= size; space++)
				for (int direction = 1; direction <= 4; direction++)
					if (Goboard[hang][lie] == num && ComboCheck(hang, lie, direction, space) >= 3)
					{
						switch (direction)
						{
						case 1:
						{
							if (hang + space <= size && lie - space >= 1 && hang - 3 * space >= 1 && lie + 3 * space <= size)
								switch (ComboCheck(hang, lie, direction, space))
								{
								case 3:
								{
									if (Goboard[hang + space][lie - space] == 0 && Goboard[hang - 3 * space][lie + 3 * space] == 0)
									{
										Draw(hang - 3 * space, lie + 3 * space, num);
										return;
									}
								}
								break;
								case 4:
								{
									if (Goboard[hang + space][lie - space] == 0)
									{
										Draw(hang + space, lie - space, num);
										return;
									}
									if (Goboard[hang - 4 * space][lie + 4 * space] == 0)
									{
										Draw(hang - 4 * space, lie + 4 * space, num);
										return;
									}
								}
								break;
								}
						}
						break;
						case 2:
						{
							if (lie - space >= 1 && lie + 3 * space <= size)
								switch (ComboCheck(hang, lie, direction, space))
								{
								case 3:
								{
									if (Goboard[hang][lie - space] == 0 && Goboard[hang][lie + 3 * space] == 0)
									{
										Draw(hang, lie + 3 * space, num);
										return;
									}
								}
								break;
								case 4:
								{
									if (Goboard[hang][lie - space] == 0)
									{
										Draw(hang, lie - space, num);
										return;
									}
									if (Goboard[hang][lie + 4 * space] == 0)
									{
										Draw(hang, lie + 4 * space, num);
										return;
									}
								}
								break;
								}
						}
						break;
						case 3:
						{
							if (hang - space >= 1 && lie - space >= 1 && hang + 3 * space <= size && lie + 3 * space <= size)
								switch (ComboCheck(hang, lie, direction, space))
								{
								case 3:
								{
									if (Goboard[hang - space][lie - space] == 0 && Goboard[hang + 3 * space][lie + 3 * space] == 0)
									{
										Draw(hang + 3 * space, lie + 3 * space, num);
										return;
									}
								}
								break;
								case 4:
								{
									if (Goboard[hang - space][lie - space] == 0)
									{
										Draw(hang - space, lie - space, num);
										return;
									}
									if (Goboard[hang + 4 * space][lie + 4 * space] == 0)
									{
										Draw(hang + 4 * space, lie + 4 * space, num);
										return;
									}
								}
								break;
								}
						}
						break;
						case 4:
						{
							if (hang - space >= 1 && hang + 3 * space <= size)
								switch (ComboCheck(hang, lie, direction, space))
								{
								case 3:
								{
									if (Goboard[hang - space][lie] == 0 && Goboard[hang + 3 * space][lie] == 0)
									{
										Draw(hang + 3 * space, lie, num);
										return;
									}
								}
								break;
								case 4:
								{
									if (Goboard[hang - space][lie] == 0)
									{
										Draw(hang - space, lie, num);
										return;
									}
									if (Goboard[hang + 4 * space][lie] == 0)
									{
										Draw(hang + 4 * space, lie, num);
										return;
									}
								}
								break;
								}
						}
						break;
						}
					}
	cout << "\n  �ж��Լ��ǲ����Ѿ�ҪӮ��  ����\n" << endl;
	//����
	//�ж϶����Ƿ�ҪӮ��
	for (int hang = 1; hang <= size; hang++)
		for (int lie = 1; lie <= size; lie++)
			for (int space = 1; space <= size; space++)
				for (int direction = 1; direction <= 4; direction++)
					if (Goboard[hang][lie] != num && Goboard[hang][lie] != 0 && ComboCheck(hang, lie, direction, space) >= 3)
					{
						switch (direction)
						{
						case 1:
						{
							if (hang + space <= size && lie - space >= 1 && hang - 3 * space >= 1 && lie + 3 * space <= size)
								switch (ComboCheck(hang, lie, direction, space))
								{
								case 3:
								{
									if (Goboard[hang + space][lie - space] == 0 && Goboard[hang - 3 * space][lie + 3 * space] == 0)
									{
										Draw(hang - 3 * space, lie + 3 * space, num);
										return;
									}
								}
								break;
								case 4:
								{
									if (Goboard[hang + space][lie - space] == 0)
									{
										Draw(hang + space, lie - space, num);
										return;
									}
									if (Goboard[hang - 4 * space][lie + 4 * space] == 0)
									{
										Draw(hang - 4 * space, lie + 4 * space, num);
										return;
									}
								}
								break;
								}
						}
						break;
						case 2:
						{
							if (lie - space >= 1 && lie + 3 * space <= size)
								switch (ComboCheck(hang, lie, direction, space))
								{
								case 3:
								{
									if (Goboard[hang][lie - space] == 0 && Goboard[hang][lie + 3 * space] == 0)
									{
										Draw(hang, lie + 3 * space, num);
										return;
									}
								}
								break;
								case 4:
								{
									if (Goboard[hang][lie - space] == 0)
									{
										Draw(hang, lie - space, num);
										return;
									}
									if (Goboard[hang][lie + 4 * space] == 0)
									{
										Draw(hang, lie + 4 * space, num);
										return;
									}
								}
								break;
								}
						}
						break;
						case 3:
						{
							if (hang - space >= 1 && lie - space >= 1 && hang + 3 * space <= size && lie + 3 * space <= size)
								switch (ComboCheck(hang, lie, direction, space))
								{
								case 3:
								{
									if (Goboard[hang - space][lie - space] == 0 && Goboard[hang + 3 * space][lie + 3 * space] == 0)
									{
										Draw(hang + 3 * space, lie + 3 * space, num);
										return;
									}
								}
								break;
								case 4:
								{
									if (Goboard[hang - space][lie - space] == 0)
									{
										Draw(hang - space, lie - space, num);
										return;
									}
									if (Goboard[hang + 4 * space][lie + 4 * space] == 0)
									{
										Draw(hang + 4 * space, lie + 4 * space, num);
										return;
									}
								}
								break;
								}
						}
						break;
						case 4:
						{
							if (hang - space >= 1 && hang + 3 * space <= size)
								switch (ComboCheck(hang, lie, direction, space))
								{
								case 3:
								{
									if (Goboard[hang - space][lie] == 0 && Goboard[hang + 3 * space][lie] == 0)
									{
										Draw(hang + 3 * space, lie, num);
										return;
									}
								}
								break;
								case 4:
								{
									if (Goboard[hang - space][lie] == 0)
									{
										Draw(hang - space, lie, num);
										return;
									}
									if (Goboard[hang + 4 * space][lie] == 0)
									{
										Draw(hang + 4 * space, lie, num);
										return;
									}
								}
								break;
								}
						}
						break;
						}
					}
	cout << "\n  �ж϶����Ƿ�ҪӮ��  ����\n" << endl;
	//Ԥ�ж���˫����
	for (int hang = 1; hang <= size; hang++)
		for (int lie = 1; lie <= size; lie++)
			for (int space = 2; space <= 4; space++)
				for (int direction = 1; direction <= 4; direction++)
					if (Goboard[hang][lie] != num && Goboard[hang][lie] != 0 && ComboCheck(hang, lie, direction, space) == 2)
					{
						switch (direction)
						{
						case 1:
						{
							int breakcase = 0;
							for (int i = 1; i <= space - 1; i++)
							{
								if (Goboard[hang - i][lie + i] == num)
								{
									breakcase = 1;
									break;
								}
							}
							if (breakcase != 1)
							{
								for (int i = 1; i <= space - 1; i++)
								{
									if (Goboard[hang - i][lie + i] == 0)
									{
										Draw(hang - i, lie + i, num);
										return;
									}
								}
							}
						}
						break;
						case 2:
						{
							int breakcase = 0;
							for (int i = 1; i <= space - 1; i++)
							{
								if (Goboard[hang][lie + i] == num)
								{
									breakcase = 1;
									break;
								}
							}
							if (breakcase != 1)
							{
								for (int i = 1; i <= space - 1; i++)
								{
									if (Goboard[hang][lie + i] == 0)
									{
										Draw(hang, lie + i, num);
										return;
									}
								}
							}
						}
						break;
						case 3:
						{
							int breakcase = 0;
							for (int i = 1; i <= space - 1; i++)
							{
								if (Goboard[hang + i][lie + i] == num)
								{
									breakcase = 1;
									break;
								}
							}
							if (breakcase != 1)
							{
								for (int i = 1; i <= space - 1; i++)
								{
									if (Goboard[hang + i][lie + i] == 0)
									{
										Draw(hang + i, lie + i, num);
										return;
									}
								}
							}
						}
						break;
						case 4:
						{
							int breakcase = 0;
							for (int i = 1; i <= space - 1; i++)
							{
								if (Goboard[hang + i][lie] == num)
								{
									breakcase = 1;
									break;
								}
							}
							if (breakcase != 1)
							{
								for (int i = 1; i <= space - 1; i++)
								{
									if (Goboard[hang + i][lie] == 0)
									{
										Draw(hang + i, lie, num);
										return;
									}
								}
							}
						}
						break;
						}
					}
	cout << "\n  Ԥ�ж���˫����  ����\n" << endl;
	//����Χ��
	for (int hang = 1; hang <= size; hang++)
		for (int lie = 1; lie <= size; lie++)
			for (int space = 2; space <= size; space++)
				for (int direction = 1; direction <= 4; direction++)
					if (Goboard[hang][lie] != num && Goboard[hang][lie] != 0 && ComboCheck(hang, lie, direction, space) == 3)
					{
						switch (direction)
						{
						case 1:
						{
							if (Goboard[hang - 3 * space][lie - 3 * space] == num && hang + space <= size && lie - space >= 1)
							{
								Draw(hang + space, lie - space, num);
								return;
							}
						}
						break;
						case 2:
						{
							if (Goboard[hang][lie - 3 * space] == num && lie - space >= 1)
							{
								Draw(hang, lie - space, num);
								return;
							}
						}
						break;
						case 3:
						{
							if (Goboard[hang + 3 * space][lie + 3 * space] == num && hang - space >= 1 && lie - space >= 1)
							{
								Draw(hang - space, lie - space, num);
								return;
							}
						}
						break;
						case 4:
						{
							if (Goboard[hang + 3 * space][lie] == num && hang - space >= 1)
							{
								Draw(hang - space, lie, num);
								return;
							}
						}
						break;
						}
					}
	//���ؽ���
	cout << "\n  ����Χ��  ����\n" << endl;
	//����
	for (int hang = 1; hang <= size; hang++)
		for (int lie = 1; lie <= size; lie++)
			for (int space = 1; space <= size; space++)
				for (int direction = 1; direction <= 4; direction++)
					if (Goboard[hang][lie] == num && (ComboCheck(hang, lie, direction, space) == 3 || ComboCheck(hang, lie, direction, space) == 2))
					{
						switch (direction)
						{
						case 1:
						{
							int combo = ComboCheck(hang, lie, direction, space);
							if (hang - combo * space >= 1 && lie + combo * space <= size)
								if (Goboard[hang - combo * space][lie + combo * space] == 0)
								{
									Draw(hang - combo * space, lie + combo * space, num);
									return;
								}
							if (hang + space <= size && lie - space >= 1)
								if (Goboard[hang + space][lie - space] == 0)
								{
									Draw(hang + space, lie - space, num);
									return;
								}
						}
						break;
						break;
						case 2:
						{
							int combo = ComboCheck(hang, lie, direction, space);
							if (lie + combo * space <= size)
								if (Goboard[hang][lie + combo * space] == 0)
								{
									Draw(hang, lie + combo * space, num);
									return;
								}
							if (lie - space >= 1)
								if (Goboard[hang][lie - space] == 0)
								{
									Draw(hang, lie - space, num);
									return;
								}
						}
						break;
						case 3:
						{
							int combo = ComboCheck(hang, lie, direction, space);
							if (hang + combo * space <= size && lie + combo * space <= size)
								if (Goboard[hang + combo * space][lie + combo * space] == 0)
								{
									Draw(hang + combo * space, lie + combo * space, num);
									return;
								}
							if (hang - space >= 1 && lie - space >= 1)
								if (Goboard[hang - space][lie - space] == 0)
								{
									Draw(hang - space, lie - space, num);
									return;
								}
						}
						break;
						case 4:
						{
							int combo = ComboCheck(hang, lie, direction, space);
							if (hang + combo * space <= size)
								if (Goboard[hang + combo * space][lie] == 0)
								{
									Draw(hang + combo * space, lie, num);
									return;
								}
							if (hang - space >= 1)
								if (Goboard[hang - space][lie] == 0)
								{
									Draw(hang - space, lie, num);
									return;
								}
						}
						break;
						}
					}
	//��������
	cout << "\n  ����  ����\n" << endl;

	//AIΧ�������µڶ�������
	srand(time(0));
	int randirection = 1 + rand() % 3;
	for (int hang = 1; hang <= size; hang++)
		for (int lie = 1; lie <= size; lie++)
			if (Goboard[hang][lie] != 0 && Goboard[hang][lie] != num)
				switch (randirection)
				{
				case 1:
				{
					if (Goboard[hang - 1][lie + 1] == 0)
					{
						Draw(hang - 1, lie + 1, num);
						return;
					}
				}
				case 2:
				{
					if (Goboard[hang][lie + 1] == 0)
					{
						Draw(hang, lie + 1, num);
						return;
					}
				}
				case 3:
				{
					if (Goboard[hang + 1][lie + 1] == 0)
					{
						Draw(hang + 1, lie + 1, num);
						return;
					}
				}
				case 4:
				{
					if (Goboard[hang + 1][lie] == 0)
					{
						Draw(hang + 1, lie, num);
						return;
					}
				}
				default:
					break;
				}
	//AI�ڶ��ֽ���
	cout << "\n  AIΧ�������µڶ�������  ����\n" << endl;

	//AI����
	int x = 4 + rand() % (size - 6);
	int y = 4 + rand() % (size - 6);
	Draw(x, y, num);
	cout << "\n  AI����  ��������bugȥ���㣡������\n" << endl;
}
void Gobang::Draw(int hang, int lie, int num)
{
	Goboard[hang][lie] = num;
	cout << "\nѡ�� " << num << " ������λ�ã�  " << "�� " << hang << " , " << lie << " ��" << endl;
	print();
}
/*�����ýӿ�*/void Gobang::Pointest(int goboard, int num, int hang, int lie, int direction, int space)
{
	cout << "\n���ԣ�����" << "  Goboard[hang][lie]:  " << goboard << "  num:  " << num << "  hang:  " << hang << "  lie:  " << lie << "  direction:  " << direction << "  space:  " << space << endl << endl;
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
}