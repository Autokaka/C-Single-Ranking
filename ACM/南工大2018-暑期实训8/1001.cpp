#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define UB 0x7fffffff
#define DB 0x8fffffff
#define N 1000000
int n[N];

long long qpow(long long a, long long n, long long p)
{
	if (n == 1)
		return a;
	long long tmp = qpow(a, n >> 1, p);
	if (n & 1)
		return a * tmp % p * tmp % p;
	else
		return tmp * tmp % p;
}

bool isPrime(int x)
{
	if (x == 2)
		return 1;
	long long a;
	srand(time(0));
    for(int i = 0; i < 4; i++)
    {
        a = 2 + rand() % (x - 2);
        if(qpow(a, x, x) % x != a)
			return 0;
    }
    return 1;
}

int main()
{
	int t, cnt;
	while (~scanf("%d", &t))
	{
		cnt = 0;
		rep(i, 0, t)
		{
			scanf("%d", &n[i]);
			if (isPrime(n[i]))
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}

