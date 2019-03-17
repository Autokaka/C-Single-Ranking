#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
int n, m, sum, vis[3][4], ret;
void dfs(int x, int y)
{
	int dx, dy;
	if (sum == 5)
	{
		if (judge()) ret++;
		return;
	}
	dy = (y+1)%m;
	dx = x + (y+1)/m;
	//²»È¡ 
	dfs(dx, dy);
	//È¡ 
	vis[dx][dy] = 1;
	sum++;
	dfs(dx, dy);
	vis[dx][dy] = 0;
	sum--;
} 

int main()
{
	dfs(0, 0); 
	vis[0][0] = 1;
	sum = 1;
	dfs(0, 0);
	return 0;
}

