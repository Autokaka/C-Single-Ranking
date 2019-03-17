#include <stdio.h>
using namespace std;
int main()
{
	int n, m;
	while (~scanf("%d%d", &n, &m) && (m || n))
	{
		int sum = 1;
		for (int i = 1; i <= m; i++)
			sum = (sum * n) % 1000;
		printf("%d\n", sum);
	}
	return 0;
}
