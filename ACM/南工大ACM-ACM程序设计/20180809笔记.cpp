#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

#define N 10002
struct node
{
	int javabean;
	int catfood;
} rooms[N];
bool cmp(const node &n1, const node & n2)
{
	return n1.javabean * n2.catfood > n2.javabean * n1.catfood;//¾¡Á¿±ÜÃâ³ý·¨ 
}
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	int i;
	double ret = 0;
	while (cin >> m >> n, !(m == -1 && n == -1))
	{
		for (i = 0; i < n; i++)
			cin >> rooms[i].javabean >> rooms[i].catfood;
		sort(rooms, rooms + n, cmp);
		for (i = 0; i < n; i++)
		{
			if (m >= rooms[i].catfood)
			{
				ret += rooms[i].javabean;
				m -= rooms[i].catfood;
			}
			else
				break;
		}
		if (i < n)
			ret += 1.0 * rooms[i].javabean * m / rooms[i].catfood;
		printf("%.3lf\n", ret);
	}
	return 0;
}

