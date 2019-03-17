#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 7
int a[] = {1, 2, 3, 4, 5, 6}, x[N];
const int n = 6, k = 3;//第i个元素的使用情况->0未用过1用过  
int vis[N];

void dfs(int dep)
{
	int i;
	if (dep >= k)
	{
		for (i = 0; i < k; i++)
			cout << x[i] << " ";
		cout << endl;
		return;
	}
	for (i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			x[dep] = a[i];
			dfs(dep + 1);
			vis[i] = 0;
		}
	}
}

int main()
{
	dfs(0);
	return 0;
}

