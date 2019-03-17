#include <iostream>
using namespace std;

int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		for (int i = n - 1; i >= 1; i--)
			n += i;
		printf("%d\n\n", n);
	}
	return 0;
}
