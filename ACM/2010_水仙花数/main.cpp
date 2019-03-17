#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		if (!(m >= 100 && m <= n && n <= 999))
			continue;		
		for (; n > m; n--)
			if (pow(n / 100, 3) + pow(n / 10 % 10, 3) + pow(n % 10, 3) == n)
				break;
		for (; m <= n; m++)
			if (pow(m / 100, 3) + pow(m / 10 % 10, 3) + pow(m % 10, 3) == m)
			{
				cout << m;
				if (m != n)
					cout << " ";
				else
					break;
			}
		(m > n)? cout << "no" << endl : cout << endl;
	}
	return 0;
}
