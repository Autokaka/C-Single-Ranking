#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(x) for(int i = 0; i < (x); i++)

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m), n + m)
    {
        int *a = new int [n];
        int *b = new int [m];
        int *flag = new int [n];
        FOR(n)
        	flag[i] = 0;
        FOR(n)
        	scanf("%d", &a[i]);
        sort(a, a + n);
        FOR(m)
        	scanf("%d", &b[i]);
        for (int i = 0; i < n; i++)
        	for (int j = 0; j < m; j++)
        		if (a[i] == b[j])
        			flag[i] = 1;
        int cnt = 0;
		FOR(n)
        	if (flag[i])
        		continue;
        	else
        	{
        		printf("%d ", a[i]);
        		cnt++;
			}
        cnt == 0? printf("NULL\n") : printf("\n");
        delete []a;
        delete []b;
        delete []flag;
    }
    return 0;
}
