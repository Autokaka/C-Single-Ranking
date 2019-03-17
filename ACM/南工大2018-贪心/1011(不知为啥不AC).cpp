#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

struct Node
{
	int time, level;
} machine[100100], task[100100];

bool cmp(Node a, Node b)
{
	if (a.time == b.time)
		return (a.level > b.level);
	return (a.time > b.time);
}

int main()
{
	int N, M;
	while (~scanf("%d%d", &N, &M))
	{
		rep(i, 0, N)
			scanf("%d%d", &machine[i].time, &machine[i].level);
		rep(i, 0, M)
			scanf("%d%d", &task[i].time, &task[i].level);
		sort(machine, machine + N, cmp);
		sort(task, task + M, cmp);
		int t = 0, levelcnt[110] = {0};
		__int64 sum = 0;
		rep(i, 0, M)
		{
			int j = 0;
			while(machine[i].time >= task[i].time && j < N)
			{
				levelcnt[machine[i].level]++;
				j++;
			}
			rep(k, task[i].level, 101)
			{
				if(levelcnt[k])
				{
					levelcnt[k]--;
					t++;
					sum += (__int64)(500 * task[i].time + 2 * task[i].level);
					break;
				}
			}
		}
		printf("%d %I64d\n",t ,sum);
	}
	return 0;
}

