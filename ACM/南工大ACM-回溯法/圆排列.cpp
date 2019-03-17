#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 7
int a[] = {1, 2, 3, 4, 5, 6}, x[N];
const int n = 6, k = 3;//第i个元素的使用情况->0未用过1用过  
int vis[N];

void dfs(int st, int dep)
{
	int i;
	if (dep >= k)
	{
		for (i = 0; i < k; i++)
			cout << x[i] << " ";
		cout << endl;
		return;
	}
	for (i = st + 1; i < n; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			x[dep] = a[i];
			dfs(st, dep + 1);
			vis[i] = 0;
		}
	}
}

int main()
{
	int i; 
	for (i = 0; i < n - k + 1; i++)
	{
		x[0] = a[i];
		dfs(i, 1);
	}
	return 0;
}

