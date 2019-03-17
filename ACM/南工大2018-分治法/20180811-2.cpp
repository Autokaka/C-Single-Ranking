#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for (int (x) = (y); (x) < (z); (x)++)
#define N 10

int main()
{
	int num[N] = {1, 2, 3, 4, 4, 4, 5, 6, 7, 9}, left = 0, right = N, mid;
	int n;
	printf("#binary_search(num, num + N, n);# Please entry n:\n");//搜索元素 
	scanf("%d", &n);
	if (binary_search(num, num + N, n))
		printf("Yes\n");
	else
		printf("No\n");
	printf("#lower_bound(num, num + N, n);# Please entry n:\n");//返回等于n的指针的下界 
	scanf("%d", &n);
	printf("%d\n", *lower_bound(num, num + N, n));
	printf("#upper_bound(num, num + N, n);# Please entry n:\n");//返回等于n的指针的上界 
	scanf("%d", &n);
	printf("%d\n", *upper_bound(num, num + N, n));
	pair<int, int> pa;
	printf("#equal_range(num, num + N, n);# Please entry n:\n");//返回值等于n的[i, j)的区间
	scanf("%d", &n);
	printf("%d\n", equal_range(num, num + N, n));
	return 0;
}

