include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define INF 0x7fffffff

int f(long long x)
{
	int tmp = (x + 1) % 4;
	if (tmp == 0) return 0;
	else if (tmp == 1) return x;
	else if (tmp == 2) return x ^ (x - 1);
	else return x ^ (x - 1) ^ (x - 2);
}

int main()
{
	int n;
	long long ni, xi, ret = 0;
	for (i = 0; i < n; i++)
	{
		cin >> ni >> xi;
		ret = ret ^ f(xi + ni - 1) ^ f(xi - 1);
	}
	if (ret == 0) cout << "Lose\n";
	else cout << "Win\n";
	return 0;
}

