#include <stdio.h>
using namespace std;

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		int **s = new int *[n];
		for (int i = 0; i < n; i++)
			s[i] = new int [n];
		for (int x = 0; x < n; x++)
		{
			s[x][0] = 1;
			for (int y = 1; y < n; y++)
				s[x][y] = 0;
		}	
		for (int x = 1; x < n; x++)
			for (int y = 1; y < n; y++)
				s[x][y] = s[x - 1][y] + s[x - 1][y - 1];
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < x + 1; y++)
			{
				printf("%d", s[x][y]);
				if (y != x)
					printf(" ");
				else
					printf("\n");
			}
			if (x == n - 1)
				printf("\n");
		}
		for (int i = 0; i < n; i++)
			delete []s[i];
		delete []s;
	}
	return 0;
}
