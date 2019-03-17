#include <iostream>
using namespace std;

int main()
{
	int d;
	while (cin >> d)
	{
		if (d <= 1 || d >= 30)
			continue;
		int sum =1;
		for (int i = 1; i <= d - 1; i++)
			sum = (sum + 1) * 2;
		cout << sum << endl;
	}
	return 0;
}
