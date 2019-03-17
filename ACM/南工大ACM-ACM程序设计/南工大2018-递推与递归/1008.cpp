#include <iostream>
using namespace std;

int main()
{
	int f[1024] = {0};
	f[1] = 0, f[2] = 2, f[3] = 2;
	for (int i = 4; i <= 1000; i++)
		f[i] = (2 * f[i - 2] + f[i - 1]) % 10000;
	int n;
	while (~scanf("%d", &n), n)
		printf("%d\n", f[n]);
	return 0;
}
