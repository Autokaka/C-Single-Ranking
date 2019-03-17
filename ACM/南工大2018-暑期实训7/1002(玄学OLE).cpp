#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

__int64 n, r, cnt;

int main()
{
	while (~scanf("%I64d", &n), n - 1)
	{
		r = 9, cnt = 1;
		while (n > r)
		{
			(cnt & 1)? r *= 2 : r *= 9;
			cnt++;
		}
		printf("%s\n", (cnt & 1)? "Stan wins." : "Ollie wins.");
	}
	return 0;
}

