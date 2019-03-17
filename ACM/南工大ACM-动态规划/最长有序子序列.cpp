#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define INF 0x7fffffff
#define N 1000
int a[N], dp[N], c[N], n;

int main()
{
	int i, k, m, cnt_c;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	c[0] = -INF, cnt_c = 1;
	for (i = 0; i < n; i++)
	{
		//c中查找第一个比a[i]大的元素的下标 
		k = upper_bound(c, c + cnt_c, a[i]) - c;
		dp[i] = k;
		c[k] = a[i];
		if (k >= cnt_c)
			cnt_c++;
	}
	cout << cnt_c - 1 << endl;
	m = 1;
	for (i = 1; i < cnt_c; i++)
		cout << c[i] << " ";
	cout << endl;
	return 0;
}

