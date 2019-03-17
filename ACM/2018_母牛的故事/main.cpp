#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n <= 0)
			continue;
		int cow[3] = {0, 0, 1};
		for (int i = 1; i <= n - 1; i++)
		{
			int tmp[3] = {cow[2], cow[0], cow[1] + cow[2]};
			for (int i = 0; i <= 2; i++)
				cow[i] = tmp[i];
		}
		cout << cow[0] + cow[1] + cow[2] << endl;
	}
	return 0;
}
