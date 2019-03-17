#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define X 4

int mod;

struct Mat
{
	int a[X][X];
};
//矩阵乘法 
Mat mulM(Mat m1, Mat m2)
{
	Mat ret;
	memset(ret.a, 0, sizeof(ret.a));
	rep(i, 0, X)
		rep(j, 0, X)
			rep(k, 0, X)
				ret.a[i][j] = (ret.a[i][j] + m1.a[i][k] * m2.a[k][j]) % mod;
	return ret;
}
//矩阵快速幂模运算 
Mat qpowM(Mat tgt, int n)
{
	if (n == 0)
	{
		Mat E;
		rep(i, 0, X)
			rep(j, 0, X)
				E.a[i][j] = 1;
		return E;
	}
	if (n == 1)
		return tgt;
	Mat tmp = qpowM(tgt, n >> 1);
	if (n & 1)
		return mulM(tgt, mulM(tmp, tmp));
	else
		return mulM(tmp, tmp);
}

int main()
{
	int L, f[5] = {0, 2, 4, 6, 9};
	while (~scanf("%d%d", &L, &mod))
	{
		Mat T;
		rep(i, 0, X)
			rep(j, 0, X)
				T.a[i][j] = 0;
		T.a[0][0] = 1, T.a[0][2] = 1, T.a[0][3] = 1, T.a[1][0] = 1, T.a[2][1] = 1, T.a[3][2] = 1;
		if (L <= 4)
		{
			printf("%d\n", f[L] % mod);
			continue;
		}
		T = qpowM(T, L - 4);
		int result = 0;
		for (int i = 0, cnt = X; i < X; i++)
			result = (result + T.a[0][i] * f[cnt--]) % mod;
		printf("%d\n", result);
	}
	return 0;
}

