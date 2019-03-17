#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define UB 0x7fffffff
#define DB 0x8fffffff
#define N 85
char seq[N], sub1[N], sub2[N];
int n, l, cnt;

int dfs(int dep)
{
	char i;
	int j, flag = 0;
	if (cnt + dep > n)
	{
		/*for (j = 1; j < dep; j++)
		{
			printf("%c", seq[j]);
			if (j % 4 == 0 && j % 64 != 0) printf(" ");
			if (j % 64 == 0) printf("\n");
		}
		if ((dep - 1) % 64 != 0) printf("\n");
		printf("%d\n", dep - 1);*/
		for (j = 1; j < dep; j++)
		{
			cout << seq[j];
			if (j % 64 == 0 && j != (dep - 1))
			{
				cout << endl;
				continue;
			}
			if (j % 4 == 0 && j != (dep - 1))
				cout << " ";
		}
		cout << endl << dep - 1 << endl;
		return 1;
	}
	for (i = 'A'; i < 'A' + l; i++)
	{
		seq[dep] = i;
		for (j = 1; j <= dep / 2; j++)
		{
			memset(sub1, 0, sizeof(sub1));
			memset(sub2, 0, sizeof(sub2));
			strncpy(sub1, seq + dep - 2 * j + 1, j);
			strncpy(sub2, seq + dep - j + 1, j);
			if (!strcmp(sub1, sub2))
				flag = 1;
		}
		if (flag)
		{
			flag = 0;
			continue;
		}
		if (dfs(dep + 1))
			return 1;
		cnt++;
	}
	return 0;
}

int main()
{
	int i, len;l = 3;
	while (~scanf("%d%d", &n, &l), n || l)
	{
		cnt = 0;
		dfs(1);
	}
	return 0;
}

