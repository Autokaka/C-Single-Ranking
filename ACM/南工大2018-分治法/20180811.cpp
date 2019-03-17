#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for (int (x) = (y); (x) < (z); (x)++)
#define N 10

int main()
{
	int num[N], left = 0, right = N, mid;
	rep(i, 0, 10)
		num[i] = i;
	int search, flag = 1;
	scanf("%d", &search);
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (num[mid] > search)
		{
			right = mid - 1;
			continue;
		}	
		if (num[mid] < search)
		{
			left = mid + 1;
			continue;
		}
		if (num[mid] == search)
		{
			printf("Yes\n");
			return 0;
		}
		printf("No\n");
	}
	return 0;
}

