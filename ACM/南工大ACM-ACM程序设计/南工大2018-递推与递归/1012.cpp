#include <iostream>
using namespace std;

int main()
{
	int l = 1, m = 1, r = 1, f[30] = {0};
	f[1] = 3;
	for (int i = 2; i < 30; i++)
	{
		int tl = l, tm = m, tr = r;
		l = tm + tl;
		r = tm + tr;
		m = tm + tl + tr;
		f[i] = l + m + r;
	}
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int gen;
		scanf("%d", &gen);
		printf("%d\n", f[gen]);
	}
	return 0;
}
