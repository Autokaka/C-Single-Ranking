#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	char ans[100];
	int n, m;
	while (~scanf("%d%d", &n, &m))
	{
		int top = 99, flag = 1;
		if (n < 0)
		{
			flag = -1;
			n = -n;
		}
		while (top >= 0)
		{
			if (n % m >= 10)
				ans[top] = n % m - 10 + 'A';
			else
				ans[top] = n % m + '0';
			n /= m;
			if (n == 0)
				break;
			top--;
		}
		if (flag == -1)
			printf("-");
		for (int i = top; i < 100; i++)
			printf("%c", ans[i]);
		printf("\n");
	}
	return 0;
}
