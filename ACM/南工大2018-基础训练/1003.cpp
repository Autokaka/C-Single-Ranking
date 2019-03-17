#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(x) for (int i = 0; i < (x); i++)

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int m;
		scanf("%d", &m);
		int *s = new int [m];
		FOR(m)
			scanf("%d", &s[i]);
		sort(s, s + m);
		FOR(m)
		{
			printf("%d", s[i]);
			if (i == m - 1)
				printf("\n");
			else
				printf(" ");
		}
		delete []s;
	}
	return 0;
}

