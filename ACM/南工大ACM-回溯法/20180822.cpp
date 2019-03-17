#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 20
const int n = 7;
int a[N], used[N]; 

void dfs(int dep)
{
	int i;
	if (dep >= 14)
	{
		for(i = 1; i <= 14; i++)
			cout << a[i] << " ";
		cout << endl;
		return;
	}
	for (i = 1; i < 8 && dep + i + 1 <= 14; i++)
	{
		if (!used[i] && a[dep] == 0 && a[dep + i + 1] == 0)
		{
			a[dep] = i;
			a[dep + i + 1] = i;
			used[i] = 1;
			dfs(dep + 1);
			if (dep == 1 || dep == 9 || dep == 7 || dep == 2)
				goto end;
			used[i] = 0;
			a[dep + i + 1] = 0;
			a[dep] = 0;	
		}
	}
	if (a[dep])
		dfs(dep + 1);
	end:;
}

int main()
{
	a[1] = 7, a[9] = 7, a[2] = 4, a[7] = 4;
	used[4] = 1, used[7] = 1;
	dfs(3);
	return 0;
}

