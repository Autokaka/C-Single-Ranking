#include <iostream>
using namespace std;
//ì³²¨À­ÇÐÊý 
int main()
{
	int y1 = 1, y2 = 0;
	int f[30] = {0};
	f[1] = 1;
	for (int i = 2; i < 20; i++)
	{
		int tmp = y2;
		y2 = y1;
		y1 += tmp;
		f[i] = y1 + y2;
	}
	int m, n;
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d", &n);
		printf("%d\n", f[n]);
	}
	return 0;
}
