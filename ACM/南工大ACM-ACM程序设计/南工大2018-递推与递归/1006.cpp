#include <iostream>
using namespace std;

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		int sum = 0, m2;
		for (int m3 = 0; m3 <= n / 3; m3++)
		{
			m2 = (n - 3 * m3) / 2;
			sum += m2 + 1;
		}
		printf("%d\n", sum);
	}
	return 0;
}
