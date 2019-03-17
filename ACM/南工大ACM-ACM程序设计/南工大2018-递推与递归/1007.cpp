#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int f[70] = {0};
	f[1] = 1; f[2] = 3;
	for (int i = 3; i <= 70; i++)
	{
		int tgt = 0x7fffffff;
		for (int j = 1; j < i; j++)
			if (tgt > 2 * f[j] + pow(2, i - j) - 1)
				tgt = 2 * f[j] + pow(2, i - j) - 1;
		f[i] = tgt;
	}
	int n;
	while(~scanf("%d", &n))
		printf("%d\n", f[n]);
	return 0;
}

