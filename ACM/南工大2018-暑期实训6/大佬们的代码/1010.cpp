#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#define LL long long
#define N 10005
#define eps 1e-12
#define INF -0x3f3f3f3f
using namespace std;
struct node{
	int a,b,c;// (0 ¡Ü a ¡Ü 100), b (|b| ¡Ü 5000), c (|c| ¡Ü 5000)
}coe[N];
int n;//(n ¡Ü 10000)
double ff(double x){
	double m=coe[0].a*x*x+coe[0].b*x+coe[0].c;
	for(int i=1;i<n;i++)
		m=max(m,coe[i].a*x*x+coe[i].b*x+coe[i].c);
	return m;
}
int main(){
	ios::sync_with_stdio(false);
	double low,up,m1,m2;
	int i;
	int t;//(T < 100)
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d %d %d",&coe[i].a,&coe[i].b,&coe[i].c);
		low=0;up=1000;
		while(up-low>=eps){
			m1=low+(up-low)/3;
			m2=up-(up-low)/3;
			if(ff(m1)<=ff(m2))
				up=m2;
			else
				low=m1;
		}
		printf("%.4lf\n",ff((m1+m2)/2));
	}
	return 0;
}

