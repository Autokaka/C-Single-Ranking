#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 15
int x[N], ret[N], n, W, cur = 0, ans = 0, ans1 = 0, rest;//x[i] = 0不取第i个物品; x[i] = 1取. cur当前背包已存放物品的重量; rest没有考虑的物品的价值总量  

struct node
{
	int weight, value;
} goods[N];

void dfs(int dep)
{
	int i;
	if (dep >= N)
	{
		if (ans1 > ans)
		{
			ans = ans1;
			for (i = 0; i < n; i++)
				ret[i] = x[i];
		}
		return;
	}
	//加入第dep个物品 
	if (cur + goods[dep].weight <= W)
	{
		x[dep] = 1;
		ans1 += goods[dep].value;
		cur += goods[dep].weight;
		dfs(dep + 1);
		cur -= goods[dep].weight;//一定记得回溯以后要减回去  
		ans1 -= goods[dep].value;
	}
	//不加入
	rest -= goods[dep].value;
	if (rest + ans1 > ans)
	{
		x[dep] = 0;
		dfs(dep + 1);
	}
	rest += goods[dep].value; 
}

int main()
{
	int i;
	cin >> n >> W;
	for (i = 0; i < n; i++)
	{
		cin >> goods[i].weight >> goods[i].value;
		rest += goods[i].value;
	}
	dfs(0);
	for (i = 0; i < n; i++)
		if (ret[i])
			cout << i + 1 << " ";
	cout << ans << endl;
	return 0;
}

