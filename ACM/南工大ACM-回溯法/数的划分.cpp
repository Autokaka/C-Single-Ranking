#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define UB 0x7fffffff
#define DB 0x8fffffff
#define N 7
int x[N], n, k, sum;

void dfs(int st, int dep)
{
	int i;
	if (dep >= k)
	{
		if (sum == n)
		{
			for (i = 0; i < k; i++)
				cout << x[i] << " ";
			cout << endl;
		}
		return;
	}
	for (i = st; i <= n; i++)
	{
		if (n - sum < i * (k - dep))
			break;
		sum += i;
		x[dep] = i;
		dfs(i, dep + 1);
		sum -= i;
	}
}

int main()
{
	cin >> n >> k;
	sum = 0;
	dfs(1, 0);
	return 0;
}

