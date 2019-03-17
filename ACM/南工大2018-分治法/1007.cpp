#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

int main()
{
	__int64 K, N;
	while (cin >> K)
	{
		while (K--)
		{
			cin >> N;
			int n = sqrt(2 * N);
			__int64 team;
			for (team = n - 1; team < n + 2; team++)
				if (team * (team + 1) >= 2 * N)
					break;
			if ((N - team * (team - 1) / 2) % 9 == 0)
				cout << 9 << endl;
			else
				cout << (N - team * (team - 1) / 2) % 9 << endl;
		}
	}
	return 0;
}

