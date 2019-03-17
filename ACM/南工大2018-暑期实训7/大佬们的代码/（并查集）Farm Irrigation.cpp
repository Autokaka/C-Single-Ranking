#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
#include<cctype>
#include<sstream>
using namespace std;
#define N 2505
int m, n;
char area[52][52];

struct field          //���ڴ��11�����͵����ص�ˮ�ܿ��ڷ���
{                    
	//0 ��ʾ�÷���û��ˮ�ܣ�1��ʾ��ˮ��
	int n; //��
	int w; //��
	int e; //��
	int s; //��
}farm[15];

struct node          //���鼯ģ��
{
	int data;
	int parent;   
	int rank;
	node() :rank(1) {}
}uf[N];

int find(int x)     
{
	int k = x, k1 = x;
	while (k != uf[k].parent)
	{
		k = uf[k].parent;
	}
	while (x != uf[x].parent)
	{
		k1 = uf[x].parent;
		uf[x].parent = k;
		x = k1;
	}
	return x;
}
void Union(int x, int y)    
{
	x = find(x), y = find(y);
	if (x != y)
	{
		if (uf[x].rank < uf[y].rank)
		{
			uf[x].parent = y;
		}
		else
		{
			uf[y].parent = x;
			if (uf[x].rank == uf[y].rank)
				uf[x].rank++;           
		}
	}
}
void ini()               //��ʼ��
{
	for (int i = 1; i <= n*m; i++)     
	{
		uf[i].parent = i;
	}
}

int findthecase()        //���Ҳ��鼯����
{
	int ans = 0;
	for (int i = 1;i <= n * m;i++)
		if (uf[i].parent == i)
			ans++;
	return ans;
}
int main()
{
	//��ʼ��11�����͵�����
	farm[1].n = farm[2].n = farm[5].n = farm[7].n = farm[8].n = farm[10].n = farm[11].n = 1;
	farm[3].s = farm[4].s = farm[5].s = farm[8].s = farm[9].s = farm[10].s = farm[11].s = 1;
	farm[2].e = farm[4].e = farm[6].e = farm[7].e = farm[9].e = farm[10].e = farm[11].e = 1;
	farm[1].w = farm[3].w = farm[6].w = farm[7].w = farm[8].w = farm[9].w = farm[11].w = 1;
	while (cin>>m>>n && n>=0 && m>=0)
	{
		ini();
		memset(area, 0, sizeof(area));
		for (int i = 1;i <= m;i++)
		{
			getchar();
			for (int j = 1;j <= n;j++)
				cin >> area[i][j];
		}
		for (int i = 1;i <= m;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				int a = (i - 1)*n + j;     // a ��ʾ��ǰ��λ��
				//�����жϣ���ǰλ�õ��·�������λ�õ��Ϸ���ˮ��
				if ( farm[(area[i][j] - 'A' + 1)].s == 1 && farm[(area[i + 1][j] - 'A' + 1)].n == 1)
					Union(a, i*n + j);
				//�����жϣ���ǰλ�õ��ҷ����ұ߷��������ˮ��
				if ( farm[(area[i][j] - 'A' + 1)].e == 1 && farm[(area[i][j + 1] - 'A' + 1)].w == 1)
					Union(a, a + 1);
			}
		}
		int ans = findthecase();
		cout << ans << endl;
	}
}
