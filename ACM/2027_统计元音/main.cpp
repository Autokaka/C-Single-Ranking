#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	int n, len;
	char s[100];
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		gets(s);
		len = strlen(s);
		int a = 0, e = 0, i = 0, o = 0, u = 0;
		for (int x = 0; x < len; x++)
		{
			(s[x] == 'a')? a++ : 0;
			(s[x] == 'e')? e++ : 0;
			(s[x] == 'i')? i++ : 0;
			(s[x] == 'o')? o++ : 0;
			(s[x] == 'u')? u++ : 0;
		}
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", a, e, i, o, u);
		if (n)
			printf("\n");
	}
	return 0;
}
