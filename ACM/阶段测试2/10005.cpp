#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define INF 0x7fffffff
char num[11];
int fama[11];
int n, cnt, suml, sumr;

bool dfs(int dep, int last)
{
	int i;
	if (dep > n)
		return 1;
	for (i = 1; i <= cnt; i++)
	{
		if (fama[i] == last)
			continue;
		if (dep & 1)
		{
			if (suml + fama[i] > sumr)
			{
				suml += fama[i];
				if (dfs(dep + 1, fama[i])) return 1;
				suml -= fama[i];
			}
		}
		else
		{
			if (sumr + fama[i] > suml)
			{
				sumr += fama[i];
				if (dfs(dep + 1, fama[i])) return 1;
				sumr -= fama[i];
			}
		}
	}
	return 0;
}

int main()
{
	int t, flag, i;
	//scanf("%d", &t);
	cin >> t;
	while (t--)
	{
		cnt = 0, suml = 0, sumr = 0;
		//getchar();
		for (i = 1; i <= 10; i++)
		{
			cin >> num[i];
			//scanf("%c", &num[i]);
			if (num[i] - '0') fama[++cnt] = i;
		}
		scanf("%d", &n);
		//printf("%s\n", dfs(1, 0)? "YES" : "NO");
		if (dfs(1, 0)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

