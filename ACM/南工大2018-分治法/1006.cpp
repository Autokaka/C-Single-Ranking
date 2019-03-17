#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

int main()
{
	int T, x, m, k, c, sum;
	scanf("%d", &T);
	rep(cnt, 0, T)
	{
		sum = 0;
		scanf("%d%d%d%d", &x, &m, &k, &c);
		for(int i = 0; i < m; i++)
			sum = (10 * sum + x % k) % k;
		printf("Case #%d:\n", cnt + 1);
		if (sum == c)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
