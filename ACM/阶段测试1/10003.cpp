#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define X 100100

int find(char n[], int l, int r)
{
	if (l == r)
	{
		if ((n[l] - '0') & 1)
			return -1;
		else
			return l;
	}
	int mid = (l + r) >> 1, retl, retr;
	retl = find(n, l, mid);
	retr = find(n, mid + 1, r);
	if (retl != -1 && retr != -1 && n[retl] < n[strlen(n) - 1])
		return retl;
	if (retl != -1 && retr != -1 && n[retl] > n[strlen(n) - 1])
		return retr;
	if (retl != -1 && retr == -1)
		return retl;
	if (retr != -1 && retl == -1)
		return retr;
}

int main()
{
	int t;
	char n[X];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", n);
		int pos;
		pos = find(n, 0, strlen(n) - 1);
		if (pos == -1)
		{
			printf("-1\n");
			continue;
		}
		swap(n[pos], n[strlen(n) - 1]);
		printf("%s\n", n);
		memset(n, 0, sizeof(n));
	}	
	return 0;
}

