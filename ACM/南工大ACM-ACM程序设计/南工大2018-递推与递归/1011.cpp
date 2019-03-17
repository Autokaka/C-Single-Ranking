#include <iostream>
using namespace std;

long long f[1000100] = {0};

int main()
{
	f[1] = 1, f[2] = 2;
	for (int i = 3; i <= 1000000; i++)
	{
		if (i % 2 == 0)
			f[i] = f[i - 2] + f[i / 2];
		else
			f[i] = f[i - 1];
		f[i] %= 1000000000;
	}
	long long n;
	while (~scanf("%I64d", &n))
		printf("%I64d\n", f[n]);
	return 0;
}

