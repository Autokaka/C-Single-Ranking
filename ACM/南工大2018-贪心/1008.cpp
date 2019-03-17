#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

struct Node
{
	int l, w, team;
} wood[5010], last[5010];

bool cmp(Node a, Node b)
{
	if (a.l == b.l)
		return a.w > b.w;
	return a.l > b.l;
}

int main()
{
	int T, n;
	scanf("%d", &T);
	while (T--)
	{
		memset(wood, 0, sizeof(wood));
		memset(last, 0, sizeof(last));
		scanf("%d", &n);
		rep (i, 0, n)
			scanf("%d%d", &wood[i].l, &wood[i].w);
		sort(wood, wood + n, cmp);
		int cnt = 1;
		wood[0].team = 1; last[cnt].l = wood[0].l; last[cnt].w = wood[0].w;
		rep(i, 1, n)
		{
			rep(j, 1, cnt + 1)
			{
				if (last[j].l >= wood[i].l && last[j].w >= wood[i].w)
				{
					last[j].l = wood[i].l;
					last[j].w = wood[i].w;
					wood[i].team = last[j].team = j;
					goto loop;
				}
			}
			cnt++;
			last[cnt].l = wood[i].l;
			last[cnt].w = wood[i].w;
			wood[i].team = last[cnt].team = cnt;
			loop: continue;
		}
		printf("%d\n", cnt);
	}
	return 0;
}

