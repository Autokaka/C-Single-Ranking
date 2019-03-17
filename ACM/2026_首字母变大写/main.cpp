#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char s[100];
	while(gets(s))
	{
		int len = strlen(s);
		s[0] -= 32;
		for (int i = 1; i < len - 1; i++)
		{
			if (s[i] == ' ' && s[i + 1] >= 'a' && s[i + 1] <= 'z')
				s[i + 1] -= 32;
		}
		cout << s << endl;	
	}
	return 0;
}
