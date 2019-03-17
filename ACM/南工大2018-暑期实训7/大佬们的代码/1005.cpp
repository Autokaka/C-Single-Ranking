#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<set>
#include<map>
using namespace std;
int parent[1005];
int find(int x)//���Ҹ��ڵ㺯�� 
{
	if(parent[x]==x)//���ظ��ڵ� 
	return x;
	else
	{
		parent[x]=find(parent[x]);//�ݹ飬ֱ���ҵ����ڵ���� 
		return parent[x];
	}
}
void Union(int u,int v)//�ϲ� 
{
	int t1=find(u);
	int t2=find(v);
	if(t1!=t2)
	parent[t2]=t1;
}
int main()
{
	int T,i,n,m;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		int t1,t2;
		for(i=1;i<=n;i++)
		parent[i]=i;
		for(i=1;i<=m;i++)
		{
			cin>>t1>>t2;
			Union(t1,t2);
		}
		//ͳ�Ƹ��ڵ������ 
		int p=0;
		for(i=1;i<=n;i++)
		{
			if(parent[i]==i)
			p++; 
		}
		cout<<p<<endl;
	}
	return 0;
}
