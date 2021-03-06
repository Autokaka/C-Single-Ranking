#include "stdafx.h"


#include <iostream>
#include "IntergerSet.h"
using namespace std;

IntergerSet::IntergerSet(int arraysize)
{
	Set = new int[arraysize+1];
	for (int i=0; i <= arraysize; i++)
		Set[i] = 0;
	nMax = arraysize;
}

void IntergerSet::insertElement()
{
	int ins;
	cout << "(输入0退出...)\n";
	while (1)
	{
		cout << "添加数组元素";
		cin >> ins;
		if (ins == 0)
			break;
		while (ins > nMax)
		{
			cout << "储存的数字不在范围内(" << nMax << ")，请重新输入！  ";
			cin >> ins;
		}
		Set[ins] = 1;
	}
}
void IntergerSet::deleteElement()
{
	int del;
	cout << "(输入0退出...)\n";
	while (1)
	{
		cout << "删除数组元素";
		cin >> del;
		if (del == 0)
			break;
		while (del > nMax)
		{
			cout << "删除的数字不在范围内(" << nMax << ")，请重新输入！  ";
			cin >> del;
		}
		Set[del] = 0;
	}
}

IntergerSet IntergerSet::unionOfSets(IntergerSet set)
{//适配两个大小可能不同的集合
	if (nMax >= set.nMax)
	{
		IntergerSet temp(nMax);
		int i = 1;
		for (i; i <= set.nMax; i++)
			temp.Set[i] = (Set[i] || set.Set[i]);
		for (i; i <= nMax; i++)
			temp.Set[i] = Set[i];
		return temp;
	}
	else
	{
		IntergerSet temp(set.nMax);
		int i = 1;
		for (i; i <= nMax; i++)
			temp.Set[i] = (Set[i] || set.Set[i]);
		for (i; i <= set.nMax; i++)
			temp.Set[i] = set.Set[i];
		return temp;
	}
}
IntergerSet IntergerSet::intersectionOfSets(IntergerSet set)
{//适用于两个任意大小的数组
	int less = 0;
	if (nMax >= set.nMax)
		less = set.nMax;
	else
		less = nMax;
	IntergerSet temp(less);
	for (int i = 1; i <= less; i++)
		temp.Set[i] = (Set[i] && set.Set[i]);
	return temp;
}
IntergerSet IntergerSet::operator+(IntergerSet set)
{
	return unionOfSets(set);
}

bool IntergerSet::isEqualTo(IntergerSet set)
{//适用于两个任意大小的数组比较
	if (nMax >= set.nMax)
	{
		int i = 1;
		for (i; i <= set.nMax; i++)
			if (Set[i] != set.Set[i])
				return false;
		for (i; i <= nMax; i++)
			if (Set[i] != 0)
				return false;
	}
	else
	{
		int i = 1;
		for (i; i <= nMax; i++)
			if (Set[i] != set.Set[i])
				return false;
		for (i; i <= set.nMax; i++)
			if (set.Set[i] != 0)
				return false;
	}
	return true;
}

void IntergerSet::printSet() const
{
	int cnt=0;
	for (int i = 1; i <= nMax; i++)
		if (Set[i] == 1)
		{
			cout << i << "\t";
			cnt++;
		}
	if (cnt == 0)
		cout << "(空)";
	cout << endl;
}