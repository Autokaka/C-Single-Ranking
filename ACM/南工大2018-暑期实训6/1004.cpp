#include <bits/stdc++.h>
using namespace std;
#define X 10010
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define prec 1e-5
double cable[X];
int n, k;

int Sum(double avrlen)
{
	int pt = 0;
	rep(i, 0, n)
		pt += cable[i] / avrlen;
	return pt;
}

double findLen(double cable[], double l, double r)
{
	if (r - l <= prec)
		return l;
	double mid = (l + r) / 2;
	if (Sum(mid) >= k)
		return findLen(cable, mid, r);
	else
		return findLen(cable, l, mid);
}

int main()
{
	double l, r;
	while (scanf("%d%d", &n, &k), n || k)
	{
		l = 0, r = 0;
		rep(i, 0, n)
		{
			scanf("%lf", &cable[i]);
			if (cable[i] > r)
				r = cable[i];
		}
		printf("%.2lf\n", findLen(cable, l, r));
	}
	return 0;
}

