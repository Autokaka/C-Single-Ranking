#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
#define N 10003
struct node 
{
	int a, h;
	double li, ri;
} tree[N];

struct node1
{
	int b, z;
} mr[N];

int n, m, pos[N];
double p[N], lazy[N<<2];

map<int, int> num;

void push_down(int rt)
{
	
}

void update (int left, int right, int L, int R, int rt, int p)
{
	int i;
	if (left == right && right == R)
	{
		lazy[rt] = p;
		return;
	}
	push_down(rt);
	int mid = (left+right) >> 1;
	if (L < mid) update(left, mid, rt<<1, L, R, p);
	else update(mid+1, right, rt<<1|1, L, R ,p);
}

double query(int left, int right, int rt, int pos)
{
	if (left == right) return p[left];
	int mid = (left+right) >> 1;
	if (mid >= pos) query(left, mid, rt<<1, pos);
	
}

int main()
{
	int i;
	cin >> n >> m;
	for (i = 0; i < n; i ++)
	{
		cin >> tree[i].a >> tree[i].h >> tree[i].li >> tree[i].ri;
		tree[i].li = 1 - tree[i].li / 100.0;
		tree[i].ri = 1 - tree[i].ri / 100.0;
		pos[i] = tree[i].a;
	}
	for (i = 0; i < m; i ++) cin >> mr[i].b >> mr[i].z;
	sort(pos, pos + n);
	int cnt = unique(pos, pos + n) - pos;
	for (i = 0; i < cnt; i ++) num[pos[i]] = i;
	for (i = 0; i < n; i++) p[i] = 1;
	for (i = 0; i < n; i++)
	{
		update (0; cnt - 1, 1, tree[i].a - tree[i].h, tree[i].a - 1, )
	}
	return 0;
}

