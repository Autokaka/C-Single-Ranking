#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
#define N 10002
#define lt tree[tree<<1]
#define rt tree[tree<<1|1]
struct mode
{
	int max, lmax, rmax, w;
} tree[N<<2];

void push_up(int rt)//区间合并问题的push_up 
{
	tree[rt].max = max(max(lt.max, rt.max), lt.rmax + rt.lmax);
	tree[rt].lmax = lt.lmax + ((lt.max == lt.w)? rt.lmax : 0);
	tree[rt].rmax = rt.rmax + ((rt.max == rt.w)? lt.rmax : 0);
	tree[rt].w = lt.w + rt.w;
}

int main()
{

	return 0;
}

