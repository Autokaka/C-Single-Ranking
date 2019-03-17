#include <iostream>
#include <map>
#include <set>
using namespace std;

#define FOR(x) for (int i = 0; i < (x); i++)

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		map<string, int> mkbd;
		set<string> winner;
		string name[1024];
		int mark[1024];
		int m;
		cin >> m;
		FOR(m)
		{
			cin >> name[i] >> mark[i];
			mkbd[name[i]] += mark[i];
		}
		int big = mark[0];
		map<string, int>::iterator it;
		for (it = mkbd.begin(); it != mkbd.end(); it++)
		{
			if (big < it->second)
			{
				big = it->second;
				winner.clear();
			}
			if (big == it->second)
				winner.insert(it->first);
		}
		mkbd.clear();
		FOR(m)
		{
			mkbd[name[i]] += mark[i];
			if (winner.count(name[i]) && big <= mkbd[name[i]])
			{
				cout << name[i] << endl;
				break;
			}
		}
	}
	return 0;
}

