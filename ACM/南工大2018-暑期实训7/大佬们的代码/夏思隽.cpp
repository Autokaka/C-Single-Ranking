//Nim��Ϸ���� �������� 
/*ǰ�����ذܵ����£�(1��2)��(3��5)��(4��7)��(6��10)��(8��13) 
���ڵ�k���ذܵ�(a(k),b(k)),a(k)��ǰ��û���ֹ�����С��Ȼ����b(k)=a(k)+k 
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
		double x=(1+sqrt(5.0))/2;//��ʽ���� 
		int t=(k*x+k);
		if(t==b)
			cout<<0<<endl;
		else
			cout<<1<<endl;
	}
	return 0;
}


