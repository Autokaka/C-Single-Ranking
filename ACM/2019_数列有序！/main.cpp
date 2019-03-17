#include <iostream>
#include <stdio.h>
using namespace std;

bool cmp(int &a, int &b)
{
	if (a > b)
	{
		int tmp = a;
		a = b;
		b = tmp;
		return 1;
	}
	return 0;
}

int main()
{
	int n, m, cnt;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)
			continue;
		int *s = new int [n + 1];
		s[n] = m;
		for (int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		do
		{
			cnt = 0;
			for (int i = 0; i < n; i++)
				cnt += cmp(s[i], s[i + 1]);
		} while (cnt != 0);
		for (int i = 0; i <= n; i++)
			(i == n)? cout << s[i] << endl : cout << s[i] << " ";
	}
	return 0;
}
