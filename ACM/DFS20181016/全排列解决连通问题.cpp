#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
int a[12] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, g[3][4]; 
int main()
{
	int ret = 0;
	do
	{
		int cnt = 0;
		rp2(i, 0, 3)
			rp2(j, 0, 4)
				g[i][j] = a[cnt++];
		if (judge()) ret++; 
	}while (priv_permutation(a, a + 12));
	cout << ret << endl;
	return 0;
}

