#include <stdio.h>
#include <iomanip>
using namespace std;

int main()
{
	int n, m;
	char s[100];
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &m);
		double ci, si, flag =0, sumc = 0, sums = 0;	
		while (m--)
		{	
			scanf ("%*s%lf%lf", &ci, &si);
			if (si < 60)
				flag = 1;
			sumc += ci;
			sums += ci * si;
		}
		if (flag == 1)
			printf("Sorry!\n");
		else
			printf("%.2lf\n", sums / sumc);
		if(n)
			printf("\n");
	}
	return 0;
}
