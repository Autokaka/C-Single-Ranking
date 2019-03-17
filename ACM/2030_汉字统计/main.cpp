#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	getchar();
	while (n--)
	{
		string s;
		getline(cin, s);
		int cnt = 0, len = s.length();
		for (int i = 0; i < len; i += 2)
			if (s[i] < 0 && s[i + 1] < 0)
				cnt++;
		cout << cnt << endl;
	}
	return 0;
}
