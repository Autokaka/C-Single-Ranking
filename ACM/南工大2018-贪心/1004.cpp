#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for (int (x) = (y); (x) < (z); (x)++)

struct Node
{
	int D, P;
}road[10500];

bool cmp(Node a,Node b)
{return (a.P > b.P);}

int main()
{
	int N, M;
	while (~scanf("%d%d", &N, &M), N || M)
	{
		int loss = 0;
		rep(i, 0, N) 
		{
			scanf("%d%d", &road[i].D, &road[i].P);
			loss += road[i].D * road[i].P;
		}
		sort(road, road + N, cmp);
		rep(i, 0, N) 
		{
			if (M >= road[i].D)
			{
				M -= road[i].D;
				loss -= road[i].D * road[i].P;
			}
			else
			{
				loss -= M * road[i].P;
				break;
			}
		}
		printf("%d\n", loss);
	}
	return 0;
}

