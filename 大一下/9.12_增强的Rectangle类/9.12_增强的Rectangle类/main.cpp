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
		cout << "��#��#��FBI Warning!!!��#��#��\n������Ͻǵĵ�һ���㿪ʼ����ʱ�����ABCD�ĵ����꣺\n";
		cout << "A��";
		cin >> xa >> ya;
		cout << "B��";
		cin >> xb >> yb;
		cout << "C��";
		cin >> xc >> yc;
		cout << "D��";
		cin >> xd >> yd;
		Rectangle rectangle1(xa, ya, xb, yb, xc, yc, xd, yd);

		int calcommand=0;
		do
		{
			cout << "\n * �������ָ�0.�˳� 1.�󳤶� 2.���� 3.���ܳ� 4.�������  ";
			cin >> calcommand;
			if (calcommand == 0)
				break;
			rectangle1.calSystem(calcommand);
			cout << " * �˳��𣿣�0.�˳� 1.������  ";
			cin >> calcommand;
		} while (calcommand!=0);
		

		cout << " * �Ƿ���������һ��㣿��y/n��  ";
		cin >> exitcommand;

	} while (exitcommand=='y');
	return 0;
}