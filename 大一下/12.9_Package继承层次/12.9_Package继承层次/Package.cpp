#include "stdafx.h"
#include "Package.h"
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

Package::Package(string jijianren, string shoujianren, string sheng, string shi, string dizhi, int youzhengbianma, double zhongliang, double danweifeiyong)
{
	sender = jijianren;
	receiver = shoujianren;

	province = sheng;
	city = shi;
	address = dizhi;
	postcode = youzhengbianma;

	setWeight(zhongliang);
	fareperweight = danweifeiyong;
}

string Package::getSender()
{
	return sender;
}
string Package::getReceiver()
{
	return receiver;
}

string Package::getProvince()
{
	return province;
}
string Package::getCity()
{
	return city;
}
string Package::getAddress()
{
	return address;
}
int Package::getPostcode()
{
	return postcode;
}

void Package::setWeight(double zhongliang)
{
	while (zhongliang < 0)
	{
		cout << "重量值输入错误，请重新输入！  ";
		cin >> zhongliang;
	}
	weight = zhongliang;
}
double Package::getWeight()
{
	return weight;
}
double Package::getfarePerweight()
{
	return fareperweight;
}

double Package::calculateCost()
{
	return (weight * fareperweight);
}

void Package::print()
{
	cout << "\n__________邮件信息__________" << endl;

	cout << "\n寄件人：" << sender << setw(20) << "收件人：" << receiver << endl;

	cout << "\n省：" << province << setw(20) << "市：" << city << endl;
	cout << "收件人住址：" << address << endl;

	cout << "\n邮件重量：" << weight << " kg" << setw(20) << "单位邮费：" << fareperweight << endl;
	cout << "\n总计邮费：" << calculateCost() << endl;

}
