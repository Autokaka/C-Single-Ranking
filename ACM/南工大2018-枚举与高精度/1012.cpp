#include <iostream>
using namespace std;

int main()
{
	int n, h, a, b, c;
	char s;
	cin >> n;
	while (n--)
	{
		cin >> s >> h;
		c = (h - 3) / 2;
		if ((h - 3) % 2 == 0)
			a = (h - 3) / 2;
		else
			a = (h - 3) / 2 + 1;
		b = 1 + h / 6;
		for (int i = 1; i <= b; i++)
			cout << ' ';
		for (int i = 1; i <= a; i++)
			cout << s;
		printf("\n");
		for (int i = 1; i <= c; i++)
		{
			for (int j = 1; j <= 2 * b + a; j++)
			{
				if ((j >= 1 && j <= b) || (j > b + a && j <= 2 * b + a))
					cout << s;
				if (j > b && j <= b + a)
					cout << ' ';
			}
			printf("\n");
		}
		for (int i = 1; i <= b; i++)
			cout << ' ';
		for (int i = 1; i <= a; i++)
			cout << s;
		printf("\n");
		for (int i = 1; i <= a; i++)
		{
			for (int j = 1; j <= 2 * b + a; j++)
			{
				if ((j >= 1 && j <= b) || (j > b + a && j <= 2 * b + a))
					cout << s;
				if (j > b && j <= b + a)
					cout << ' ';
			}
			printf("\n");
		}
		for (int i = 1; i <= b; i++)
			cout << ' ';
		for (int i = 1; i <= a; i++)
			cout << s;
		printf("\n");
		if (n >= 1)
			printf("\n");
	}
	return 0;
}

