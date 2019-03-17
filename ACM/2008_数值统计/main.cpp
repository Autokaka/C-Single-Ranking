#include <iostream>
#include <stdio.h>
using namespace std;
 
int main()
{
	int size, minus, zero, plus;
	double n;
	while (scanf("%d", &size) != EOF)
	{
		minus = 0, zero = 0, plus = 0;
		if (size <= 0 || size >= 100)
			continue;
		for (int i = 1; i <= size; i++)
		{
			scanf("%lf", &n);
			if (n < 0)
				minus++;
			if (n == 0)
				zero++;
			if (n > 0)
				plus++;
		}
		cout << minus << " " << zero << " " << plus << endl;
	}
	return 0;
}
