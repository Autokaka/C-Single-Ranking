#include <bits/stdc++.h>
using namespace std;

#define MONEY 200

int King[1024], Tianji[1024];

int main()
{
	int n, i, *kfast, *tfast, *kslow, *tslow;
	while (~scanf("%d", &n), n)
	{
		int kwin = 0, twin = 0;
		for (i = 0; i < n; i++)
			scanf("%d", &Tianji[i]);
		for (i = 0; i < n; i++)
			scanf("%d", &King[i]);
		sort(Tianji, Tianji + n, greater<int>());
		sort(King, King + n, greater<int>());
		kfast = King, kslow = King + n - 1;
		tfast = Tianji, tslow = Tianji + n - 1;
		for (i = 0; i < n; i++)
		{
			if (*kfast > *tfast)
			{
				kfast++;
				tslow--;
				kwin++;
				continue;
			}
			if (*kfast < *tfast)
			{
				kfast++;
				tfast++;
				twin++;
				continue;
			}
			if (*kfast == *tfast)
			{
				if (*kslow >= *tslow)
				{
					if (*kfast != *tslow)
						kwin++;
					kfast++;
					tslow--;
					continue;
				}
				if (*kslow < *tslow)
				{
					kslow--;
					tslow--;
					twin++;
					continue;
				}
			}
		}
		printf("%d\n", (twin - kwin) * MONEY);
	}
	return 0;
}
