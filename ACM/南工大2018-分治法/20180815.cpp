//Èý·Ö·¨ 
#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define UP 100000.0

struct point
{
	double x, y;
};

int a, b, c;
point p;

double f(double x)
{
	return a * x * x + b * x + c;
}

double dis(point p1, point p2)
{
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

double triSearch(double left, double right)
{
	double lm = left + (right - left) / 3, rm = right - (right - left) / 3;
	point p1, p2;
	if (abs(right - left) < 1e-6)
		return dis(p1, p);
	p1.x = lm, p2.x = rm, p1.y = f(lm), p2.y = f(rm);
	if (dis(p1, p) <= dis(p2, p))
		return triSearch(left, rm);
	else
		return triSearch(lm, right);
}

int main()
{
	double t, ret;
	cin >> a >> b >> c;
	cin >> p.x >> p.y;
	t = -1.0 * b / 2 / a;
	if (p.x >= t)
		ret = triSearch(t, UP);
	else
		ret = triSearch(-UP, t);
	cout << ret << endl;
	return 0;
}

