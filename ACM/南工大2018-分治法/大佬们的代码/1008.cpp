#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
double min(double a,double b)
{
	return a<b?a:b;
}
struct node
{
  double x;
  double y;
}no[100005];
int pos[100005];
bool cmpx(node a,node b)
{
  return a.x<b.x;
}
bool cmpy(int a,int b)
{
  return no[a].y<no[b].y;
}
double dis(node a,node b)
{
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double find(int l,int r)
{
     if(l+1==r)
         return dis(no[l],no[r]);
     if(l+2==r)
         return min(dis(no[l],no[r]),min(dis(no[l],no[l+1]),dis(no[l+1],no[r])));
     int mid=(l+r)>>1;
     double ans=min(find(l,mid),find(mid+1,r));
     int i,j,cnt=0;
     for(i=l;i<=r;i++)
     {
         if(no[i].x>=no[mid].x-ans&&no[i].x<=no[mid].x+ans)
            pos[cnt++]=i;
     }
     sort(pos,pos+cnt,cmpy);
     for(i=0;i<cnt;i++)
         for(j=i+1;j<cnt;j++)
         {
             if(no[pos[j]].y-no[pos[i]].y>=ans) 
		     break;
             ans=min(ans,dis(no[pos[i]],no[pos[j]]));
         }
    return ans;
}
int main()
{
    int i,n;
    while(scanf("%d",&n)!=EOF)
    {
      if(!n) break;
      for(i=0;i<n;i++)
         scanf("%lf %lf",&no[i].x,&no[i].y);
      sort(no,no+n,cmpx);
      printf("%.2lf\n",find(0,n-1)/2);
    }
    return 0;
}
