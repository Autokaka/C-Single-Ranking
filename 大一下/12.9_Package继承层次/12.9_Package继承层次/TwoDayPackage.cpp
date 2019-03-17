#include "stdafx.h"
#include "TwoDayPackage.h"
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

TwoDayPackage::TwoDayPackage(string jijianren, string shoujianren, string sheng, string shi, string dizhi, int youzhengbianma, double zhongliang, double danweifeiyong, double liangripingjifei)
	:Package(jijianren, shoujianren, sheng, shi, dizhi, youzhengbianma, zhongliang, danweifeiyong)
{
	twodayfare = liangripingjifei;
}

double TwoDayPackage::calculateCost()
{
	return (Package::calculateCost() + twodayfare);
}

void TwoDayPackage::print()
{
	cout << "\n__________�ʼ���Ϣ__________" << endl;

	cout << "\n�ļ��ˣ�" << getSender() << setw(20) << "�ռ��ˣ�" << getReceiver() << endl;

	cout << "\nʡ��" << getProvince() << setw(20) << "�У�" << getCity() << endl;
	cout << "�ռ���סַ��" << getAddress() << endl;

	cout << "\n�ʼ�������" << getWeight() << " kg" << setw(20) << "��λ�ʷѣ�" << getfarePerweight() << "����ƽ�ķѣ�" << twodayfare << endl;
	cout << "\n�ܼ��ʷѣ�" << calculateCost() << endl;

}
