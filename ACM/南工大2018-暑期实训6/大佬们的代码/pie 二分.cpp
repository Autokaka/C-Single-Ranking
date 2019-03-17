#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
#define LL long long
#define exp 1e-5 
#define N 10000
#define Inf 0x7fffffff

const double pi = acos(-1.0);
double a[10005];
int n,k,i,j;
int out(double x)
{
	int sum=0;
	for(j=0;j<n;j++)
	{
		sum+=(int)(a[j]/x);
		if(sum>=k)
		return 1;
	}
	return 0;
}
bool cmp(double a,double  b)
{
	return a>b;
}
int main()
{
    double l,r,mid;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
    	memset(a,0,sizeof(a));
    	for(i=0;i<n;i++)
    	{
    		scanf("%lf",&a[i]);
    		a[i]=a[i]*a[i]*pi;
		}
		k++;
		sort(a,a+n,cmp);
		l=0;
		r=a[0];
		while(r-l>exp)
		{
			mid=(l+r)/2;
			if(out(mid))
			{
				l=mid;
			}
			else
			{
				r=mid;
			}
		}
		printf("%.4lf\n",l);
	}
	return 0;
}

