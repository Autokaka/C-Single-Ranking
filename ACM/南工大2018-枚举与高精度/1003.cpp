#include <iostream>
using namespace std;

int main()
{
	int N, n, m;
	scanf("%d", &N);
	while (N--)
	{
		int cse = 0;
		while (~scanf("%d%d", &n, &m), n || m)
		{
			cse++;
			int a, b, cnt = 0;
			for (a = 1; a < n - 1; a++)
				for (b = a + 1; b < n; b++)
					if ((a * a + b * b + m) % (a * b) == 0)
						cnt++;
			printf("Case %d: %d\n", cse, cnt);			
		}
		if (N)
			printf("\n");
	}
	return 0;
}
