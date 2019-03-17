#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
#define N 2002
int prime[N], p_cnt;

int main()
{
	int m, a, b, p, q, ret_p, ret_q;
	long long tmp = 0;
	cin >> m >> a >> b;
	rp3(p, p_cnt, 0)
	{
		if (prime[p] > m) continue;
		rp2(q, p, p_cnt)
		{
			if (prime[p]*prime[q] > m) break;
			if (prime[p]*prime[q] <= m && a*prime[q] <= b*prime[p])
			{
				if (tmp < prime[p]*prime[q])
				{
					tmp = prime[p]*prime[q];
					ret_p = p;
					ret_q = q;
				}
				
			}
		}
	}
	cout << ret_p << " " << ret_q << endl;
	return 0;
}

