#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	int n;
	char s[100];
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		scanf("%s", s);
		char tmp[100];
		strcpy(tmp, s);
		int len = strlen(s);
		for (int i = 0; i < len / 2; i++)
		{
			char temp = s[i];
			s[i] = s[len - i - 1];
			s[len - i - 1] = temp;
		}
		if(strcmp(tmp, s) == 0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
