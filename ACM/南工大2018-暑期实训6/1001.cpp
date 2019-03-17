#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define X 2
#define mod 998244353

struct Mat
{
	__int64 a[X][X];
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
Mat qpowM(Mat tgt, __int64 n)
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
	__int64 k, f[2] = {0, 1};
	while (~scanf("%d", &k))
	{
		Mat T;
		T.a[0][0] = 1, T.a[0][1] = 1, T.a[1][0] = 1, T.a[1][1] = 0;
		T = qpowM(T, 2 * k + 2);
		__int64 result = 0;
		for (int i = 0, cnt = 1; i < X; i++)
			result = (result + T.a[0][i] * f[cnt--]) % mod;
		printf("%d\n", result - 1);
	}
	return 0;
}

