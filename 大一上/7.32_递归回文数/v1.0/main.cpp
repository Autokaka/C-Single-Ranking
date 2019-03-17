#include <iostream>
#include<cstring>
using namespace std ; 

bool checkPal( char [] , int ) ;

int main() 
{
	//回文数组
	char str[80]={0} ;
	cout << "年轻的少年哟，你想要判断啥哟？\n" ;
	cin.getline( str , 80 ) ;
	//数组处理
	int process , cnt=0 ;//储存非字母出现的次数 
	char str_temp[80]={0} ;//缓存数组 
	for( process=0 ; process<80 ; process++ )
	{
		if( str[process]=='\0' )
			break ; 
		else 
	    {
	    	if( str[process]>='a'&&str[process]<='z' )
	    	{
	    	    str_temp[process-cnt]=str[process] ;
			} 
			else
			{
				cnt++ ;
			}
		}
	} 
	//检查并作出回应
    cout << "\n你输入的以下信息\n" << str ;
	if( checkPal( str_temp , strlen(str_temp) ) )
		cout << "\n是回文" ; 
	else
	    cout << "\n不是回文" ;
	
	return 0 ;
}

bool checkPal( char str_temp[] , int arraysize )
{
	if( arraysize==0||arraysize==1 )
	    return true ;
	else
	{
		if( str_temp[0]==str_temp[arraysize-1] )
		    return checkPal( str_temp+1 , arraysize-2 ) ;
	}
	return false ;
}
