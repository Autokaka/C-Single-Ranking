#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n;
	char s[50];
	while(cin >> n)
	{
		if (n <= 0 || n > 50)
			break;
		getchar();
		while(n--)
		{
			gets(s);
			if (!((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z') || s[0] == '_'))
			{
				cout << "no" << endl;
				continue;
			}
			int flag = 0;
			for (int j = 1; s[j] != '\0'; j++)
			{
				if (!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9') || s[j] == '_'))
				{
					flag = 1;
					break;
				}
			}
			(flag == 0)? cout << "yes" : cout << "no";
			cout << endl; 
		}
	}
	return 0;
}
