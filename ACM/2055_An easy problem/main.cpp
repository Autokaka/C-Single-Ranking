#include <iostream>
using namespace std;

int main()
{
	int n, y;
	char x;
	cin >> n;
	while (n--)
	{
		cin >> x >> y;
		if (x >= 'a' && x <= 'z')
			cout << -int(x - 96) + y << endl;
		if (x >= 'A' && x <= 'Z')
			cout << int(x - 64) + y << endl;
	}
	return 0;
}
