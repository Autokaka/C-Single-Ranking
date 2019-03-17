#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

int A[510], B[510], C[510], D[250010];

int main()
{
	int L, N, M, S, rnd = 0;
	int tgt;
	while (~scanf("%d%d%d", &L, &N, &M))
	{
		rep(i, 0, L) scanf("%d", &A[i]);
		rep(i, 0, N) scanf("%d", &B[i]);
		rep(i, 0, M) scanf("%d", &C[i]);
		int cnt = 0;
		rep(i, 0, L)
			rep(j, 0, N)
				D[cnt++] = A[i] + B[j];
		sort(D, D + cnt);
		scanf("%d", &S);
		printf("Case %d:\n", ++rnd);
		int flag;
		while(S--)
		{
			flag = 0;
			scanf("%d", &tgt);
			rep(i, 0, M)
			{
				int left = 0, right = cnt - 1, mid;
				while (left <= right)
				{
					mid = (left + right) >> 1;
					if (C[i] + D[mid] == tgt)
					{
						flag = 1;
						break;
					}
					if (C[i] + D[mid] < tgt)
						left = mid + 1;
					else
						right = mid - 1;
				}
				if(flag) break;
			}
			if (flag)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}

