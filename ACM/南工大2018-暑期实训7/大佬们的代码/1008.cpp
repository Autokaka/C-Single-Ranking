#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
#define N 200010 
int a[N],sum[N];

map<string,int>m;

int find(int t){
    if(t!=a[t])
        a[t]=find(a[t]);
    return a[t];
}
void Union(int x,int y){
	x=find(x);
    y=find(y);
    if(x==y){
        cout<<sum[x]<<endl;  			//如果两人已经是朋友了，    
        return;					  		//直接输出任意一方的朋友总数即可 
    }else{
        cout<<sum[x]+sum[y]<<endl;
	    a[x]=y;							//如果两人不是朋友，输出两人朋友数之和，
	    sum[y]+=sum[x];					//然后再使两人成为朋友，更新数据。
	    sum[x]+=sum[y];
	}
}
int main()
{
    int t;
    while(cin>>t){
		while(t--){
	        char c1[30],c2[30];
	        int n;
	        cin>>n;
	        for(int i=1;i<=2*n;i++){	//初始化：每个人只和自己是朋友，朋友总数为 1 
	            a[i]=i;
	            sum[i]=1;
	        }
	        int cnt=1;					 //人名->编号 ，每有一个新人出现时 +1 
	        m.clear();
	        while(n--){
	            cin>>c1>>c2;
	            if(!m[c1])
	                m[c1]=cnt++;
	            if(!m[c2])
	                m[c2]=cnt++; 
	            Union(m[c1],m[c2]);
	        }
	    }
	}
	return 0;
}
