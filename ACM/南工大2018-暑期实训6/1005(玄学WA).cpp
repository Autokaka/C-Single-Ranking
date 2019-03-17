#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define prec 1e-6
#define v(r) acos(-1.0)*(r)*(r)
#define X 10010
double rad[X];
int n, f;

int Sum(double avrv)
{
	int cnt = 0;
	rep(i, 0, n)
		cnt += v(rad[i]) / avrv;
	return cnt;
}

double findV(double rad[], double l, double r)
{
	if (r - l <= prec)
		return l;
	double mid = (l + r) / 2;
	if (Sum(mid) >= f + 1)
		return findV(rad, mid, r);
	else
		return findV(rad, l, mid);
}

int main()
{
	int t;
	double l, r;
	scanf("%d", &t);
	while (t--)
	{
		l = 0, r = 0;
		scanf("%d%d", &n, &f);
		rep(i, 0, n)
		{
			scanf("%lf", &rad[i]);
			if (v(rad[i]) > r)
				r = v(rad[i]);
		}
		printf("%.4lf\n", findV(rad, l, r));
	} 
	return 0;
}

