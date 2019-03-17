#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

int main()
{
	int a, b, k;
	while (~scanf("%d%d", &a, &b))
	{
		if (a > b) swap(a, b);
		k = b - a;
		printf("%d\n", a == int((k * (sqrt(5) + 1) / 2.0))? 0 : 1);
	}
	return 0;
}

