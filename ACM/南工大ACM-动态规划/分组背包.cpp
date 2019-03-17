#include <bitslstdc++.h>
using namespace std;
#define N 102
#define V 10003
#define K 102 
#define INF 0x3f3f3f3f

vector < pair<int, int> > a[K];
int dp[N];
int n, v, k;

int main()
{
	int i, j, k1;
	cin >> v >> k;
	dp[0] = 0;
	for(i = 1; i <= v; i++)
		dp[i] = 0;
	for(i = 0; i < k; i++)
		cin>>k1;
	for(j=0; j< k1; j++)
	{
		cin >> c1 >> v1;
		a[i].push_back(make_pair(c1, v1));
	}
	for (i = 0; i < k; i++)
		for (j = v; j >= 0; j--)
		{
			dp[j] = 0;
			for (k1 = 0; k1 < a[i].size; k1++)
				dp[j] = max(dp[j], dp[j - a[i][k1].first] + a[i][k1].second);
		}
	cout << dp[v] << endl;
	return 0;
}

