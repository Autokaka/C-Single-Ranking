#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

int last[30100];

int main()
{
	int N, h;
	while(~scanf("%d", &N))
	{
		int cnt = 0;		
		while(N--)
		{
			int mkhigh = 0, mklow = 0;
			scanf("%d", &h);
			if (last[0] == 0)
			{
				last[0] = h;
				cnt++;
				continue;
			}
			rep(i, 0, cnt)
				if (h >= last[i])
					mkhigh++;
				else
					mklow++;
			if (mklow)
			{
				int mini = 0;
				rep(i, 0, cnt)
					if (h < last[i] && last[i] - h > mini)
					{
						mini = last[i] - h;
						mklow = i;
					}
				last[mklow] = h;
				continue;
			}
			if (mkhigh == cnt)
			{
				last[mkhigh] = h;
				cnt++;
			}		
		}
		printf("%d\n", cnt);
	}
	return 0;
}

