#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(x) for (op[x] = 0; op[x] < 4; op[x]++)

int main()
{
	ios::sync_with_stdio(false);
	int a[5], y , i, op[4];
	for (int i = 0; i < 5; i++)
		cin >> a[i];
	cin >> y;
	int p, q, f = 1;
	FOR(0)
		FOR(1)
			FOR(2)
				FOR(3)
					for (int i = 0; i < 4; i++)
						switch(op[i])
						{
							case 0:
								
								break;
							case 1:
								break;
							case 2:
								break;
							case 3:
								break;
							default:
								break;
						}
	return 0;
}

