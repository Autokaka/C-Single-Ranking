//并查集数组方式查找 
#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 100

int data[N], rank[N], parent[N];

/*int find(x)//递归实现 
{
	if (x == parent[x])
		return x;
	return find(parent[x]);
}*/

int Find(int x)//递推实现 
{
	while (x != parent[x])
		x = parent[x];
	return x;
}

int Union(int x, int y)//合并 
{
	
} 

int main()
{

	return 0;
}

