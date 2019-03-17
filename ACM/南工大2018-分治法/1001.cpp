#include <bits/stdc++.h>
using namespace std;

set<int> a, b;
vector<int> result;

int main()
{
	int n, m;
	while (~scanf("%d%d", &n, &m))
	{
		int tmp;
		while(n--)
		{
			scanf("%d", &tmp);
			a.insert(tmp);
		}
		while (m--)
		{
			scanf("%d", &tmp);
			b.insert(tmp);
		}
		result.resize(a.size() + b.size());
		vector<int>::iterator it;
		it = set_union(a.begin(), a.end(), b.begin(), b.end(), result.begin());
		result.resize(it - result.begin());
		for (it = result.begin(); it != result.end(); it++)
		{
			printf("%d", *it);
			it == result.end() - 1? printf("\n") : printf(" ");
		}
		a.clear();
		b.clear();
		result.clear();
	}
	return 0;
}

