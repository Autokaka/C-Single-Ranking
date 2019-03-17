#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=500005;
int L,n,m;
int a[maxn];

bool judge(int mid)	//mid存的是青蛙一次能跳的最远距离 
{
    int cnt=1;		//cnt存的是青蛙一共要跳的次数 
    int pos=0;		//pos存的是青蛙当前的位置 
    for(int i=1;i<=n;i++)
    {
    	if(a[i]-a[pos]<=mid && a[i+1]-a[pos]>mid)
        {
        	pos=i;	//当 一次能跳的最远距离  a[i]-a[pos] <= mid < a[i+1]-a[pos]
            cnt++;  //切换当前位置，且跳的次数 ++  
        }
    }
    if(cnt>m)
        return false;//次数超了 return false，否则return true 
    else
        return true;
}
int main()
{
    int l,r,minl,i,ans;
    while(~scanf("%d%d%d",&L,&n,&m))
    {
        a[0]=0;
        a[n+1]=L;
        minl=0;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(i=1;i<=n+1;i++)		//minl保存的是两个相邻的石头之间（包括起始点和结束点）的最大距离。
           {
               if(a[i]-a[i-1]>minl)
                  minl=a[i]-a[i-1];	    
           }
        l=minl;				    //二分答案的最小值为 minl 
        r=L;					//二分答案的最大值为 L 
        while(l<=r)
        {
            int mid=(l+r)>>1;
			if(judge(mid))		//return true 说明次数不够，说明mid大了 
			{
				r=mid-1;		//mid大了就要往 l~mid找，r=mid-1 
				ans=mid;		//保留答案ans 
			}
            else
                l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
