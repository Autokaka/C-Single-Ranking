#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a = 1, b = 3, m;
		cin >> m;
		m -= 2;
		while (m--)
		{
			int tmp = b;
			b += 2 * a;
			a = tmp;
		}
		cout << b << endl;
	}
	return 0;
}
