#include <stdio.h>
using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n <= 0)
			break;
		int *s = new int [n];
		for (int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		int j = 0;
		while (++j)
		{
			int cnt = 0;
			for (int k = 0; k < n; k++)
				if (j % s[k] == 0)
					cnt++;
			if (cnt == n)
			{
				printf("%d\n", j);
				break;
			}	
		}
		delete []s;
	}
	return 0;
}
