#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

char a[1000], b[1000], tmp[1000], flag;

void fplus(char *fmr, char *ltr)
{
	int up = 0, i, big, small;
	char tfmr[1000], tltr[1000], result[2000];
	strcpy(tfmr, fmr), strcpy(tltr, ltr);
	if (strlen(fmr) > strlen(ltr))
	{
		big = strlen(fmr), small = strlen(ltr);
		for (i = small; i < big; i++)
			ltr[i] = '0';
	}	
	else
	{
		big = strlen(ltr), small = strlen(fmr);
		for (i = small; i < big; i++)
			fmr[i] = '0';
	}
	for (i = 0; i < big; i++)
	{
		result[i] = (up + fmr[i] - '0' + ltr[i] - '0') % 10 + '0';
		if (up + fmr[i] - '0' + ltr[i] - '0' >= 10)
			up = (up + fmr[i] - '0' + ltr[i] - '0') / 10;
		else
			up = 0;
	}
	if (up)
		result[i] = up + '0';
	if (strlen(tltr) + 1 > big)
		big = strlen(tltr) + 1;
	if (strlen(result) > big)
		big = strlen(result);
	cout << setw(big - strlen(tfmr) + 1);
	for (i = strlen(tfmr) - 1; i >= 0; i--)
		cout << tfmr[i];
	cout << endl << setw(big - strlen(tltr)) << flag;
	for (i = strlen(tltr) - 1; i >= 0; i--)
		cout << tltr[i];
	cout << endl;
	for (i = 0; i < big; i++)
		cout << '-';
	cout << endl << setw(big - strlen(result) + 1);
	for (i = strlen(result) - 1; i >= 0; i--)
		cout << result[i];
	cout << endl;
	memset(fmr, 0, sizeof(fmr));
	memset(ltr, 0, sizeof(ltr));
	memset(tfmr, 0, sizeof(tfmr));
	memset(tltr, 0, sizeof(tltr));
	memset(result, 0, sizeof(result));
}

void fminus(char *fmr, char *ltr)
{
	int down = 0, i, big = strlen(fmr);	
	char tltr[1000], result[2000];
	strcpy(tltr, ltr);
	for (i = big - 1; i >= strlen(ltr); i--)
		tltr[i] = '0';
	for (i = 0; i < strlen(fmr); i++)
	{
		result[i] = (fmr[i] - tltr[i] - down) + '0';
		if (fmr[i] - tltr[i] - down < 0)
		{
			result[i] += 10;
			down = 1;
		}
		else
			down = 0;
	}
	if (strlen(fmr) > big)
		big = strlen(fmr);
	if (strlen(ltr) + 1 > big)
		big = strlen(ltr) + 1;
	cout << setw(big - strlen(fmr) + 1);
	for (i = strlen(fmr) - 1; i >= 0; i--)
		cout << fmr[i];
	cout << endl << setw(big - strlen(ltr)) << flag;
	for (i = strlen(ltr) - 1; i >= 0; i--)
		cout << ltr[i];
	cout << endl;
	for (i = 0; i < big; i++)
		cout << '-';
	cout << endl;
	for (i = strlen(result) - 1; i > 0; i--)
	{
		if (result[i] == '0' && result[i - 1] == '0')
		{
			cout << ' ';
			continue;
		}	
		if (result[i] == '0' && result[i - 1] != '0')
		{
			i--;
			cout << ' ';
			break;
		}
		if (result[i] != 0)
			break;	
	}
	for (; i >= 0; i--)
		cout << result[i];
	cout << endl;
	memset(fmr, 0, sizeof(fmr));
	memset(ltr, 0, sizeof(ltr));
	memset(tltr, 0, sizeof(tltr));
	memset(result, 0, sizeof(result));
}

void fmultiply(char *fmr, char *ltr)
{
	int row = 0, i, j, up = 0, big;
	char result[2000], current[1000];
	if (strlen(fmr) > strlen(ltr))
		big = strlen(fmr);
	else
		big = strlen(ltr);
	for (i = 0; i <= big; i++)
		result[i] = '0', current[i] = '0';
	for (j = 0; j < strlen(ltr); j++)
	{
		for (i = 0; i < strlen(fmr); i++)
		{
			current[i + row] = ((fmr[i] - '0') * (ltr[j] - '0')) % 10 + '0';
			if ((fmr[i] - '0') * (ltr[j] - '0') >= 10)
				up = (fmr[i] - '0') * (ltr[j] - '0') / 10;
			else
				up = 0;
		}
		up = 0;
		for (i = 0; i < strlen(current); i++)
		{
			if (up + result[i] - '0' + current[i] - '0' >= 10)
				up = (up + result[i] - '0' + current[i] - '0') / 10;
			else
				up = 0;
			result[i] = (up + result[i] - '0' + current[i] - '0') % 10 + '0';
		}
		row++;	
	}
	cout << result << endl;
	memset(fmr, 0, sizeof(fmr));
	memset(ltr, 0, sizeof(ltr));
	memset(result, 0, sizeof(result));
	memset(result, 0, sizeof(current));
}

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		gets(tmp);
		int mid;
		for (mid = 0; mid < strlen(tmp); mid++)
			if (tmp[mid] == '+' || tmp[mid] == '-' || tmp[mid] == '*')
			{
				flag = tmp[mid];
				break;
			}	
		int i;
		for (i = 0; i < mid; i++)
			a[i] = tmp[mid - 1 - i];
		for (i = 0; i < strlen(tmp) - mid - 1; i++)
			b[i] = tmp[strlen(tmp) - 1 - i];
		switch(flag)
		{
			case '+':
				fplus(a, b);
				break;
			case '-':
				fminus(a, b);
				break;
			case '*':
				fmultiply(a, b);
				break;
		}
	}
	return 0;
}

