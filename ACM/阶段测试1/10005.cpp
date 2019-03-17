#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

int main()
{
	int t, n, m, cnt;
	scanf("%d", &t);
	while (t--)
	{
		map<int, int> mp;
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d", &m);
			mp[m]++;
		}
		cnt = 0;
		map<int, int>::iterator it;
		for (it = mp.begin(); it != mp.end(); it++)
		{
			for(int i = 0; i < 32; i++)
			{
				int tmp = it->first, tmp1 = (1 << i) - tmp;
				if(mp[tmp1]==0)
				{
					mp.erase(tmp1);
					continue;
				}
				if (tmp < tmp1)
					cnt += mp[tmp1] * mp[tmp];
				else if (tmp == tmp1)
					cnt += (mp[tmp] * (mp[tmp] - 1)) / 2;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}

