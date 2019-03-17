#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

__int64 qpow(__int64 a, __int64 p, __int64 mod)
{
	if (p == 0)
		return 1;
	__int64 tmp = qpow(a, p >> 1, mod) % mod;
	if (p & 1)
		return a * tmp % mod * tmp % mod;
	else
		return tmp * tmp % mod;
}

bool prime(__int64 n)
{
	for (__int64 i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

int main()
{
	__int64 a, p, res;
	while (cin >> p >> a, a || p)
	{
		if (prime(p))
		{
			cout << "no\n";
			continue;
		}
		if (qpow(a, p, p) == a % p)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}

