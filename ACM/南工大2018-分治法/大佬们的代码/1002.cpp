#include <iostream>
#include <algorithm>
using namespace std;
int a[100010];

int search(int left,int right,int key)
{
	int mid,ans=0;
	while(left<=right)
	{
		mid=(left+right)/2;
	if(a[mid]<=key)
	{
		ans+=mid-left+1;
		left=mid+1;
	}
	else
	{
		right = mid-1;
	}
    }
    return ans;
}
	

int main()
{
	long long int ret;
	int t,i;
	cin>>t;
	while(t--)
	{
		ret=0;
		int n,k;
		cin>>n>>k;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		for(i=0;i<n;i++)
		{
			ret+=search(i+1,n-1,k+a[i]);
		}
		cout<<ret<<endl;
	}
	return 0;
}
