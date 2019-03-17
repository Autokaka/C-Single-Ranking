#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m && n != 0 && m != 0)
	{
		for (int i = sqrt(2 * m); i >= 1; i--)
		{
			int l = (2 * m / i + 1 - i) / 2;
			if ((2 * l + i - 1) * i / 2 == m)
				cout << "[" << l << "," << l + i - 1 << "]" << endl;
		}
		cout << endl;
	}
	return 0;
}
