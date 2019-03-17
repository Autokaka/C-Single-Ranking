#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define INF 0x7fffffff
#define N 1003
char x[N], y[N];
int dp[N][N], pre[N], cur[N];

int main()
{
	int i, j, lenx, leny;
	x[0] = '0', y[0] = '0';
	cin >> x + 1 >> y + 1;
	lenx = strlen(x), leny = strlen(y);
	for (i = 0; i < lenx; i++)
		pre[i] = 0;
	for (i = 1; i < lenx; i++)
	{
		cur[0] = 0;
		for (j = 1; j < leny; j++)
		{
			if (x[i] == y[j])
				cur[j] = pre[j - 1] + 1;
			else
				cur[j] = max(cur[j - 1], pre[j]);
		}
		for (j = 0; j < leny; j++)
			pre[j] = cur[j];
		//memcpy(pre, cur, leny);
	}
	cout << cur[leny - 1] << endl;
	return 0;
}

