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
	rp(r, 2, n) rp(i, 1, n-r)//֮��������r����i������Ϊ�����䳤�ȹ�����ʱ����Щdp�����û�б������������Ҫ�ȼ������������С��dpֵ 
	{
		j = i+r-1;
		rp(k, i, j-1) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + p[i]*p[k+1]*p[j]);
	}
	return 0;
}

