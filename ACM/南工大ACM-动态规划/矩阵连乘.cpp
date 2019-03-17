#include <bits/stdc++.h>
using namespace std;
#define rp(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define INF 0x7fffffff
#define N 102
int p[N], dp[N][N] = {0};

int main()
{
	int n, i, j, k, r;
	rp(i, 1, n+1) cin >> p[i];
	rp(i, 0, n) rp(j, i+1, n) dp[i][j] = INF;
	rp(r, 2, n) rp(i, 1, n-r)//之所以先用r再用i，是因为在区间长度过长的时候，有些dp结果还没有被算出来。所以要先计算所有区间较小的dp值 
	{
		j = i+r-1;
		rp(k, i, j-1) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + p[i]*p[k+1]*p[j]);
	}
	return 0;
}

