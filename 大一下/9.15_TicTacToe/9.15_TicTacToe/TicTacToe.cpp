#include "stdafx.h"



#include <iostream>
using namespace std;
#include "TicTacToe.h"
#include<iomanip>
#include <cstdlib>
#include <ctime>

TicTacToe::TicTacToe()
{
	for (int fill_x = 0; fill_x <= 2; fill_x++)
	{
		for (int fill_y = 0; fill_y <= 2; fill_y++)
			chessboard[fill_x][fill_y] = 0;
	}
}

void TicTacToe::pvpMode()
{
	char exit = 'n';
	do
	{
		for (int display = 0; display <= 3; display++)
			cout << '.' << endl;
		cout << " * 游戏开始！\n";
		cnt = 0;
		srand(time(0));
		int player = 1 + rand() % 2;
		cout << " * 本局由玩家 " << player << " 先手（玩家1—>X，玩家2—>O）\n";

		int result = 0;
		do
		{
			switch (player)
			{
			case 1:
				play(1);
				cnt++;
				player = 2;
				break;
			case 2:
				play(2);
				cnt++;
				player = 1;
				break;
			}
			result = judge();
		} while (result == 0);//0继续12玩家获胜3平局

		switch (result)
		{
		case 1:
		case 2:
			cout << "\n【*【*玩家 " << result << " 获胜！*】*】\n";
			break;
		case 3:
			cout << "\n【平局！】\n";
			break;
		}

		cout << "\n * 你想要再来一局吗？（y/n）  ";
		cin >> exit;
	} while (exit == 'y');

}

void TicTacToe::pveMode()
{

}

void TicTacToe::play(int player)
{
	int x_position, y_position;
	cout << "\n * 轮到玩家 " << player << " 放置棋子（坐标）：  ";
	cin >> x_position >> y_position;
	check(x_position, y_position);
	switch (player)
	{
		case 1:
			chessboard[x - 1][y - 1] = 1;
			break;
		case 2:
			chessboard[x - 1][y - 1] = 2;
			break;
	}
	displayBoard();
}

void TicTacToe::displayBoard()
{
	cout << "\n棋盘：";
	for (int display_x = 0; display_x <= 2; display_x++)
	{
		if (display_x != 0)
			cout << setw(7);
		for (int display_y = 0; display_y <= 2; display_y++)
			switch (chessboard[display_x][display_y])
			{
			    case 0:
					cout << "_" << "  ";
					break;
				case 1:
					cout << "X" << "  ";
					break;
				case 2:
					cout << "O" << "  ";
					break;
			}	
		cout << endl;
	}
}

int TicTacToe::judge()
{
	if (cnt == 9)
		return 3;

	for (int search_x = 0; search_x <= 2; search_x++)
	{
		switch (search_x)
		{
			case 0:
				for (int search_y = 0; search_y <= 2; search_y++)
				{
					if (chessboard[search_x][search_y] != 0)
					{
						int mark = chessboard[search_x][search_y];
						if (chessboard[search_x + 1][search_y] == mark && chessboard[search_x + 2][search_y] == mark)
							return mark;
						switch (search_y)
						{
						case 0:
							if ((chessboard[search_x + 1][search_y + 1] == mark && chessboard[search_x + 2][search_y + 2] == mark)
								|| (chessboard[search_x][search_y + 1] == mark && chessboard[search_x][search_y + 2] == mark))
								return mark;
							break;
						case 2:
							if (chessboard[search_x + 1][search_y - 1] == mark && chessboard[search_x + 2][search_y - 2] == mark)
								return mark;
							break;
						}
					}
				}
				break;
			case 1:
			case 2:
				if (chessboard[search_x][0] != 0)
				{
					int mark = chessboard[search_x][0];
					if (chessboard[search_x][1] == mark && chessboard[search_x][2] == mark)
						return mark;
				}
				break;
		}
	}

	if (cnt == 9)
		return 3;

	return 0;
}

void TicTacToe::check(int x_position, int y_position)
{
	int flag = 1;
	do
	{
		if ((x_position > 3 || x_position <= 0) || (y_position > 3 || y_position <= 0))
		{
			cout << "输入的坐标不符合要求，请重新输入！  ";
			cin >> x_position >> y_position;
			continue;
		}
		
		if (chessboard[x_position - 1][y_position - 1] != 0)
		{
			cout << "此处已经被玩家放置棋子，请重新选择位置！  ";
			cin >> x_position >> y_position;
			continue;
		}

		x = x_position;
		y = y_position;
		flag = 0;
	}while (flag);
}