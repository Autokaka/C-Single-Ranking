#include <iostream>
using namespace std;

int book[500];

int main()
{
	int n;
	while (~scanf("%d", &n), n)
	{
		printf("Printing order for %d pages:\n", n);
		int pages = n / 4;
		if (n % 4 != 0)
			pages++;
		int blanks = pages * 4 - n;
		int i;
		for (i = 0; i < 4 * pages - blanks; i++)
			book[i] = i + 1;
		for (i = 4 * pages - blanks; i < 4 * pages; i++)
			book[i] = 0;
		int *r = book, *l = book + 4 * pages - 1;
		for (int i = 1; i <= pages; i++)
		{
			if (*l == 0 && *r == 0)
				break;
			printf("Sheet %d, front: ", i);
			if (*l == 0)
				printf("Blank, %d\n", *r);
			if (*l != 0 && *r != 0)
				printf("%d, %d\n", *l, *r);
			l--, r++;
			if (*l == 0 && *r == 0)
				break;
			printf("Sheet %d, back : ", i);
			if (*l == 0)
				printf("%d, Blank\n", *r);
			if (*l != 0 && *r != 0)
				printf("%d, %d\n", *r, *l);
			l--, r++;
		}
	}
	return 0;
}
