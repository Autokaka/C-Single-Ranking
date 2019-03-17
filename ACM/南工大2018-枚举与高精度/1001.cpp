#include <iostream>
#include <cstring>
using namespace std;

#define L 10240

int main()
{
	char n[L];
	while (~scanf("%s", n))
	{
		int cnt = 0;
		for (int i = 0; i < strlen(n); i++)
			cnt += n[i] - '0';
		if (!cnt)
			break;
		while (cnt >= 10)
		{
			int tmp = 0;
			while (cnt > 0)
			{
				tmp += cnt % 10;
				cnt /= 10;
			}
			cnt = tmp;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
