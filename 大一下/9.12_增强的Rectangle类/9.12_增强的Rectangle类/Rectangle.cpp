#include"stdafx.h"


#include <iostream>
using namespace std;
#include "Rectangle.h"
#include <iomanip>
#include <cmath>

Rectangle::Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	check(x1, y1, x2, y2, x3, y3, x4, y4);
	setPosition(x1, y1, x2, y2, x3, y3, x4, y4);
}

void Rectangle::check(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	int flag1 = 1;
	do
	{
		if ((x1 < 0.0 || x1 > 20.0) || (y1 < 0 || y1 > 20))
		{
			cout << "第1个点的坐标不在第一象限或者越界，请重新输入！ \n";
			cout << "A："; 
			cin >> x1 >> y1;
			flag1 = 1;
			continue;
		}
		if ((x2 < 0.0 || x2 > 20.0) || (y2 < 0 || y2 > 20))
		{
			cout << "第2个点的坐标不在第一象限或者越界，请重新输入！ \n";
			cout << "B：";
			cin >> x2 >> y2;
			flag1 = 2;
			continue;
		}
		if ((x3 < 0.0 || x3 > 20.0) || (y3 < 0 || y3 > 20))
		{
			cout << "第3个点的坐标不在第一象限或者越界，请重新输入！ \n";
			cout << "C：";
			cin >> x3 >> y3;
			flag1 = 3;
			continue;
		}
		if ((x4 < 0.0 || x4 > 20.0) || (y4 < 0 || y4 > 20))
		{
			cout << "第4个点的坐标不在第一象限或者越界，请重新输入！ \n";
			cout << "D：";
			cin >> x4 >> y4;
			flag1 = 4;
			continue;
		}
		flag1 = 0;
	} while (flag1);

	int flag2 = checkRectangle(x1, y1, x2, y2, x3, y3, x4, y4);
	if (!flag2)
	{
		cout << "未构成矩形，请重新输入4点坐标！ \n";
		cout << "A：";
		cin >> x1 >> y1;
		cout << "B：";
		cin >> x2 >> y2;
		cout << "C：";
		cin >> x3 >> y3;
		cout << "D：";
		cin >> x4 >> y4;
		check(x1, y1, x2, y2, x3, y3, x4, y4);
	}
	else
		cout << "四点构成矩形\n";

	int flag3=checkSquare(x1, y1, x2, y2, x3, y3, x4, y4);
	if (flag3)
		cout << "还构成正方形\n";
}

int Rectangle::checkRectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	if ((pow(x1-x2,2)+pow(y1-y2,2)+pow(x2-x3,2)+pow(y2-y3,2)==pow(x1-x3,2)+pow(y1-y3,2))&&(pow(x2-x3,2)+pow(y2-y3,2)+pow(x3-x4,2)+pow(y3-y4,2)==pow(x2-x4,2)+pow(y2-y4,2)))
		return 1;
	return 0;
}

int Rectangle::checkSquare(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	if (pow(x1-x2,2)+pow(y1-y2,2)==pow(x2-x3,2)+pow(y2-y3,2))
		return 1;
	return 0;
}

void Rectangle::setPosition(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	xa = x1, ya = y1;
	xb = x2, yb = y2;
	xc = x3, yc = y3;
	xd = x4, yd = y4;
}

void Rectangle::calSystem(int command)
{
	switch (command)
	{
		case 1:
			cout << "该图形长为：" << setprecision(2) << fixed << (sqrt((xc - xb)*(xc - xb) + (yc - yb)*(yc - yb))) << endl ;
			break;
		case 2:
			cout << "该图形宽为：" << setprecision(2) << fixed << (sqrt((xa - xb)*(xa - xb) + (ya - yb)*(ya - yb))) << endl ;
			break;
		case 3:
			cout << "该图形周长为：" << 2*((sqrt((xc - xb)*(xc - xb) + (yc - yb)*(yc - yb))) + (sqrt((xa - xb)*(xa - xb) + (ya - yb)*(ya - yb)))) << endl ;
			break;
	}
}