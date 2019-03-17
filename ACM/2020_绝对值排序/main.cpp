#include <iostream>
#include <stdio.h>
using namespace std;

bool cmp2(int &a, int &b)
{
	if (a * a < b * b)
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
	int n, cnt;
	while (scanf("%d", &n) != EOF)
	{
		if (n <= 0)
			continue;
		int *s = new int [n];
		for (int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		do
		{
			cnt = 0;
			for (int i = 0; i < n - 1; i++)
				cnt += cmp2(s[i], s[i + 1]);
		} while (cnt != 0);
		for (int i = 0; i < n; i++)
			(i == n - 1)? cout << s[i] << endl : cout << s[i] << " ";
		delete []s;
	}
	return 0;
}
