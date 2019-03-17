#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	char n[1024];
	while(gets(n))
	{
		vector<int> v;
		n[strlen(n)] = '5';
		for (int i = 0; i < strlen(n); i++)
		{
			int tmp = 0, cnt = 1;
			if (n[i] == '5')
			{
				int flag = 0;
				for (int j = i - 1; j >= 0 && n[j] != '5'; j--)
				{
					tmp += (n[j] - '0') * cnt;
					cnt *= 10;
					flag = 1;
				}
				if (flag)
					v.push_back(tmp);
			}
		}
		sort(v.begin(), v.end());
		vector<int>::iterator it;
		for (it = v.begin(); it != v.end(); it++)
		{
			printf("%d", *it);
		it == v.end() - 1? printf("\n") : printf(" ");
		}	
		memset(n, '0', sizeof(n)/sizeof(char));
	}
	return 0;
}
