#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define INF 0x7fffffff
#define N 10000003
int dp[N], st[N];
 
int main()
{
	int i, n;
	cin >> n;
	dp[0] = 0;
	for (i = 1; i <= n; i++)
	{
		cin >> x;
		if (dp[i - 1] > 0)
		{
			dp[i] = dp[i - 1] + x;
			st[i] = st[i - 1];
		}
		else
		{
			dp[i] = x;
			st[i] = i;
		}
	}
	int ans = -INF, st1, ed1;
	for (i = 1; i <= n; i++)
		if (ans < dp[i])
		{  
			ans = dp[i];
			st1 = st[i];
			ed1 = i;
		}
	cout << ans << endl;
	return 0;
}

