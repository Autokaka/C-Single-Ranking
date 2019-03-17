#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int size;
	while (scanf("%d", &size) != EOF)
	{
		if (size > 100 || size < 0)
			continue;
		int *n = new int [size];
		for (int i = 0; i < size; i++)
			if (scanf("%d", &n[i]) == EOF)
				return 0;
		for (int i = 0; i < size; i++)
		{
			double sum = 0;
			for (int j = 1; j <= n[i]; j++)
				sum += double(pow(-1, j - 1) / j);
			cout << fixed << setprecision(2) << sum << endl;
		}	
	}	
	return 0;
}
