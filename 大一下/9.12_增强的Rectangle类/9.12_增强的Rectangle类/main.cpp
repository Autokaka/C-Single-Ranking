#include"stdafx.h"


#include <iostream>
using namespace std;
#include "Rectangle.h"

int main()
{
	char exitcommand='n';
	do
	{
		double xa, ya;
		double xb, yb;
		double xc, yc;
		double xd, yd;
		
		for (int i = 1; i <= 3; i++)
			cout << ".\n";
		cout << "【#【#【FBI Warning!!!】#】#】\n请从左上角的第一个点开始，逆时针给出ABCD四点坐标：\n";
		cout << "A：";
		cin >> xa >> ya;
		cout << "B：";
		cin >> xb >> yb;
		cout << "C：";
		cin >> xc >> yc;
		cout << "D：";
		cin >> xd >> yd;
		Rectangle rectangle1(xa, ya, xb, yb, xc, yc, xd, yd);

		int calcommand=0;
		do
		{
			cout << "\n * 输入计算指令（0.退出 1.求长度 2.求宽度 3.求周长 4.求面积）  ";
			cin >> calcommand;
			if (calcommand == 0)
				break;
			rectangle1.calSystem(calcommand);
			cout << " * 退出吗？（0.退出 1.继续）  ";
			cin >> calcommand;
		} while (calcommand!=0);
		

		cout << " * 是否再来计算一组点？（y/n）  ";
		cin >> exitcommand;

	} while (exitcommand=='y');
	return 0;
}