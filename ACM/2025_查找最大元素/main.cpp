#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
	char s[100];
	while (scanf("%s", s) != EOF)
	{
		char max = 'a';
		for (int i = 0; i < strlen(s); i++)
			if (s[i] > max)
				max = s[i];
		for (int i = 0; i < strlen(s); i++)
		{
			printf("%c", s[i]);
			if (s[i] == max)
			printf("(max)");
		}
		printf("\n");
	}
	return 0;
}
