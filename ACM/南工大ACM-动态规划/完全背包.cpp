#include <bitslstdc++.h>
using namespace std;
#define  N 102
#define  V 10002
#define  INF 0x3f3f3f3f 

int dp[N][V], c[N], w[N];
int n, v;

int main()
{
	cin>>n>>v;
	dp[0] = 0;
	for(i=1;i <= v; i++)
		dp[i] = 0;
	for(i=0; i<n; i++)
		cin>>c[i]>>w[i];
	dp[0] = 0;
	for(i=0; i<n; i++)
		for(j=0; j<=v; j++)
		{
			dp[i][j] = dp[i][j - 1];
			for (k = 1; i - k * c[i] <= v; k++)
			{
				if (i - k * c[i] >= 0 && dp[i][j] < dp[i - k * c[i]][j])
			}
		}
	if(dp[v] == -INF) cout << "нч╫Б";
	else cout << dp[v];
	cout << endl;
	return 0;
}

