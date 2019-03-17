#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
#define N 8
int dir[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
int vis[N][N];
pair< pair<int, int>, int >cur;
pair<int, int>cur1;
queue< pair< pair<int, int>, int > >qu;

int main()
{
	int i, x, y, x1, y1, x2, y2, dx, dy;
	while(cin >> x1 >> y1 >> x2 >> y2)
	{
		memset(vis, 0, sizeof(vis));
		qu.push(make_pair(make_pair(x1, y1), 0));
		vis[x1][y1] = 1;
		while(!qu.empty())
		{
			cur = qu.front();
			cur1 = cur.first;
			x = cur1.first;
			y = cur1.second;
			if (x == x2 && y == y2)
			{
				cout << "From " << x << " to " << y << " takes " << cur.second << " times\n";
				break;
			}
			qu.pop();
			rp2(i, 0, 8)
			{
				dx = x + dir[i][0];
				dy = y + dir[i][1];
				if (dx < 0 || dx >= 8 || dy < 0 || dy >= 8) continue;
				if (!vis[dx][dy])
				{
					vis[dx][dy] = 1;
					qu.push(make_pair(make_pair(dx, dy), cur.second+1));
				}
			}
		}
		cout << endl;
	}
	return 0;
}

