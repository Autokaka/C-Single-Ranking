#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define X 3
#define mod 1000000007

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
	int t, f[5] = {0, 0, 3, 4, 6};
	__int64 n;
	while (~scanf("%d", &t))
	{
		while (t--)
		{
			scanf("%I64d", &n);
			if (n <= 4)
			{
				printf("%d\n", f[n]);
				continue;
			}
			Mat T;
			memset(T.a, 0, sizeof(T.a));
			T.a[0][0] = 1, T.a[0][2] = 1, T.a[1][0] = 1, T.a[2][1] = 1;
			T = qpowM(T, n - 4);
			__int64 result = 0;
			for (int i = 0, cnt = 4; i < X; i++)
				result = (result + T.a[0][i] * f[cnt--]) % mod;
			printf("%I64d\n", result);
		}	
	}
	return 0;
}

