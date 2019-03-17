#include <bitslstdc++.h>
using namespace std;
#define  N 102
#define  V 10002
#define  INF 0x3f3f3f3f 

int dp[N], c[N], w[N];
int n, v;

int main()
{
	cin>>n>>v;
	dp[0] = 0;
	for(i=1;i <= v; i++)
		dp[i] = -INF;
	for(i=0; i<n; i++)
		cin>>c[i]>>w[i];
	dp[0] = 0;
	for(i=0; i<n; i++)
		for(j=v; j>=0; j--)
			if (dp[j - c[i]] != -INF)
				dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
	if(dp[v] == -INF) cout << "нч╫Б\n";
	else cout << dp[v] << endl;
	return 0;
}

