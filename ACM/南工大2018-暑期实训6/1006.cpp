#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define v(a, b, c) acos(-1.0)*c*(a*a+b*b+a*b)/3
#define vcone(a, b) acos(-1.0)*a*a*b/3

int main()
{
	int t;
	double r, R, h, H, V, deltah, cone1, cone2;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lf%lf%lf%lf", &r, &R, &H, &V);
		if (R == r)
		{
			printf("%.6lf\n", V / (acos(-1.0) * R * R));
			continue;
		}
		deltah = H * r / (R - r);
		cone1 = H*(R*R+r*r+R*r)+r*r*deltah;
		cone2 = 3*V/acos(-1.0)+r*r*deltah;
		h = (H+deltah)*pow(cone2/cone1, 1.0/3)-deltah;
		printf("%.6lf\n", h);
	}
	return 0;
}

