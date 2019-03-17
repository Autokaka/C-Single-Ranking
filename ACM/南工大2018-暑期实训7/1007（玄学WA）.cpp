#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define UB 0x7fffffff
#define DB 0x8fffffff
#define N 55
const int tile[11] = {8, 6, 9, 3, 5, 10, 14, 13, 11, 7, 15};
int m, n, sto[N][N], x[N * N];
struct node
{
	int parent;
} uf[11];

void init()
{
	int i;
	for (i = 0; i < 11; i++)
		uf[i].parent = i;
}

int Root(int x)//╢ив╘╠Ю╨е 
{
	if (x == uf[x].parent)
		return x;
	uf[x].parent = Root(uf[x].parent);
	return uf[x].parent;
}

void Union(int x, int y)
{
	x = Root(x), y = Root(y);
	if (x != y)
		uf[y].parent = x;
}

int canLink(int x, int y)
{
	int ret = 0;
	//вС 
	if (y - 1 >= 0 && (tile[sto[x][y]] & 8) && (tile[sto[x][y - 1]] & 2))
		ret += 8;
	//ио 
	if (x - 1 >= 0 && (tile[sto[x][y]] & 4) && (tile[sto[x - 1][y]] & 1))
		ret += 4; 
	//ср 
	if (y + 1 < n && (tile[sto[x][y]] & 2) && (tile[sto[x][y + 1]] & 8))
		ret += 2;
	//об 
	if (x + 1 < n && (tile[sto[x][y]] & 1) && (tile[sto[x + 1][y]] & 4))
		ret += 1;
	return ret;
}

int main()
{
	char c;
	while (~scanf("%d%d", &m, &n), m >= 0 || n >= 0)
	{
		init();
		memset(x, 0, sizeof(x));
		getchar();
		rep(i, 0, m)
		{
			rep(j, 0, n)
			{
				scanf("%c", &c);
				sto[i][j] = c - 'A';
			}
			getchar();
		}
		rep(x, 0, m)
		{
			rep(y, 0, n)
			{
				int cnt = canLink(x, y);
				//вС 
				if (cnt & 8)
					Union(sto[x][y - 1], sto[x][y]);
				//ио 
				if (cnt & 4)
					Union(sto[x - 1][y], sto[x][y]);
				//ср 
				if (cnt & 2)
					Union(sto[x][y + 1], sto[x][y]);
				//об 
				if (cnt & 1)
					Union(sto[x + 1][y], sto[x][y]);
			}	
		}
		rep(i, 0, m)
			rep(j, 0, n)
				x[Root(sto[i][j])] = 1;					
		int cnt = 0;
		rep(i, 0, N * N)
			if (x[i])
				cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}

