#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define INF 0x7fffffff
#define N 22
int dp[N][N*(N-1)/2];

int main()
{
	int n, i, j, r;
	cin >> n;
	rep(i, 0, n) dp[i][0] = 1;
	rep(i, 0, n)
		rep(r, 0, i)//与新加直线平行的数量为i - r 
			rep(j, 0, r*(r-1)/2)//求r条直线所有可能交点的情况 
				if(dp[r][j])
					dp[i][r*(i-r)+j] = 1; 
	rep(i, 0, n*(n-1)/2) if (dp[n][i]) cout << i << " ";
	cout << endl; 
	return 0;
}

