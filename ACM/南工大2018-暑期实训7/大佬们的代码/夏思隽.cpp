//Nim游戏变形 威佐夫博弈 
/*前几个必败点如下：(1，2)，(3，5)，(4，7)，(6，10)，(8，13) 
对于第k个必败点(a(k),b(k)),a(k)是前面没出现过的最小自然数，b(k)=a(k)+k 
a(k)= k*(1+sqrt(5)/2) */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath> 
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int a,b;
	while(cin>>a>>b)
	{
		if(a>b)
			swap(a,b);
		int k=b-a;
		double x=(1+sqrt(5.0))/2;//费式数列 
		int t=(k*x+k);
		if(t==b)
			cout<<0<<endl;
		else
			cout<<1<<endl;
	}
	return 0;
}


