#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m, num;
	while(~scanf("%d%d", &n, &m))
	{
		vector<int> v;
		while (n--)
		{
			scanf("%d", &num);
			v.push_back(num);
		}
		sort(v.begin(), v.end(), greater<int>());
		vector<int>::iterator it;
		for (it = v.begin(); it != v.begin() + m; it++)
		{
			printf("%d", *it);
			it == v.begin() + m - 1? printf("\n") : printf(" ");
		}
	}
	return 0;
}
