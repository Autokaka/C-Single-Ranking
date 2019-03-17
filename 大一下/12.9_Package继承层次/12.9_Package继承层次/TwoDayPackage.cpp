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
	cout << "\n__________邮件信息__________" << endl;

	cout << "\n寄件人：" << getSender() << setw(20) << "收件人：" << getReceiver() << endl;

	cout << "\n省：" << getProvince() << setw(20) << "市：" << getCity() << endl;
	cout << "收件人住址：" << getAddress() << endl;

	cout << "\n邮件重量：" << getWeight() << " kg" << setw(20) << "单位邮费：" << getfarePerweight() << "两日平寄费：" << twodayfare << endl;
	cout << "\n总计邮费：" << calculateCost() << endl;

}
