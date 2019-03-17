#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define UB 0x7fffffff
#define DB 0x8fffffff
#define N 65
int a[N], vis[N];
int n, len, num, rest;

int dfs(int k, int cur_len, int st)
{
	int i, pre = 0;
	if (k > num - 1)
	{
		return 1;
	}
	for (i = st; i < n; i++)
	{
		if (vis[i] || a[i] == pre)
			continue;
		pre = 0;
		if (cur_len + a[i] == len)
		{
			vis[i] = 1;
			rest -= a[i];
			if (dfs(k + 1, 0, 0))
				return 1;
			rest += a[i];
			vis[i] = 0;
		}
		else if (cur_len + a[i] < len)
		{
			vis[i] = 1;
			rest -= a[i];
			if (dfs(k, cur_len + a[i], i + 1))
				return 1;
			if (cur_len + rest < len)              //不取a[i]剩余的木棍总长与当前木棍的长度之和达不到len  
				break;
			rest += a[i];
			vis[i] = 0;
		}
		else if (cur_len + a[n - 1] > len)         //弱剪枝 
			break;
		pre = a[i];
	}
	return 0;
}

int main()
{
	int i, s = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		s += a[i];
	}
	sort(a, a + n, greater<int>())
	for (i = 1; i <= s; i++)
	{
		if (s % i == 0)
		{
			rest = s;
			len = i;           //小木棍的长度 
			num = s % i;       //小木棍的根数  
			memset(vis, 0, sizeof(vis)); 
			dfs(1, 0, 0);
		}
	}
	return 0;
}

