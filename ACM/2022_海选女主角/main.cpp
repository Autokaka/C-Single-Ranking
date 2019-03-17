#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		int **s = new int *[m + 1];
		for (int i = 0; i <= m; i++)
			s[i] = new int [n + 1];
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &s[i][j]);
		int x = 1, y = 1, max = s[1][1];
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (s[i][j] * s[i][j] > max * max)
				{
					x = i;
					y = j;
					max = s[i][j];
				}
		cout << x << " " << y << " " << max << endl;
		for (int i = 0; i <= m; i++)
			delete []s[i];
		delete [] s;
	}
	return 0;
}
