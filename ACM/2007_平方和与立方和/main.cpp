#include <iostream>
#include <stdio.h>
using namespace std;

int main() 
{
	int min, max, even, odd, tmp;
	while (scanf("%d %d", &min, &max) != EOF)
	{
		(min > max)? tmp = max, max = min, min = tmp : 0;
		even = 0, odd = 0;
		for (int i = min; i <= max; i++)
			(i % 2 != 0)? odd += i * i * i : even += i * i;
		cout << even << " " << odd << endl;
	}
	return 0;
}
