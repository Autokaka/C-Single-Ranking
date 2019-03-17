#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define MOD 100000007

struct matrix
{
	int a11, a12, a21, a22;
	void print()
	{
		printf("%d%d%d%d\n", a11, a12, a21, a22);
	}
};

matrix mulM(matrix m1, matrix m2)
{
	matrix ret;
	ret.a11 = (m1.a11 * m2.a11 % MOD + m1.a12 * m2.a21 % MOD) % MOD;
	ret.a12 = (m1.a11 * m2.a12 % MOD + m1.a12 * m2.a22 % MOD) % MOD;
	ret.a21 = (m1.a21 * m2.a11 % MOD + m1.a22 * m2.a21 % MOD) % MOD;
	ret.a12 = (m1.a21 * m2.a12 % MOD + m1.a22 * m2.a22 % MOD) % MOD;
	return ret;
}

matrix powM(matrix m, int n)
{
	if (n == 1)
		return m;
	matrix tmp;
	tmp = powM(m, n >> 1);
	if (n & 1)
		return mulM(m, mulM(tmp, tmp));
	else
		return mulM(tmp, tmp);
}

int main()
{
	int n;
	matrix m = {1, 1, 1, 0}, ret;
	scanf("%d", &n);
	ret = powM(m, n - 1);
	printf("%d\n", (ret.a11 + ret.a12));
	return 0;
}

