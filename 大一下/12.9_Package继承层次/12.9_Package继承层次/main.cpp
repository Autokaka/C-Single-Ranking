#include "stdafx.h"
#include"Package.h"
#include"TwoDayPackage.h"
#include"OvernightPackage.h"
#include<string>
#include<iostream>
using namespace std;


int main()
{
	string jijianren;
	string shoujianren;

	string sheng;
	string shi;
	string dizhi;
	int youzhengbianma;

	double zhongliang;
	double danweifeiyong;

	double liangripingjifei;
	double lianyepingjifei;

	for (int i = 1; i <= 3; i++)
		cout << ".\n";
	cout << "\n__________Package测试__________" << endl;
	cout << "\n请输入寄件人姓名和收件人姓名（寄件人姓名+空格+收件人姓名）：  ";
	cin >> jijianren >> shoujianren;
	cout << "\n请输入寄件省/市（省+空格+市）：  ";
	cin >> sheng >> shi;
	cout << "\n请输入收件人住址：  ";
	cin >> dizhi;
	cout << "\n请输入邮政编码：  ";
	cin >> youzhengbianma;
	cout << "\n请输入物品重量：  ";
	cin >> zhongliang;
	cout << "\n请设定物品单位费用：  ";
	cin >> danweifeiyong;
	Package a(jijianren, shoujianren, sheng, shi, dizhi, youzhengbianma, zhongliang, danweifeiyong);
	a.print();



	cout << "\n__________TwoDayPackage测试__________" << endl;
	cout << "\n请输入寄件人姓名和收件人姓名（寄件人姓名+空格+收件人姓名）：  ";
	cin >> jijianren >> shoujianren;
	cout << "\n请输入寄件省/市（省+空格+市）：  ";
	cin >> sheng >> shi;
	cout << "\n请输入收件人住址：  ";
	cin >> dizhi;
	cout << "\n请输入邮政编码：  ";
	cin >> youzhengbianma;
	cout << "\n请输入物品重量：  ";
	cin >> zhongliang;
	cout << "\n请设定物品单位费用：  ";
	cin >> danweifeiyong;
	cout << "\n请设定两日平寄费：  ";
	cin >> liangripingjifei;
	TwoDayPackage b(jijianren, shoujianren, sheng, shi, dizhi, youzhengbianma, zhongliang, danweifeiyong, liangripingjifei);
	b.print();


	cout << "\n__________OvernightPackage测试__________" << endl;
	cout << "\n请输入寄件人姓名和收件人姓名（寄件人姓名+空格+收件人姓名）：  ";
	cin >> jijianren >> shoujianren;
	cout << "\n请输入寄件省/市（省+空格+市）：  ";
	cin >> sheng >> shi;
	cout << "\n请输入收件人住址：  ";
	cin >> dizhi;
	cout << "\n请输入邮政编码：  ";
	cin >> youzhengbianma;
	cout << "\n请输入物品重量：  ";
	cin >> zhongliang;
	cout << "\n请设定物品单位费用：  ";
	cin >> danweifeiyong;
	cout << "\n请设定连夜加价单位费用：  ";
	cin >> lianyepingjifei;
	OvernightPackage c(jijianren, shoujianren, sheng, shi, dizhi, youzhengbianma, zhongliang, danweifeiyong, lianyepingjifei);
	c.print();

	system("pause");
    return 0;
}

