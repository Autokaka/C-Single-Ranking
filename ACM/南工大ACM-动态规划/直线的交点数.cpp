#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define INF 0x7fffffff
#define N 22
int dp[N][N*(N-1)/2];

int main()
{
	int n, i, j, r;
	cin >> n;
	rep(i, 0, n) dp[i][0] = 1;
	rep(i, 0, n)
		rep(r, 0, i)//���¼�ֱ��ƽ�е�����Ϊi - r 
			rep(j, 0, r*(r-1)/2)//��r��ֱ�����п��ܽ������� 
				if(dp[r][j])
					dp[i][r*(i-r)+j] = 1; 
	rep(i, 0, n*(n-1)/2) if (dp[n][i]) cout << i << " ";
	cout << endl; 
	return 0;
}

