#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

int maxSeg(int *a, int left, int right)
{
	int mid = (left + right) >> 1, ret, max1, max2;
	if (left == right)
		return a[left];
	max1 = maxSeg(a, left, mid);
	max2 = maxSeg(a, mid + 1, right);
	ret = max(max1, max2);
	int tmp1, tmp2, ret1, ret2, i;
	tmp1 = ret1 = a[mid];
	for (i = mid, i >= 0; i--)
	{
		tmp1 += a[i];
		if (tmp1 > ret1)
			ret1 = tmp1;
	}
	for (i = mid + 1, i < right; i++)
	{
		tmp2 += a[i];
		if (tmp2 > ret2)
			ret2 = tmp2;
	}
	ret = max(ret, ret1 + ret2);
	return ret;
}

int main()
{
	int a[] = {2, -4, -1, 3, 6, -5, 4, 3, -2, 7};
	return 0;
}

