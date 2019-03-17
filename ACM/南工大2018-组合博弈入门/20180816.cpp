#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 10000007
int n, a, b, c;
int num[N] = {0};

int main()
{
	while (cin >> n)
	{
		cin >> a >> b >> c;
		cout << num[0] << ' ';
		rep(i, 1, 1000)
		{
			if (i >= a && num[i - a] == 0)
				num[i] = 1;
			else if (i >= b && num[i - b] == 0)
				num[i] = 1;
			else if (i >= c && num[i - c] == 0)
				num[i] = 1;
			else
				num[i] = 0;
			cout << num[i] << ' ';
		}
		cout << endl;
		//探究周期循环 
		int st = max(a, max(a, b));
		for (int i = 2 * st;;i++)
		{
			int i1 = i;
			for (int j = 0; j < i - st; j++)
			{
				int j1 = j;
				while (1)
					if (a[i1++] != a[j1++])
						break;
			}
				
		 } 
	}	
	return 0;
}

