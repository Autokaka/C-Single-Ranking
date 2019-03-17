#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define INF 0x7fffffff
#define N 32

int dp[N*6];
struct node
{
	int l, w, h;
	bool operator < (struct node &n1) const
	{
		if (l == n1.l) return w > n1.w;
		return l > n1.l;
	}
} cube[N*6];

int main()
{
	int n, i, j, l, w, h;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cube[i*6].l = l;
		cube[i*6].w = w;
		cube[i*6].h = h;
		cube[i*6+1].l = w;
		cube[i*6+1].w = l;
		cube[i*6+1].h = h;
	}
	sort(cube, cube + n);
	int maxi;
	dp[0] = cube[0].h;
	for (i = 1; i < n; i++)
	{
		maxi = 0;
		for (j = 0; j < i; j++)
		{
			if (cube[i].l < cube[j].l && cube[i].w < cube[j].w)
				if (dp[j] > maxi) maxi = dp[j];
		}
		dp[i] = maxi + cube[i].h;
	}
	maxi = 0;
	for (i = 0; i < n; i++)
		if (dp[i] > maxi) maxi = dp[i];
	cout << maxi << endl;
	return 0;
}

