//nim-sum, �����������ʾ�ж����ַ�������ذܵ㣬 �����Ϊ0��ؽ���ذܵ��� 
#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

int main()
{
	//��λ������� 1^1=0; 1^0=0; 0^1=0; 0^0=1 
	int n;
	while (cin >> n)
	{
		int acum = 0, num;
		while (n--)
		{
			cin >> num;
			acum = (acum ^ num);
		}
		cout << acum << endl;
	}
	return 0;
}

