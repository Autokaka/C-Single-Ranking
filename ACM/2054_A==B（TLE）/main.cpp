#include <iostream>
#include <string.h>
using namespace std;

int begin(char *s)
{
	for (int i = 0; i < strlen(s) - 1;)
	{
		if (s[i] == '0' && s[i + 1] != '.')
			i++;
		else
			return i;	
	}
}

int end(char *s)
{
	int dot = 0;
	for (int i = 0; i < strlen(s); i++)
		if (s[i] == '.')
		{
			dot = 1;
			break;
	    }
	if (dot == 0)
		return strlen(s) - 1;
	else
	{
		for (int i = strlen(s) - 1; i >= 0; i--)
		{
			if (s[i] == '.')
				return --i;
			if (s[i] != '0')
				return i;	
		}
	}
}

int main()
{
	char a[100], b[100];
	while (cin >> a >> b)
	{
		int ab = begin(a), ae = end(a);
		int bb = begin(b), be = end(b);
		if ((ae - ab) != (be - bb))
		{
			cout << "NO\n";
			loop: continue;
		}
		for (int j = 0; j < ae - ab + 1; j++)
			if (a[j + ab] != b[j + bb])
			{
				cout << "NO\n";
				goto loop;
			}
		cout << "YES\n";
	}
	return 0;
}
