#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std ;

int main()
{
	//�������� 
	const char *article[5]={"The","A","One","Some","Any"} ;
	const char *noun[5]={"boy","girl","dog","town","car"} ;
	const char *verb[5]={"drove","jumped","ran","walked","skipped"} ;
	const char *preposition[5]={"to","from","over","under","on"} ;
	//�������
	srand( time(0) ) ;
	int cnt ;
	for( cnt=1 ; cnt<=20 ; cnt++ )
	{
		//article
		cout << article[rand()%5] << " " ;
		//noun
		cout << noun[rand()%5] << " " ;
		//verb
		cout << verb[rand()%5] << " " ;
		//preposition
		cout << preposition[rand()%5] << " " ;
		//article
		cout << article[rand()%5] << " " ;
		//noun
		cout << noun[rand()%5] << " .\n" ;
	} 
	
	return 0;
}
