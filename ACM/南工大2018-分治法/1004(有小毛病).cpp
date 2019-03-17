#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define X 100100
#define MIN -1000
#define MAX 1000

int num[X];

struct Ret
{
	int max, left, right;
};

Ret subSeq(int n[], int l, int r)
{
	if (l == r)
	{
		Ret ret;
		ret.max = n[l];
		ret.left = l;
		ret.right = r;
		return ret;
	}
	int mid = (l + r) / 2;
	Ret leftpart, rightpart;
	leftpart = subSeq(n, l, mid);
	rightpart = subSeq(n, mid + 1, r);
	int acum = 0, i;
	Ret midpart;
	midpart.max = n[mid];
	for (i = mid; i >= 0; i--)
	{
		acum += n[i];
		if (acum > midpart.max)
		{
			midpart.max = acum;
			midpart.left = i;
		}
	}
	for (i = mid + 1; i <= r; i++)
	{
		acum += n[i];
		if (acum > midpart.max)
		{
			midpart.max = acum; 
			midpart.right = i;
		}
	}
	if (midpart.max >= leftpart.max && midpart.max >= rightpart.max)
		return midpart;
	if (leftpart.max >= midpart.max && leftpart.max >= rightpart.max)
		return leftpart;
	if (rightpart.max >= leftpart.max && rightpart.max >= midpart.max)
		return rightpart;
}

int main()
{
	int T, N, left, right;
	Ret res;
	cin >> T;
	rep(rnd, 0, T)
	{
		cin >> N;
		rep(i, 0, N)
			cin >> num[i];
		left = 0;
		right = N - 1;
		res = subSeq(num, left, right);
		cout << "Case " << rnd + 1 << ":" << endl
			 << res.max << " " << res.left + 1 << " " << res.right + 1 << endl;
		if (rnd != T - 1)
			cout << endl;
	}
	return 0;
}

