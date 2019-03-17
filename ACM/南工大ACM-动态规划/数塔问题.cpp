#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define UB 0x7fffffff
#define DB 0x8fffffff
#define N 102
int a[N][N], dp[N][N], n;

int main()
{
	int i, j, t, n, ret;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= i; j++)
				cin >> a[i][j];
		dp[1][1] = a[1][1];
		for (i = 2; i <= n; i++)
			for (j = 1; j <= n; j++)
				dp[i][j] = a[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
		ret = 0;
		for (i = 1; i <= n; i++)
			if (dp[n][i] > ret)
				ret = dp[n][i];
		cout << ret << endl;
	}
	return 0;
}

