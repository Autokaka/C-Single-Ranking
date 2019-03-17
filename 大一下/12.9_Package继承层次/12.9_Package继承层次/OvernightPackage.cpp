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
	cout << "\n__________邮件信息__________" << endl;

	cout << "\n寄件人：" << getSender() << setw(20) << "收件人：" << getReceiver() << endl;

	cout << "\n省：" << getProvince() << setw(20) << "市：" << getCity() << endl;
	cout << "收件人住址：" << getAddress() << endl;

	cout << "\n邮件重量：" << getWeight() << " kg" << setw(20) << "单位邮费：" << getfarePerweight() << setw(20) << "每kg所加的连夜基础费用：" << overnightfare << endl;
	cout << "\n总计邮费：" << calculateCost() << endl;

}