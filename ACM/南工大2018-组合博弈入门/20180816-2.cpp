//nim-sum, 异或运算结果表示有多少种方案进入必败点， 若结果为0则必进入必败点了 
#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

int main()
{
	//按位异或运算 1^1=0; 1^0=0; 0^1=0; 0^0=1 
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

