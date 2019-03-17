#include <iostream>
#include<cstring>
using namespace std ; 

void stringReverse( char [] , int , int ) ;

int main() 
{
	//原回文数组
	char str[80]={0} ; 
	cout << "年轻的少年哟，你想要鼓捣啥子哟？\n" ;
	cin.getline( str , 80 ) ;
	//处理用缓存数组
	char str_temp[80]={0} ;
	int copy ;
	for( copy=0 ; copy<=strlen(str)-1 ; copy++ )
	{
		str_temp[copy]=str[copy] ;
	}
	//鼓捣
	int begin=0 ;
	do
	{
		cout << "\n告诉我你要从哪一位开始鼓捣：" ;
		cin >> begin ; 
 		stringReverse( str_temp , strlen(str_temp) , begin ) ;
    	if( begin<=strlen(str) )
    	{
    		//处理前 
		    cout << "\n|______处理前______|\n" << str << endl ;
		    //处理后 
		    cout << "\n|______处理后______|\n" << str_temp << endl ;
		}
		else
			cout << "\n你这是在瞎搞，请重新输入\n" ;	
	}while( begin>strlen(str) ) ;
	
	return 0 ;
}

void stringReverse( char str[] , int arraysize , int begin )
{
    if( begin>arraysize )
        str[0]=str[0] ;
    else
    {
    	arraysize-=begin-1 ;//去掉之前的 
		str+=begin-1 ;//指向现在的 
		int temp=str[arraysize-1] ;
		str[arraysize-1]=str[0] ;
		str[0]=temp ;
		return stringReverse( str+1 , arraysize-2 , 1 ) ;
	}

}
