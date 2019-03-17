#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

int soldier[3010];

int main()
{
	int N;
	while(~scanf("%d", &N))
	{
		map<int, int> sim;
		rep(i, 0, N)
			scanf("%d", &soldier[i]);
		sort(soldier, soldier + N, greater<int>());
		rep(i, 0, N - 1)
			if(soldier[i] == soldier[i + 1])
				sim[soldier[i]]++;
		map<int, int>::iterator it;
		int mini = sim.begin()->second;
		for (it = sim.begin(); it != sim.end(); it++)
			if (it->second > mini)
				mini = it->second;
		printf("%d\n", mini + 1);
	}
	return 0;
}

