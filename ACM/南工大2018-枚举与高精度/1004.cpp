#include <iostream>
#include <map>
#include <cstring>
using namespace std;

char s[10000];

int main()
{
	int N;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%s", &s);
		int cnt = 1;
		for (int i = 0; i < strlen(s); i++)
		{
			if(s[i] == s[i + 1])
				cnt++;
			else
			{
				if (cnt > 1)
					printf("%d", cnt);
				printf("%c", s[i]);
				cnt = 1;
			}
		}
		printf("\n");
	}
	return 0;
}
