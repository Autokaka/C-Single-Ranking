#include <iostream>
using namespace std ; 

int main()
{
	const int ArraySize=10 ;
	int storage[ArraySize+1]={1,3,5,7,9,11,13,15,17,19,21} ;
	
	int i=0 ;
	for ( i ; i<=ArraySize ; i++ )
	{
		cout << storage[i] << " " ;
	}
	
	cout<<"\nKey:" ;
	int key ;
	cin>> key ;
	
	int low=0 , high=ArraySize , mid=(low+high)/2 ; 
	while (storage[mid]!=key)
	{
		mid=(low+high)/2 ;
		if (storage[mid]>key)
		{
			high=mid-1 ;
		}
		else
		{
			low=mid+1 ;
		}	
	}
	if (storage[mid]==key)
	{
		cout << "数组的第 " << mid+1 << " 个数是你要找的那个数" ;
	}
	return 0;
}
