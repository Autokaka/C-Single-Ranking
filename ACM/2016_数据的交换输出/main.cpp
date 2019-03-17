#include <iostream>
#include <stdio.h>
using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int size;
	while (scanf("%d", &size) != EOF)
	{
		if (size <= 0 || size >= 100)
			continue;
		int *n = new int [size];
		for (int i = 0; i < size; i++)
			scanf("%d", &n[i]);
		int *min = n;
		for (int i = 1; i < size; i++)
			(*min > n[i])? min = n + i : 0;
		swap(*min, n[0]);
		for (int i = 0; i < size; i++)
			(i == size - 1)? cout << n[i] << endl : cout << n[i] << " ";
		delete [] n;
	}
	return 0;
}
