#include <stdio.h>//iostream和它的区别就表现在这道题里面 
#include <algorithm>
using namespace std;

#define X 1000

struct node
{
	double javabean;
	double food;	
};

bool cmp(node a, node b)
{
	return (a.javabean * b.food > b.javabean * a.food);	
}

int main()
{
	int M, N, i;
	while (scanf("%d%d", &M, &N), (-1 - M) || (-1 - N))
	{
		node room[X];
		double harvest = 0;
		for (i = 0; i < N; i++)
			scanf("%lf%lf", &room[i].javabean, &room[i].food);
		sort(room, room + N, cmp);
		for (i = 0; i < N; i++)
		{
			if (M >= room[i].food)
			{
				harvest += room[i].javabean;
				M -= room[i].food;
			}
			else
			{
				harvest += 1.0 * M * room[i].javabean / room[i].food;
				break;
			}
		}
		printf("%.3lf\n", harvest);
	}
	return 0;
}

