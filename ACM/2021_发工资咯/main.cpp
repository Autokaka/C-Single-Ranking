#include <iostream>
#include <stdio.h>
using namespace std;

int main ()
{
	int n, cnt, m[6] = {100, 50, 10, 5, 2, 1};
	while (scanf("%d", &n) != EOF)
	{
		if (n <= 0)
			continue;
		int *s = new int [n];
		for (int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 6; j++)
				(s[i] / m[j] != 0)? cnt += (s[i] / m[j]), s[i] %= m[j] : 0;
		cout << cnt << endl;
		delete []s;
	}
	return 0;
}
