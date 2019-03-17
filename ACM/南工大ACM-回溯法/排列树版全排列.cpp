#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 5
char a[] = {'a', 'b', 'c', 'd'}, x[5];
int n = 4, vis[N];//第i个元素的使用情况->0未用过1用过  

void dfs(int dep)
{
	int i;
	if (dep >= n)
	{
		for (i = 0; i < n; i++)
			cout << x[i] << " ";
		cout << endl;
		return;
	}
	for (i = 0; i < 4; i++)
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

