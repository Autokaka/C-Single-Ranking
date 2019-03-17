#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define INF 0x7fffffff
#define N 6000
int dp[N];

int main()
{
	int n, n1, i = 1, j = 1, k = 1, m = 1;
	cin >> n;
	dp[1] = 1;
	priority_queue< pair<int, int> >;
	rep(n1, 2, n)
	{
		dp[n1] = min(2*dp[i], 3*dp[j], 5*dp[k], 7*dp[m]);
		if (dp[n1] == 2*dp[i]) i++;
		if (dp[n1] == 3*dp[j]) j++;
		if (dp[n1] == 5*dp[k]) k++;
		if (dp[n1] == 7*dp[m]) m++;
	}
	return 0;
}

