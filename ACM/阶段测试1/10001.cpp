#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

__int64 qpow(int a, int n)
{
	if (n == 0)
		return 1;
	__int64 tmp = qpow(a, n >> 1);
	if (n & 1)
		return a * tmp * tmp;
	else
		return tmp * tmp;
}

int log2(int a)
{
	if (a == 1)
		return 1 + 0;
	return 1 + log2(a >> 1);
}

int main()
{
	__int64 t, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%I64d", &n);
		__int64 acum = -1;
		int i;
		for (i = n; i >= 2; i--)
			if ((i & (i - 1)) == 0)
				break;
		if (i == 0)
		{
			printf("%I64d\n", 0);
			continue;
		}
		if (i == 1)
		{
			printf("%I64d\n", acum);
			continue;
		}
		acum = (((1 + n) * n) / 2) - (2 * (qpow(2, log2(i)) - 1));
		printf("%I64d\n", acum);
	}
	return 0;
}

