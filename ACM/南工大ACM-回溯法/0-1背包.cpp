#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 15
int x[N], ret[N], n, W, cur = 0, ans = 0, ans1 = 0, rest;//x[i] = 0��ȡ��i����Ʒ; x[i] = 1ȡ. cur��ǰ�����Ѵ����Ʒ������; restû�п��ǵ���Ʒ�ļ�ֵ����  

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
	//�����dep����Ʒ 
	if (cur + goods[dep].weight <= W)
	{
		x[dep] = 1;
		ans1 += goods[dep].value;
		cur += goods[dep].weight;
		dfs(dep + 1);
		cur -= goods[dep].weight;//һ���ǵû����Ժ�Ҫ����ȥ  
		ans1 -= goods[dep].value;
	}
	//������
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

