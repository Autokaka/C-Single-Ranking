#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=500005;
int L,n,m;
int a[maxn];

bool judge(int mid)	//mid���������һ����������Զ���� 
{
    int cnt=1;		//cnt���������һ��Ҫ���Ĵ��� 
    int pos=0;		//pos��������ܵ�ǰ��λ�� 
    for(int i=1;i<=n;i++)
    {
    	if(a[i]-a[pos]<=mid && a[i+1]-a[pos]>mid)
        {
        	pos=i;	//�� һ����������Զ����  a[i]-a[pos] <= mid < a[i+1]-a[pos]
            cnt++;  //�л���ǰλ�ã������Ĵ��� ++  
        }
    }
    if(cnt>m)
        return false;//�������� return false������return true 
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
        for(i=1;i<=n+1;i++)		//minl��������������ڵ�ʯͷ֮�䣨������ʼ��ͽ����㣩�������롣
           {
               if(a[i]-a[i-1]>minl)
                  minl=a[i]-a[i-1];	    
           }
        l=minl;				    //���ִ𰸵���СֵΪ minl 
        r=L;					//���ִ𰸵����ֵΪ L 
        while(l<=r)
        {
            int mid=(l+r)>>1;
			if(judge(mid))		//return true ˵������������˵��mid���� 
			{
				r=mid-1;		//mid���˾�Ҫ�� l~mid�ң�r=mid-1 
				ans=mid;		//������ans 
			}
            else
                l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
