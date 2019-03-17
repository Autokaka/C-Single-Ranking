#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

long long powl(long long a,long long p,long long mod)
{
	long long tmp;
	if(p==0)
	return 1;
	tmp=powl(a,p/2,mod);
	if(p%2!=0)
	return a*tmp%mod*tmp%mod;
	else
	return tmp*tmp%mod;
}  
int main()
{
	ios::sync_with_stdio(false);
	long long p,a,i,t,flag;
	while(cin>>p>>a&&(p||a))
	{
		flag=0;
		for(i=2;i*i<p;i++)
		{
			if(p%i==0)
				flag++;
		}  
		if(flag==0)
		cout<<"no"<<endl;
		else{
			if(a==powl(a,p,p))
			cout<<"yes"<<endl;
			else
			cout<<"no"<<endl;
		} 
	}
	return 0;
}
