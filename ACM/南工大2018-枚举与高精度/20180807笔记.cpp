#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define N 15
#define PI 3.1415926
struct point
{
	int x, y, z;
} bo[N], ul, rd;

int main()
{
	ios::sync_with_stdio(false);
	int i, j, a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int n;
	double ra, dis, ras[N] = {0}, ret = 0, retT = 0;
	cin >> n;
	cin >> ul.x >> ul.y >> ul.z;
	cin >> rd.x >> rd.y >> rd.z;
	for (i = 0; i < n; i++)
		cin >> bo[i].x >> bo[i].y >> bo[i].z;
	do
	{
		retT = 0;
		for (i = 0; i < n; i++)
		{
			ra = min(rd.x - bo[a[i]].x, bo[a[i]].x - ul.x);
			ra = min(ul.y - bo[a[i]].y, bo[a[i]].y - rd.y);
			ra = min(ul.z - bo[a[i]].z, bo[a[i]].z - rd.z);
			for (j = 0; j < i; j++)
			{
				dis = sqrt((bo[a[i]].x - bo[a[j]].x) * (bo[a[i]].x - bo[a[j]].x) + 
						   (bo[a[i]].y - bo[a[j]].y) * (bo[a[i]].y - bo[a[j]].y) + 
						   (bo[a[i]].z - bo[a[j]].z) * (bo[a[i]].z - bo[a[j]].z));
				dis -= ras[j];
				if (0 > min(ra, dis))
					ra = 0;
				else
					ra = min(ra, dis);
			}
			ras[i] = ra;
			retT += 4.0 / 3 * PI * ra * ra * ra;
		}
		ret = max(ret, retT);
	} while (next_permutation(a, a + n));//х╚ееап 
	cout << ret << endl;
	return 0;
}

