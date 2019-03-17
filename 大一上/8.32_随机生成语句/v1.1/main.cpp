#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std ;

int main()
{
	//生成数组 
	const char *article_a[5]={" the"," a"," one"," some"," any"} ;
	const char *article_A[5]={" The"," A"," One"," Some"," Any"} ;
	const char *noun[5]={" boy"," girl"," dog"," town"," car"} ;
	const char *verb[5]={" drove"," jumped"," ran"," walked"," skipped"} ;
	const char *preposition[5]={" to"," from"," over"," under"," on"} ;
	//生成语句
	srand( time(0) ) ;
	int n ;
	for( n=1 ; n<=20 ; n++ )
	{
		char sentence[80]={'\0'} ; 
		int cnt ;
		for( cnt=1 ; cnt<=6 ; cnt++ )
		{
			int random=rand()%5 ;
			switch( cnt )
			{
				case 1 :
					strcat( sentence , article_A[random] ) ;
					break ;
				case 2 :
					strcat( sentence , noun[random] ) ;
					break ;
				case 3 :
					strcat( sentence , verb[random] ) ;
					break ;
				case 4 :
					strcat( sentence , preposition[random] ) ;
					break ;
				case 5 :
					strcat( sentence , article_a[random] ) ;
					break ;
				case 6 :
					strcat( sentence , noun[random] ) ;
					break ;
			}
		}
		cout << sentence << "." << endl ;
	}
	return 0;
}
