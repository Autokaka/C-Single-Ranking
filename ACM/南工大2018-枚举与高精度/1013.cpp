#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double n1, n2;
	int a, b, c;
	while (cin >> n1 >> n2, n1 || n2)
	{
		a = 1;
		b = -a * n1;
		c = a * n2;
		if (b * b - 4 * a * c < 0)
			cout << "No\n";
		else
		{
			if (double((-b + sqrt(b * b - 4 * a * c)) / (2 * a)) == int((-b + sqrt(b * b - 4 * a * c)) / (2 * a)) && double((-b - sqrt(b * b - 4 * a * c)) / (2 * a)) == int((-b - sqrt(b * b - 4 * a * c)) / (2 * a)))
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
	return 0;
}

