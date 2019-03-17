#include "stdafx.h"
#include "Gobang.h"
#include <iomanip>
#include <iostream>
using namespace std;

Gobang::Gobang(int n)
{
	while (n < 0)
	{
		cout << "输入的棋盘大小有误。请重新输入：";
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
	cout << "\n__________我们来下五子棋吧~~~__________" << endl;
	
	int turn = -1;
	int gamestatus = -1;

	while (turn <= 0 || turn > 2)
	{
		cout << "\n 【选手1：●】【选手2：〇】" << endl;
		cout << "\n【比赛由选手1先手】 你的选择是：  ";
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
				cout << "\n\n\n\n\n\n\n\n\n\n【平局！皆大欢喜！】\n\n\n\n\n\n\n\n\n" << endl;
				break;
			case 1:
				cout << "\n\n\n\n\n\n\n\n\n\n【玩家1（您自己）获胜！恭喜！】\n\n\n\n\n\n\n\n\n" << endl;
				break;
			case 2:
				cout << "\n\n\n\n\n\n\n\n\n\n【机器人获胜！】\n\n\n\n\n\n\n\n\n" << endl;
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
				cout << "\n\n\n\n\n\n\n\n\n\n【平局！皆大欢喜！】\n\n\n\n\n\n\n\n\n" << endl;
				break;
			case 1:
				cout << "\n\n\n\n\n\n\n\n\n\n【玩家1（您自己）获胜！恭喜！】\n\n\n\n\n\n\n\n\n" << endl;
				break;
			case 2:
				cout << "\n\n\n\n\n\n\n\n\n\n【机器人获胜！】\n\n\n\n\n\n\n\n\n" << endl;
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
				cout << "\n\n\n\n\n\n\n\n\n\n【平局！皆大欢喜！】\n\n\n\n\n\n\n\n\n" << endl;
				break;
			case 1:
				cout << "\n\n\n\n\n\n\n\n\n\n【玩家1（您自己）获胜！恭喜！】\n\n\n\n\n\n\n\n\n" << endl;
				break;
			case 2:
				cout << "\n\n\n\n\n\n\n\n\n\n【机器人获胜！】\n\n\n\n\n\n\n\n\n" << endl;
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
				cout << "\n\n\n\n\n\n\n\n\n\n【平局！皆大欢喜！】\n\n\n\n\n\n\n\n\n" << endl;
				break;
			case 1:
				cout << "\n\n\n\n\n\n\n\n\n\n【玩家1（您自己）获胜！恭喜！】\n\n\n\n\n\n\n\n\n" << endl;
				break;
			case 2:
				cout << "\n\n\n\n\n\n\n\n\n\n【机器人获胜！】\n\n\n\n\n\n\n\n\n" << endl;
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

	cout << "\n请选手 " << num << "（您自己）下棋：  ";
	cin >> x >> y;
	while (x < 1 || x > size || y < 1 || y > size || Goboard[x][y] != 0)
	{
		cout << "当前输入坐标不符合要求或者已经落子，请重新输入：  ";
		cin >> x >> y;
	}
	Draw(x, y, num);
}

void Gobang::AIGo(int num)
{
	//主动防御
	AIdefend(num, 2);
	//寻机进攻在Defnd完成以后自动进行

}
void Gobang::AIdefend(int num, int level)//连子的防御警戒阈值
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
						if (arry == Scoreboard[hang][lie] && ComboCheck(hang, lie, direction, space) == arry)//确实在这个方向上有这么多有可能组成五子的连子
						{
							switch (direction)
							{
							case 1:
							{
								if (hang - 4 * space < 1 || lie + 4 * space > size)
									break;

								int i = 4;//检测右边
								for (i; i >= arry; i--)
								{
									if (Goboard[hang - i * space][lie + i * space] == num)//有我方棋子
										break;
									if (i == arry)//无我方棋子
									{
										Draw(hang - arry * space, lie + arry * space, num);
										return;
									}
								}

								if (hang + space <= size && lie - space >= 1)//左侧未越界
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

								int i = 4;//检测右边
								for (i; i >= arry; i--)
								{
									if (Goboard[hang][lie + i * space] == num)//有我方棋子
										break;
									if (i == arry)//无我方棋子
									{
										Draw(hang, lie + arry * space, num);
										return;
									}
								}

								if (lie - space >= 1)//左侧未越界
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

								int i = 4;//检测右边
								for (i; i >= arry; i--)
								{
									if (Goboard[hang + i * space][lie + i * space] == num)//有我方棋子
										break;
									if (i == arry)//无我方棋子
									{
										Draw(hang + arry * space, lie + arry * space, num);
										return;
									}
								}

								if (hang - space >= 1 && lie - space >= 1)//左侧未越界
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

								int i = 4;//检测右边
								for (i; i >= arry; i--)
								{
									if (Goboard[hang + i * space][lie] == num)//有我方棋子
										break;
									if (i == arry)//无我方棋子
									{
										Draw(hang + arry * space, lie, num);
										return;
									}
								}

								if (arry < 4)
									break;

								if (hang - space >= 1)//左侧未越界
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
					cout << "\n【@【@【@【@【@【@【AI进入进攻模式！】@】@】@】@】@】" << endl;
	AIinvade(num, 3);
}
void Gobang::AIinvade(int num, int level)//连子的进攻注意阈值
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
						if ((arry + 10) == Scoreboard[hang][lie] && ComboCheck(hang, lie, direction, space) == arry)//确实在这个方向上有这么多有可能组成五子的连子
						{
							switch (direction)
							{
							case 1:
							{
								if (hang - 4 * space < 1 || lie + 4 * space > size)
									break;

								int i = 4;//检测右边
								for (i; i >= arry; i--)
								{
									if (Goboard[hang - i * space][lie + i * space] != num && Goboard[hang + i * space][lie + i * space] != 0)//有敌人棋子
										break;
									if (i == arry && Goboard[hang - i * space][lie + i * space] == 0)//无敌方棋子
									{
										Draw(hang - arry * space, lie + arry * space, num);
										return;
									}
								}

								if (hang + space <= size && lie - space >= 1)//左侧未越界
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

								int i = 4;//检测右边
								for (i; i >= arry; i--)
								{
									if (Goboard[hang][lie + i * space] != num && Goboard[hang][lie + i * space] != 0)//有敌人棋子
										break;
									if (i == arry && Goboard[hang][lie + i * space] == 0)//无敌方棋子
									{
										Draw(hang, lie + arry * space, num);
										return;
									}
								}

								if (lie - space >= 1)//左侧未越界
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

								int i = 4;//检测右边
								for (i; i >= arry; i--)
								{
									if (Goboard[hang + i * space][lie + i * space] != num && Goboard[hang + i * space][lie + i * space] != 0)//有敌人棋子
										break;
									if (i == arry && Goboard[hang + i * space][lie + i * space] == 0)//无敌方棋子
									{
										Draw(hang + arry * space, lie + arry * space, num);
										return;
									}
								}

								if (hang - space >= 1 && lie - space >= 1)//左侧未越界
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

								int i = 4;//检测右边
								for (i; i >= arry; i--)
								{
									if (Goboard[hang + i * space][lie] != num && Goboard[hang + i * space][lie] != 0)//有敌人棋子
										break;
									if (i == arry && Goboard[hang + i * space][lie] == 0)//无敌方棋子
									{
										Draw(hang + arry * space, lie, num);
										return;
									}
								}								

								if (hang - space >= 1)//左侧未越界
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
						cout << "\n您的对手：" << num << " 让了您一手！大气大气！（快去改bug啊！！！！！！）\n" << endl;
}
void Gobang::Draw(int hang, int lie, int num)
{
	Goboard[hang][lie] = num;
	cout << "\n选手 " << num << " 的落子位置：  " << "（ " << hang << " , " << lie << " ）" << endl;
	print();
}
/*测试用接口*/void Gobang::printScore()
{
	cout << "\n【@【@【@【测试落子权重系统(AI视角分析自己的可能性.分数越高,可能性越大,越安全.)】@】@】@】\n" << endl;
	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j <= size; j++)
			cout << setw(4) << Scoreboard[i][j] << setw(4);
		cout << endl << endl;
	}
}

int Gobang::judge()//(-1:还未分出胜负)(0:平局)(1:玩家1获胜)(2:玩家2获胜)
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

//返回某点处某个方向的棋子数目
int Gobang::ComboCheck(int hang, int lie, int direction, int space)
{
	if (space < 1 || hang < 1 || hang > size || lie < 1 || lie > size || Goboard[hang][lie] == 0)
		return 0;

	switch (direction)
	{
	case 1://左下->右上
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
	case 2://左->右
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
	case 3://左上->右下
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
	case 4://上->下
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
	cout << "【当前棋盘】";
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
					cout << setw(4) << "十" << setw(4);
					break;
				case 1:
					cout << setw(4) << "●" << setw(4);
					break;
				case 2:
					cout << setw(4) << "〇" << setw(4);
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