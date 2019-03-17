#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		if(n % 3 == 0)
			printf("Cici\n");
		else
			printf("Kiki\n");
	} 
	return 0;
}

