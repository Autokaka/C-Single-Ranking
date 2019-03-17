#include <iostream>
//#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(n) for (int i = 0; i < (n); i++)

struct node
{
	string a;
	int b;
	int t;
};

bool cmp(node n1, node n2)
{
	if (n1.a == n2.a)
		return n1.b > n2.b;
	return n1.a > n2.a;
}

int main()
{
	//ios::sync_with_stdio(false);
	int n;
	while (~scanf("%d", &n), n)
	{
		node no[n];
		FOR(n)
		{
			cin >> no[i].a >> no[i].b;
			no[i].t = i;
		}
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (no[i].a == no[j].a)
				{
					no[i].b += no[j].b; no[j].b = 0;
					no[i].t += no[j].t; no[j].t = 0;
				}
		FOR(n)
			sort(no, no + n, cmp);
		int max = 0;
		for (int i = 0; i < n; i++)
			if ((no[i].b > no[max].b) || (no[i].b == no[max].b && no[i].t < no[max].t))
					max = i;
		cout << no[max].a << endl;
	}
	return 0;
}

