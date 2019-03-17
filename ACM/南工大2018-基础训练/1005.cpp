#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<string, int> s;
	int n;
	while(cin >> n, n)
	{
		string name;
		while (n--)
		{
			cin >> name;
			s[name]++;
		}
		map<string, int>::iterator it, m = s.begin();
		for (it = s.begin(); it != s.end(); it++)
			if (it->second > m->second)
				m = it;
		cout << m->first << endl;
		s.clear();
	}
	return 0;
}

