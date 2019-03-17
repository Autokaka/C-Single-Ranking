#include <iostream>
using namespace std;

int main()
{
	int a, b, n;
	while (~scanf("%d%d%d", &a, &b, &n), a, b, n)
	{
		int f[60] = {0};
		f[1] = 1; f[2] = 1;
		for (int i = 3; i <= 59; i++)
			f[i] = (a * f[i - 1] % 7 + b * f[i - 2] % 7) % 7;
		int i , j, flag = 0;
		for (i = 1; i <= 49; i++)
		{
			for (j = 1; j < i; j++)
				if (f[i] == f[j] && f[i + 1] == f[j + 1])
				{
					flag = 1;
					break;
				}
			if (flag)
				break;
		}
		if (n < j)
			printf("%d\n", f[n]);
		else
			printf("%d\n", f[(n - j) % (i - j) + j]);
	}
	return 0;
}
