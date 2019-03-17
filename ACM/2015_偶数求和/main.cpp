#include <iostream>
using namespace std;
int main()
{
	int n, m, team, sum;
	while (cin >> n >> m)
	{
		(n % m == 0)? team = n / m : team = n / m + 1;
		int *s = new int [team * m];
		for (int i = 0; i < n; i++)
			s[i] = 2 * (i + 1);
		for (int i = n; i < team * m; i++)
			s[i] = 0;
		for (int i = 0; i < team; i++)
		{
			sum = 0;
			for (int j = i * m; j < (i + 1) * m; j++)
				sum += s[j];
			(i == team - 1)? cout << sum / (m - (team * m - n)) << endl : cout << sum / m << " ";
		}
		delete [] s;
	}
	return 0;
}
