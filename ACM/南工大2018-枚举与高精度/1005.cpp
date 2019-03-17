#include <iostream>
#include <cstring>

using namespace std;

char s[1024];

bool vowel(char s)
{
	if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
		return 1;
	return 0;
}

bool rule1(char *s)
{
	int vnum;
	for (int i = 0; i < strlen(s); i++)
		if (vowel(s[i]))
			return 1;
	return 0;
}

bool rule2(char *s)
{
	int vowlnum = 1, csonnum = 1;
	for (int i = 0; i < strlen(s) - 1; i++)
	{
		if (vowel(s[i]) && vowel(s[i + 1]))
		{
			if (s[i] == s[i + 1] && s[i] != 'e' && s[i] != 'o')
				return 0;
			else
				vowlnum++;
		}
		if (!vowel(s[i]) && !vowel(s[i + 1]))
		{
			if (s[i] == s[i + 1])
				return 0;
			else
				csonnum++;
		}
		if (vowlnum >= 3 || csonnum >= 3)
			return 0;
		if ((vowel(s[i]) && !vowel(s[i + 1])) || (!vowel(s[i]) && vowel(s[i + 1])))
			vowlnum = 1, csonnum = 1;
	}
	return 1;
}

int main()
{
	while (~scanf("%s", s), strcmp(s, "end"))
	{
		printf("<%s> is ", s);
		if (rule1(s) && rule2(s))
			printf("acceptable.\n");
		else
			printf("not acceptable.\n");
	}
	return 0;
}

