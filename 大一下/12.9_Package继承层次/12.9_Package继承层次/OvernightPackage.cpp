#include "stdafx.h"
#include "OvernightPackage.h"
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;


OvernightPackage::OvernightPackage(string jijianren, string shoujianren, string sheng, string shi, string dizhi, int youzhengbianma, double zhongliang, double danweifeiyong, double lianyepingjifei)
	:Package(jijianren, shoujianren, sheng, shi, dizhi, youzhengbianma, zhongliang, danweifeiyong)
{
	overnightfare = lianyepingjifei;
}

double OvernightPackage::calculateCost()
{
	return (getWeight() * (getfarePerweight() + overnightfare));
}

void OvernightPackage::print()
{
	cout << "\n__________�ʼ���Ϣ__________" << endl;

	cout << "\n�ļ��ˣ�" << getSender() << setw(20) << "�ռ��ˣ�" << getReceiver() << endl;

	cout << "\nʡ��" << getProvince() << setw(20) << "�У�" << getCity() << endl;
	cout << "�ռ���סַ��" << getAddress() << endl;

	cout << "\n�ʼ�������" << getWeight() << " kg" << setw(20) << "��λ�ʷѣ�" << getfarePerweight() << setw(20) << "ÿkg���ӵ���ҹ�������ã�" << overnightfare << endl;
	cout << "\n�ܼ��ʷѣ�" << calculateCost() << endl;

}