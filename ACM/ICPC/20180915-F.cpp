#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define INF 0x7fffffff
#define N 100005
#define M 205
int vis[2][N];

struct node
{
	int a, b, w;
} sub[M];

bool cmp1(node n1, node n2)
{
	if (n1.w == n2.w) return (n1.b - n1.a < n2.b - n2.a);
	return (n1.w > n2.w);
}

bool cmp2(node n1, node n2)
{
	if (n1.b - n1.a == n2.b - n2.a) return (n1.w > n2.w);
	return (n1.b - n1.a < n2.b - n2.a);
}

int main()
{
	int t, n, k, m, i, j, sum1, sum2, cnt;
	scanf("%d", &t);
	while (t--)
	{
		memset(vis, 0, sizeof(vis));
		memset(sub, 0, sizeof(sub));
		sum1 = 0, sum2 = 0;
		scanf("%d%d%d", &n, &k, &m);
		for (i = 1; i <= m; i++) scanf("%d%d%d", &sub[i].a, &sub[i].b, &sub[i].w);
		sort(sub + 1, sub + m + 1, cmp1);
		//for (i = 1; i <= m; i++) printf("Testing->	%d %d %d\n", sub[i].a, sub[i].b, sub[i].w);
		cnt = 0;
		for (i = 1; i <= m; i++)
		{
			int flag = 0;
			for (j = 1; j <= cnt / 2; j += 2)
				if (!(sub[i].b < vis[0][j] || sub[i].a > vis[0][j + 1]) && vis[1][j] >= k)
					flag = 1;
			if (flag) continue;
			sum1 += sub[i].w;
			vis[0][++cnt] = sub[i].a;
			vis[1][cnt++]++;
			vis[0][cnt] = sub[i].b;
			vis[1][cnt]++;	
		}
		sort(sub + 1, sub + m + 1, cmp2);
		//for (i = 1; i <= m; i++) printf("Testing->	%d %d %d\n", sub[i].a, sub[i].b, sub[i].w);
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		for (i = 1; i <= m; i++)
		{
			int flag = 0;
			for (j = 1; j <= cnt / 2; j += 2)
				if (!(sub[i].b < vis[0][j] || sub[i].a > vis[0][j + 1]) && vis[1][j] >= k)
					flag = 1;
			if (flag) continue;
			sum2 += sub[i].w;
			vis[0][++cnt] = sub[i].a;
			vis[1][cnt++]++;
			vis[0][cnt] = sub[i].b;
			vis[1][cnt]++;
		}
		printf("%d\n", sum1 > sum2? sum1 : sum2);
	}
	return 0;
}

