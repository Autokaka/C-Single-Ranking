#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	long long n,p;
	int count;
	while(cin>>n){
		count=0;
		p=1;
		while(p<n){
			count++;
			if(count%2==0)
			    p*=2;
			else
			    p*=9;
		}
		if(count%2==0)
		    cout<<"Ollie wins."<<endl;
		else
		    cout<<"Stan wins."<<endl;
	}
	return 0;
}

