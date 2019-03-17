#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for (int (x) = (y); (x) < (z); (x)++)

struct Node
{
	int candy, opleft, opright;
};

int main()
{
	int T, n;
	scanf("%d", &T);
	while (T--)
	{
		int cnt = 0;
		Node soda[100100];
		scanf("%d", &n);
		rep(i, 0, n) {scanf("%d", &soda[i].candy);cnt += soda[i].candy;}
		if(cnt < n) {printf("NO\n"); out: continue;}
		if(cnt % n == 0)
		{
			cnt /= n;
			rep(i, 0, n)
				if (soda[i].candy - cnt > 2 || cnt - soda[i].candy > 2) {printf("NO\n");goto out;}
				else {printf("YES\n"); break;}
		}
		while (1)
		{
			int flag = 0;
			rep(i, 1, n)
			{
				if(soda[i - 1].candy < soda[i].candy && soda[i - 1].candy <= cnt && soda[i].candy >= cnt && soda[i - 1].opright < 1 && soda[i].opleft < 1) 
				{
					soda[i].candy--;
					soda[i - 1].candy++;
					soda[i - 1].opright++;
					soda[i].opleft++;
					printf("%d %d\n", i + 1, i);
				}
				else if(soda[i - 1].candy > soda[i].candy && soda[i].candy <= cnt && soda[i - 1].candy >= cnt && soda[i - 1].opright < 1 && soda[i].opleft < 1)
				{
					soda[i].candy++;
					soda[i - 1].candy--;
					soda[i - 1].opright++;
					soda[i].opleft++;
					printf("%d %d\n", i, i + 1);
				}
				else flag++;
			}
			if(soda[n - 1].candy < soda[0].candy && soda[n - 1].candy <= cnt && soda[0].candy >= cnt && soda[n - 1].opright < 1 && soda[0].opleft < 1) 
			{
				soda[0].candy--;
				soda[n - 1].candy++;
				soda[n - 1].opright++;
				soda[0].opleft++;
				printf("%d %d\n", 1, n);
			}
			else if(soda[n - 1].candy > soda[0].candy && soda[0].candy <= cnt && soda[n - 1].candy >= cnt && soda[n - 1].opright < 1 && soda[0].opleft < 1)
			{
				soda[0].candy++;
				soda[n - 1].candy--;
				soda[n - 1].opright++;
				soda[0].opleft++;
				printf("%d %d\n", n, 1);
			}
			else flag++;
			if(flag == n)
				break;
		}
	}
	return 0;
}

