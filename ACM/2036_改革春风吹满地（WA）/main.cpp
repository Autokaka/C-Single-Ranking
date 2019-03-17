#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;

float triS(int a, int b, int c, int d, int e, int f)
{
	return sqrt(pow((a * d + b * e + c * f - a * f - b * c - d * e) / 2.0, 2));
}

int main()
{
	int n;
	while (~scanf("%d", &n) && n != 0)
	{
		int **s = new int *[n];
		for (int i = 0; i < n; i++)
			s[i] = new int [2];
		float sum = 0;
	    for (int x = 0; x < n; x++)
	    {
			scanf("%d%d", &s[x][0], &s[x][1]);
			if (x >= 2 && x < n)
				sum += triS(s[x][0], s[x][1], s[x - 1][0], s[x - 1][1], s[x - 2][0], s[x - 2][1]);
		}
		cout << fixed << setprecision(1) << sum << endl;
		for (int i = 0; i < n; i++)
			delete []s[i];
		delete []s;
	}
	return 0;
}
