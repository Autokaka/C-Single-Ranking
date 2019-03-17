#include <iostream>
#include <cstring>
using namespace std;

char s[10010];

int main()
{
	int mod, sum;
	while (cin >> s >> mod)
	{
		sum = 0;
		for (int i = 0; i < strlen(s); i++)
			sum = (10 * sum + (s[i] - '0') % mod) % mod;
		cout << sum << endl;
	}
	return 0;
}

