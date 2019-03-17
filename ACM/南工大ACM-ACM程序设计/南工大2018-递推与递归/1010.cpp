#include <iostream>
using namespace std;

int main()
{
	int f[50] = {0};
	f[1] = 3, f[2] = 9;
	for (int i = 3; i < 50; i++)
		f[i] = 2 * f[i - 1] + f[i - 2];
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int m;
		scanf("%d", &m);
		printf("%d\n", f[m]);
	}
	return 0;
}
