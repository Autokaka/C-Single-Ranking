#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a = 2, m;
		scanf("%d", &m);
		m -= 1;
		while (m--)
			a += 6 * (m + 1);
		printf("%d\n", a);
	}
	return 0;
}
