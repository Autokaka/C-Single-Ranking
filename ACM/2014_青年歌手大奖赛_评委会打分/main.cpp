#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

bool cmp(int &a, int &b)
{
	if (a > b)
	{
		int tmp = a;
		a = b;
		b = tmp;
		return 1;
	}
	return 0;
}

int main()
{
	int size, cnt;
	double sum;
	while (scanf("%d", &size) != EOF)
	{
		if (size <= 2 || size > 100)
			continue;
		int *n = new int [size];
		for (int i = 0; i < size; i++)
			scanf("%d", &n[i]);
		do
		{
			cnt = 0;
			for (int i = 0; i < size - 1; i++)
				cnt += cmp(n[i], n[i+1]);
		} while (cnt != 0);
		sum = 0;
		for (int i = 1; i < size - 1; i++)
			sum += n[i];
		cout << fixed << setprecision(2) << double(sum / (size - 2)) << endl;
		delete [] n;
	}
	return 0;
}
