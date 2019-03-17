#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define INF 0x7fffffff
#define N 20
int n, left, right, diff, cnt;
int num[N];

void dfs(int l, int r, int d)
{
	
}

int main()
{
	int t, i;
	cin >> t;
	while (t--)
	{
		cin >> n >> left >> right >> diff;
		for (i = 1; i < n; i++) cin >> num[i];
		sort(num + 1, num + 1 + n);
		dfs(left, right, diff);
		cout << cnt << endl;
	}
	return 0;
}

