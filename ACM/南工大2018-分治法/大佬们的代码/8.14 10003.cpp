#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
#define FOR(i,n) for(int i=1;i<=n;i++)



int Search(int *a,int Left,int Right,int num)
{
if(Left>=Right) return 0;
	
	int Mid=(Left+Right)/2;
	if(a[Left]==num || a[Right]==num) return 1;
	
	if(a[Mid]<num) return Search(a,Mid+1,Right,num);
	else return Search(a,Left,Mid,num);
}
int main()
{
 ios::sync_with_stdio(false);

int A,B,C;
int a[550];
int b[550];
int c[550];
int d[250050];
int i,j,k;
int S;
int Num;
int CUNT=0;
while(cin>>A>>B>>C)
{
	for(i=1;i<=A;i++) cin>>a[i];
	for(i=1;i<=B;i++) cin>>b[i];
	for(i=1;i<=C;i++) cin>>c[i];
	
	int T=0;
	for(i=1;i<=A;i++)
	{
		for(j=1;j<=B;j++)
		{
			d[++T]=a[i]+b[j];
		}
	}
		sort(d+1,d+A*B+1);
		cin>>S;
		
	cout<<"Case "<<++CUNT<<":\n";

	for(k=1;k<=S;k++)
	{
		
			cin>>Num;
			int flag=0;
			
			for(i=1;i<=C;i++)
			{
				if(Search(d,1,A*B,Num-c[i])) 
				{
					flag++;
					break;
				}
			
			}
			if(flag) cout<<"YES";
			else cout<<"NO";
			cout<<endl;
	}
}
 return 0;
}

