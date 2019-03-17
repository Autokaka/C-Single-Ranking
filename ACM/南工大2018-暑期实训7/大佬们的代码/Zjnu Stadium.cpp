#include <iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 50005
int father[N], dis[N];  
int Find(int x){
    if(x==father[x]) return father[x];
    int t=father[x];
    father[x] = Find(father[x]);
    dis[x]+= dis[t];
    return father[x];
}
bool Union(int x,int y,int m){
    int a=Find(x), b=Find(y);
    if(a==b){
        if(dis[x]+m!=dis[y])
            return false;
        return true;
    }
    father[b] = a;
    dis[b] = dis[x]+m-dis[y];
    return true;
}
int main(){
    int n,m,a,b,x;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<=n;i++){
        	father[i]=i;
        	dis[i]=0;
		}      
        int ans=0;
        for(int i=0; i<m; ++i){
            scanf("%d%d%d",&a,&b,&x);
            if(!Union(a, b, x)){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


