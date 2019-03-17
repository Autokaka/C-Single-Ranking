#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int begin, size;
	double sum, doublebegin;
	while (scanf("%d %d", &begin, &size) != EOF)
	{
		doublebegin = sum = begin;
		if ((begin <= 0 || begin >= 10000) || (size <= 0 || size >= 10000))
			continue;
		for (int i = 1; i < size; i++)
		{
			doublebegin = sqrt(doublebegin);
			sum += doublebegin;
		}
		cout << fixed << setprecision(2) << sum << endl;
	}
	return 0;
}
