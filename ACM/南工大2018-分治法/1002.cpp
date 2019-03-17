#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define X 100100

int num[X];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		rep(i, 0, n)
			scanf("%d", &num[i]);
		sort(num, num + n);
		int tgt;
		__int64 cnt = 0;
		for (int i = 0, j = 0; i < n; i++)
		{
			while(j + 1 < n && num[j + 1] - num[i] <= k) j++;
			cnt += j - i;
		}
		printf("%I64d\n", cnt);
	}
	return 0;
}

