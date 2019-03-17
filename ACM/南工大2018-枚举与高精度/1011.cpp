#include <iostream>
#include <cstring>
using namespace std;

char n[4][5000];
char tmp[5000];
char sum[5000];

char *add(char *a, char *b, char *c, char *d)
{
	memset(sum, 0, sizeof(sum));
	int big = 0, up = 0, i;
	if (strlen(a) > big)
		big = strlen(a);
	if (strlen(b) > big)
		big = strlen(b);
	if (strlen(c) > big)
		big = strlen(c);
	if (strlen(d) > big)
		big = strlen(d);
	for (i = big - 1; i >= strlen(a); i--)
		a[i] = '0';
	for (i = big - 1; i >= strlen(b); i--)
		b[i] = '0';
	for (i = big - 1; i >= strlen(c); i--)
		c[i] = '0';
	for (i = big - 1; i >= strlen(d); i--)
		d[i] = '0';
	for (i = 0; i < big; i++)
	{
		sum[i] = (up + a[i] - '0' + b[i] - '0' + c[i] - '0' + d[i] - '0') % 10 + '0';
		if (up + a[i] - '0' + b[i] - '0' + c[i] - '0' + d[i] - '0' >= 10)
			up = (up + a[i] - '0' + b[i] - '0' + c[i] - '0' + d[i] - '0') / 10;
		else
			up = 0;
	}
	if (up)
		sum[i] = up + '0';
	return sum;
}

int main()
{
	int m;
	while(~scanf("%d", &m), m > 0)
	{	
		for (int i = 0; i < 4; i++)
			n[i][0] = '1';
		if (m < 5)
		{
			cout << n[m - 1] << endl;
			continue;
		}
		for (int i = 4; i < m; i++)
		{
			strcpy(tmp, n[3]);
			strcpy(n[3], add(n[0], n[1], n[2], n[3]));
			strcpy(n[0], n[1]);
			strcpy(n[1], n[2]);
			strcpy(n[2], tmp);
		}
		for (int i = strlen(n[3]) - 1; i >= 0; i--)
			printf("%c", n[3][i]);
		printf("\n");
		memset(tmp, 0, sizeof(tmp));
		for (int i = 0; i < 4; i++)
			memset(n[i], 0, sizeof(n[i]));
	}
	return 0;
}
