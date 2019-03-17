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
		cout << "����ֵ����������������룡  ";
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
	cout << "\n__________�ʼ���Ϣ__________" << endl;

	cout << "\n�ļ��ˣ�" << sender << setw(20) << "�ռ��ˣ�" << receiver << endl;

	cout << "\nʡ��" << province << setw(20) << "�У�" << city << endl;
	cout << "�ռ���סַ��" << address << endl;

	cout << "\n�ʼ�������" << weight << " kg" << setw(20) << "��λ�ʷѣ�" << fareperweight << endl;
	cout << "\n�ܼ��ʷѣ�" << calculateCost() << endl;

}
