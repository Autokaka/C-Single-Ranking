#include <stdio.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int s[3][3] = {0};
		for (int x = 1; x < 3; x++)
			for (int y = 0; y < 3; y++)
				scanf("%d", &s[x][y]);
		for (int y = 2; y >= 0; y--)
		{
			for (int x = 1; x < 3; x++)
				s[0][y] += s[x][y];
			if (y > 0 && s[0][y] >= 60)
			{
				s[0][y - 1]++;
				s[0][y] -= 60;
			}
		}
		printf("%d %d %d\n", s[0][0], s[0][1], s[0][2]);
	}
	return 0;
}
