#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

int main()
{
	int n, m;
	double a_s, a_l;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (n > 50 || n <= 0 || m > 5 || m <= 0)
			continue;
		double **s = new double *[n + 1];
		for (int i = 0; i <= n; i++)
			s[i] = new double [m + 1];
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				s[i][j] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%lf", &s[i][j]);
		for (int i = 1; i <= n; i++)
		{
			a_s = 0;
			for (int j = 1; j <= m; j++)
			{
				a_s += s[i][j];
				if (j == m)
				{
					cout << fixed << setprecision(2) << a_s / m;
					(i == n)? cout << endl : cout << " ";
				}	
			}
		}
		for (int j = 1; j <= m; j++)
		{
			a_l = 0;
			for (int i = 1; i <= n; i++)
			{
				a_l += s[i][j];
				if (i == n)
				{
					cout << fixed << setprecision(2) << a_l / n;
					for (int k = 1; k <= n; k++)
						if (s[k][j] >= a_l / n)
							s[k][0]++;
					(j == m)? cout << endl : cout << " ";
				}
			}
		}
		for (int i = 1; i <= n; i++)
			if (s[i][0] == m)
				s[0][0]++;
		cout << int(s[0][0]) << endl;
		for (int i = 0; i <= n; i++)
			delete []s[i];
		delete []s;
	}
	return 0;
}
