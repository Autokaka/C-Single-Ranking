#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
vector<int>g[N];
int main()
{
	int cur, i;
	queue<int>qu;
	qu.push(1);
	vis[1] = 1;
	while(!qu.empty())
	{
		cur = qu.front();
		qu.pop();
		rp2(i, 0, g[cur].size())
		{
			now = g[cur][i];
			if (!vis[now])
			{
				vis[now] = 1;
				qu.push(now);
			}
		}
	}
	cout << endl;
	return 0;
}

