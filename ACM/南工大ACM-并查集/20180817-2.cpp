//���鼯���鷽ʽ���� 
#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 100

int data[N], rank[N], parent[N];

/*int find(x)//�ݹ�ʵ�� 
{
	if (x == parent[x])
		return x;
	return find(parent[x]);
}*/

int Find(int x)//����ʵ�� 
{
	while (x != parent[x])
		x = parent[x];
	return x;
}

int Union(int x, int y)//�ϲ� 
{
	
} 

int main()
{

	return 0;
}

