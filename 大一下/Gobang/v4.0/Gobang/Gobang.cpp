﻿#include "stdafx.h"
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
}

void Gobang::play()
{
	cout << "\n__________我们来下五子棋吧~~~__________" << endl;
	
	int turn = -1;
	int gamestatus = -1;

	while (turn <= 0 || turn > 2)
	{
		cout << "\n【↓【↓【↓【↓【务必看说明书再食用】↓】↓】↓】↓】" << endl;
		cout << "\n  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  " << endl;
		cout << "\n  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  " << endl;
		cout << "\n 【选手1执黑子〇】【选手2执白子●】" << endl;
		cout << "\n【比赛由选手1先手】 你的选择是：  ";
		cin >> turn;
	}

	switch (turn)
	{
	case 1:
		while (gamestatus)
		{
			print();
			if (AI_x != 0 && AI_y != 0)
				cout << "\nAI落子位置：（" << AI_x << " , " << AI_y << "）\n" << endl;

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

			system("cls");
		}
		break;
	case 2:
		while (gamestatus)
		{
			print();
			if (AI_x != 0 && AI_y != 0)
				cout << "\nAI落子位置：（" << AI_x << " , " << AI_y << "）\n" << endl;

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

			system("cls");
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

void Gobang::AIGo(int num)//num是自己的号码
{
	//判断自己是不是差一步就赢了
	for (int hang = 1; hang <= size; hang++)
		for (int lie = 1; lie <= size; lie++)
			for (int space = 1; space <= size; space++)
				for (int direction = 1; direction <= 4; direction++)
					if (Goboard[hang][lie] == num && ComboCheck(hang, lie, direction, space) == 4)
					{
						switch (direction)
						{
						case 1:
						{
							if (hang + space <= size && lie - space >= 1 && hang - 4 * space >= 1 && lie + 4 * space <= size)
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
						}
						break;
						case 2:
						{
							if (lie - space >= 1 && lie + 4 * space <= size)
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
						}
						break;
						case 3:
						{
							if (hang - space >= 1 && lie - space >= 1 && hang + 4 * space <= size && lie + 4 * space <= size)
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
						}
						break;
						case 4:
						{
							if (hang - space >= 1 && hang + 4 * space <= size)
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
					}
	cout << "\n  判断自己是不是差一步就赢了  结束\n" << endl;

	//判断对面是否即将要赢了
	for (int hang = 1; hang <= size; hang++)
		for (int lie = 1; lie <= size; lie++)
			for (int space = 1; space <= size; space++)
				for (int direction = 1; direction <= 4; direction++)
					if (Goboard[hang][lie] != num && Goboard[hang][lie] != 0)
					{
						switch (direction)
						{
						case 1:
						{
							for (int i = 1; i <= 4; i++)
							{
								if (hang - i * space >= 1 && lie + i * space <= size)
								{
									if (Goboard[hang - i * space][lie + i * space] == 0)
									{
										int enemy = 0;
										(num == 1) ? enemy = 2 : enemy = 1;
										Goboard[hang - i * space][lie + i * space] = enemy;
										if (ComboCheck(hang, lie, direction, space) == 5)
										{
											Draw(hang - i * space, lie + i * space, num);
											return;
										}
										else
											Goboard[hang - i * space][lie + i * space] = 0;
									}
								}
								else
									break;
							}
						}
						break;
						case 2:
						{
							for (int i = 1; i <= 4; i++)
							{
								if (lie + i * space <= size)
								{
									if (Goboard[hang][lie + i * space] == 0)
									{
										int enemy = 0;
										(num == 1) ? enemy = 2 : enemy = 1;
										Goboard[hang][lie + i * space] = enemy;
										if (ComboCheck(hang, lie, direction, space) == 5)
										{
											Draw(hang, lie + i * space, num);
											return;
										}
										else
											Goboard[hang][lie + i * space] = 0;
									}
								}
								else
									break;
							}
						}
						break;
						case 3:
						{
							for (int i = 1; i <= 4; i++)
							{
								if (hang + i * space <= size && lie + i * space <= size)
								{
									if (Goboard[hang + i * space][lie + i * space] == 0)
									{
										int enemy = 0;
										(num == 1) ? enemy = 2 : enemy = 1;
										Goboard[hang + i * space][lie + i * space] = enemy;
										if (ComboCheck(hang, lie, direction, space) == 5)
										{
											Draw(hang + i * space, lie + i * space, num);
											return;
										}
										else
											Goboard[hang + i * space][lie + i * space] = 0;
									}
								}
								else
									break;
							}
						}
						break;
						case 4:
						{
							for (int i = 1; i <= 4; i++)
							{
								if (hang + i * space <= size)
								{
									if (Goboard[hang + i * space][lie] == 0)
									{
										int enemy = 0;
										(num == 1) ? enemy = 2 : enemy = 1;
										Goboard[hang + i * space][lie] = enemy;
										if (ComboCheck(hang, lie, direction, space) == 5)
										{
											Draw(hang + i * space, lie, num);
											return;
										}
										else
											Goboard[hang + i * space][lie] = 0;
									}
								}
								else
									break;
							}
						}
						break;
						}
						if (ComboCheck(hang, lie, direction, space) == 3 || ComboCheck(hang, lie, direction, space) == 4)
							switch (direction)
							{
							case 1:
							{
								switch (ComboCheck(hang, lie, direction, space))
								{
								case 3:
								{
									if (hang + space <= size && lie - space >= 1 && hang - 3 * space >= 1 && lie + 3 * space <= size)
										if (Goboard[hang + space][lie - space] == 0 && Goboard[hang - 3 * space][lie + 3 * space] == 0)
											if (SurroundEnemy(hang + space, lie - space, num) > SurroundEnemy(hang - 3 * space, lie + 3 * space, num))
											{
												Draw(hang + space, lie - space, num);
												return;
											}
											else
											{
												Draw(hang - 3 * space, lie + 3 * space, num);
												return;
											}
								}
								break;
								case 4:
								{
									if (hang - 4 * space >= 1 && lie + 4 * space <= size)
										if (Goboard[hang - 4 * space][lie + 4 * space] == 0)
										{
											Draw(hang - 4 * space, lie + 4 * space, num);
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
								}
							}
							break;
							case 2:
							{
								switch (ComboCheck(hang, lie, direction, space))
								{
								case 3:
								{
									if (lie - space >= 1 && lie + 3 * space <= size)
										if (Goboard[hang][lie - space] == 0 && Goboard[hang][lie + 3 * space] == 0)
											if (SurroundEnemy(hang, lie - space, num) > SurroundEnemy(hang, lie + 3 * space, num))
											{
												Draw(hang, lie - space, num);
												return;
											}
											else
											{
												Draw(hang, lie + 3 * space, num);
												return;
											}
								}
								break;
								case 4:
								{
									if (lie + 4 * space <= size)
										if (Goboard[hang][lie + 4 * space] == 0)
										{
											Draw(hang, lie + 4 * space, num);
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
								}
							}
							break;
							case 3:
							{
								switch (ComboCheck(hang, lie, direction, space))
								{
								case 3:
								{
									if (hang - space >= 1 && lie - space >= 1 && hang + 3 * space <= size && lie + 3 * space <= size)
										if (Goboard[hang - space][lie - space] == 0 && Goboard[hang + 3 * space][lie + 3 * space] == 0)
											if (SurroundEnemy(hang - space, lie - space, num) > SurroundEnemy(hang + 3 * space, lie + 3 * space, num))
											{
												Draw(hang - space, lie - space, num);
												return;
											}
											else
											{
												Draw(hang + 3 * space, lie + 3 * space, num);
												return;
											}
								}
								break;
								case 4:
								{
									if (hang + 4 * space <= size && lie + 4 * space <= size)
										if (Goboard[hang + 4 * space][lie + 4 * space] == 0)
										{
											Draw(hang + 4 * space, lie + 4 * space, num);
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
								}
							}
							break;
							case 4:
							{
								switch (ComboCheck(hang, lie, direction, space))
								{
								case 3:
								{
									if (hang - space >= 1 && hang + 3 * space <= size)
										if (Goboard[hang - space][lie] == 0 && Goboard[hang + 3 * space][lie] == 0)
											if (SurroundEnemy(hang - space, lie, num) > SurroundEnemy(hang + 3 * space, lie, num))
											{
												Draw(hang - space, lie, num);
												return;
											}
											else
											{
												Draw(hang + 3 * space, lie, num);
												return;
											}
								}
								break;
								case 4:
								{
									if (hang + 4 * space <= size)
										if (Goboard[hang + 4 * space][lie] == 0)
										{
											Draw(hang + 4 * space, lie, num);
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
							break;
							}
					}
	cout << "\n  判断对面是否即将要赢了  结束\n" << endl;

	//判断自己是否即将要赢了（三颗连子两侧空空）
	for (int hang = 1; hang <= size; hang++)
		for (int lie = 1; lie <= size; lie++)
			for (int space = 1; space <= size; space++)
				for (int direction = 1; direction <= 4; direction++)
					if (Goboard[hang][lie] == num && ComboCheck(hang, lie, direction, space) == 3)
					{
						switch (direction)
						{
						case 1:
						{
							if (hang + space <= size && lie - space >= 1 && hang - 4 * space >= 1 && lie + 4 * space <= size)
								if (Goboard[hang + space][lie - space] == 0 && Goboard[hang - 3 * space][lie + 3 * space] == 0)
								{
									if (SurroundEnemy(hang + space, lie - space, num) > SurroundEnemy(hang - 3 * space, lie + 3 * space, num))
									{
										Draw(hang + space, lie - space, num);
										return;
									}
									else
									{
										Draw(hang - 3 * space, lie + 3 * space, num);
										return;
									}
								}
						}
						break;
						case 2:
						{
							if (lie - space >= 1 && lie + 4 * space <= size)
								if (Goboard[hang][lie - space] == 0 && Goboard[hang][lie + 3 * space] == 0)
								{
									if (SurroundEnemy(hang, lie - space, num) > SurroundEnemy(hang, lie + 3 * space, num))
									{
										Draw(hang, lie - space, num);
										return;
									}
									else
									{
										Draw(hang, lie + 3 * space, num);
										return;
									}
								}
						}
						break;
						case 3:
						{
							if (hang - space >= 1 && lie - space >= 1 && hang + 4 * space <= size && lie + 4 * space <= size)
								if (Goboard[hang - space][lie - space] == 0 && Goboard[hang + 3 * space][lie + 3 * space] == 0)
								{
									if (SurroundEnemy(hang - space, lie - space, num) > SurroundEnemy(hang + 3 * space, lie + 3 * space, num))
									{
										Draw(hang - space, lie - space, num);
										return;
									}
									else
									{
										Draw(hang + 3 * space, lie + 3 * space, num);
										return;
									}
								}
						}
						break;
						case 4:
						{
							if (hang - space >= 1 && hang + 4 * space <= size)
								if (Goboard[hang - space][lie] == 0 && Goboard[hang + 3 * space][lie] == 0)
								{
									if (SurroundEnemy(hang - space, lie, num) > SurroundEnemy(hang + 3 * space, lie, num))
									{
										Draw(hang - space, lie, num);
										return;
									}
									else
									{
										Draw(hang + 3 * space, lie, num);
										return;
									}
								}
						}
						break;
						}
					}
	//判断结束
	cout << "\n  判断自己是否即将要赢了  结束\n" << endl;

	//基础围堵
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
							if (SurroundEnemy(hang + space, lie - space, num) > SurroundEnemy(hang - 3 * space, lie + 3 * space, num))
							{
								Draw(hang + space, lie - space, num);
								return;
							}
							else
							{
								Draw(hang - 3 * space, lie + 3 * space, num);
								return;
							}
						}
						break;
						case 2:
						{
							if (SurroundEnemy(hang, lie - space, num) > SurroundEnemy(hang, lie + 3 * space, num))
							{
								Draw(hang, lie - space, num);
								return;
							}
							else
							{
								Draw(hang, lie + 3 * space, num);
								return;
							}
						}
						break;
						case 3:
						{
							if (SurroundEnemy(hang - space, lie - space, num) > SurroundEnemy(hang + 3 * space, lie + 3 * space, num))
							{
								Draw(hang - space, lie - space, num);
								return;
							}
							else
							{
								Draw(hang + 3 * space, lie + 3 * space, num);
								return;
							}
						}
						break;
						case 4:
						{
							if (SurroundEnemy(hang - 3 * space, lie, num) > SurroundEnemy(hang + space, lie, num))
							{
								Draw(hang + space, lie, num);
								return;
							}
							else
							{
								Draw(hang - 3 * space, lie, num);
								return;
							}
						}
						break;
						}
					}
	//防守结束
	cout << "\n  基础围堵  结束\n" << endl;

	//预判对面双活三
	for (int hang = 1; hang <= size; hang++)
		for (int lie = 1; lie <= size; lie++)
			for (int space = 2; space <= 2; space++)
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
	cout << "\n  预判对面双活三  结束\n" << endl;
	
	//进攻
	for (int combo = 3; combo >= 1; combo--)
		for (int hang = 1; hang <= size; hang++)
			for (int lie = 1; lie <= size; lie++)
				for (int space = 1; space <= size; space++)
					for (int direction = 1; direction <= 4; direction++)
						if (Goboard[hang][lie] == num && ComboCheck(hang, lie, direction, space) == combo)
						{
							switch (direction)
							{
							case 1:
							{
								if (hang + space <= size && lie - space >= 1 && hang - 3 * space >= 1 && lie + 3 * space <= size)
								{
									if (SurroundEnemy(hang + space, lie - space, num) > SurroundEnemy(hang - combo * space, lie + combo * space, num))
									{
										Draw(hang + space, lie - space, num);
										return;
									}
									if (SurroundEnemy(hang + space, lie - space, num) < SurroundEnemy(hang - combo * space, lie + combo * space, num))
									{
										Draw(hang - combo * space, lie + combo * space, num);
										return;
									}
								}
							}
							break;
							case 2:
							{
								if (lie - space >= 1 && lie + 3 * space <= size)
								{
									if (SurroundEnemy(hang, lie - space, num) > SurroundEnemy(hang, lie + combo * space, num))
									{
										Draw(hang, lie - space, num);
										return;
									}
									if (SurroundEnemy(hang, lie - space, num) < SurroundEnemy(hang, lie + combo * space, num))
									{
										Draw(hang, lie + combo * space, num);
										return;
									}
								}
							}
							break;
							case 3:
							{
								if (hang - space >= 1 && lie - space >= 1 && hang + 3 * space <= size && lie + 3 * space <= size)
								{
									if (SurroundEnemy(hang - space, lie - space, num) > SurroundEnemy(hang + combo * space, lie + combo * space, num))
									{
										Draw(hang - space, lie - space, num);
										return;
									}
									if (SurroundEnemy(hang - space, lie - space, num) < SurroundEnemy(hang + combo * space, lie + combo * space, num))
									{
										Draw(hang + combo * space, lie + combo * space, num);
										return;
									}
								}
							}
							break;
							case 4:
							{
								if (hang - space >= 1 && hang + 3 * space <= size)
								{
									if (SurroundEnemy(hang - space, lie, num) > SurroundEnemy(hang + combo * space, lie, num))
									{
										Draw(hang - space, lie, num);
										return;
									}
									if (SurroundEnemy(hang - space, lie, num) < SurroundEnemy(hang + combo * space, lie, num))
									{
										Draw(hang + combo * space, lie, num);
										return;
									}
								}
							}
							break;
							}
						}
	//进攻结束
	cout << "\n  进攻  结束\n" << endl;

	//AI围绕先手下第二颗棋子
	srand(time(0));
	int randirection = 1 + rand() % 3;
	for (int hang = 1; hang <= size; hang++)
		for (int lie = 1; lie <= size; lie++)
			if (Goboard[hang][lie] != 0 && Goboard[hang][lie] != num)
			{
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
			}
	//AI第二手结束
	cout << "\n  AI围绕先手下第二颗棋子  结束\n" << endl;

	//AI先手
	int x = 4 + rand() % (size - 6);
	int y = 4 + rand() % (size - 6);
	Draw(x, y, num);
	cout << "\n  AI先手  结束\n" << endl;
}
void Gobang::Draw(int hang, int lie, int num)
{
	Goboard[hang][lie] = num;
	cout << "\n选手 " << num << " 的落子位置：  " << "（ " << hang << " , " << lie << " ）" << endl;
	AI_x = hang;
	AI_y = lie;
}
/*测试用接口*/void Gobang::Pointest(int goboard, int num, int hang, int lie, int direction, int space)
{
	cout << "\n测试！！！" << "  Goboard[hang][lie]:  " << goboard << "  num:  " << num << "  hang:  " << hang << "  lie:  " << lie << "  direction:  " << direction << "  space:  " << space << endl << endl;
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
		int num = Goboard[hang][lie];
		int cnt = 1;

		for (int i = 1; i <= 4; i++)//端点
		{
			if (hang - i * space < 1 || lie + i * space > size)
				return cnt;
			if (Goboard[hang - i * space][lie + i * space] != num)
				return cnt;
			else
			{
				for (int j = 1; j <= space - 1; j++)//端点之间
					if (Goboard[hang - (i - 1) * space - j][lie + (i - 1) * space + j] != 0)
						return cnt;
				
				cnt++;
			}
		}
		return cnt;
	}
	break;
	case 2://左->右
	{
		int num = Goboard[hang][lie];
		int cnt = 1;

		for (int i = 1; i <= 4; i++)//端点
		{
			if (lie + i * space > size)
				return cnt;
			if (Goboard[hang][lie + i * space] != num)
				return cnt;
			else
			{
				for (int j = 1; j <= space - 1; j++)//端点之间
					if (Goboard[hang][lie + (i - 1) * space + j] != 0)
						return cnt;
				
				cnt++;
			}
		}
		return cnt;
	}
	break;
	case 3://左上->右下
	{
		int num = Goboard[hang][lie];
		int cnt = 1;

		for (int i = 1; i <= 4; i++)//端点
		{
			if (hang + i * space > size || lie + i * space > size)
				return cnt;
			if (Goboard[hang + i * space][lie + i * space] != num)
				return cnt;
			else
			{
				for (int j = 1; j <= space - 1; j++)//端点之间
					if (Goboard[hang + (i - 1) * space + j][lie + (i - 1) * space + j] != 0)
						return cnt;

				cnt++;
			}
		}
		return cnt;
	}
	break;
	case 4://上->下
	{
		int num = Goboard[hang][lie];
		int cnt = 1;
		for (int i = 1; i <= 4; i++)//端点
		{
			if (hang + i * space > size)
				return cnt;

			if (Goboard[hang + i * space][lie] != num)
				return cnt;
			else
			{
				for (int j = 1; j <= space - 1; j++)//端点之间
					if (Goboard[hang + (i - 1) * space + j][lie] != 0)
						return cnt;

				cnt++;
			}
		}
		return cnt;
	}
	break;
	}
}
int Gobang::SurroundEnemy(int hang, int lie, int num)//num是自己的数字
{
	if (hang < 1 || hang > size || lie < 1 || lie > size || Goboard[hang][lie] != 0)
		return -1;

	int cnt = 0;
	for (int direction = 1; direction <= 4; direction++)
	{
		switch (direction)
		{
		case 1:
		{
			if (hang - 1 >= 1 && lie + 1 <= size)
				if (Goboard[hang - 1][lie + 1] != 0)
					cnt++;

			if (hang + 1 <= size && lie - 1 >= 1)
				if (Goboard[hang + 1][lie - 1] != 0)
					cnt++;
		}
		break;
		case 2:
		{
			if (lie + 1 <= size)
				if (Goboard[hang][lie + 1] != 0)
					cnt++;

			if (lie - 1 >= 1)
				if (Goboard[hang][lie - 1] != 0)
					cnt++;
		}
		break;
		case 3:
		{
			if (hang + 1 <= size && lie + 1 <= size)
				if (Goboard[hang + 1][lie + 1] != 0)
					cnt++;

			if (hang - 1 >= 1 && lie - 1 >= 1)
				if (Goboard[hang - 1][lie - 1] != 0)
					cnt++;
		}
		break;
		case 4:
		{
			if (hang + 1 <= size)
				if (Goboard[hang + 1][lie] != 0)
					cnt++;

			if (hang - 1 <= size)
				if (Goboard[hang - 1][lie] != 0)
					cnt++;
		}
		break;
		}
	}
	return cnt;
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
					cout << setw(4) << "〇" << setw(4);
					break;
				case 2:
					cout << setw(4) << "●" << setw(4);
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