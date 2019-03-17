#include <iostream>
using namespace std;

int main()
{
	int b10;
	while(cin >> b10)
	{
		int b2 = 0;
		for (int i = 1; b10 != 0; i *= 10)
		{
			b2 += b10 % 2 * i;
			b10 /= 2;
		}
		cout << b2 << endl;
	}
	return 0;
}
