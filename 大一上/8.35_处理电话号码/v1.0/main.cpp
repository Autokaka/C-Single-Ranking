#include <iostream>
#include <cstring>
using namespace std ;

void extract( char * ) ;
void assemble( char * ) ;

int main()
{
	char phone_number[80]="(555) 555-5555" ;
	char phone_number_backup[80]={'\0'} ;
	strcpy( phone_number_backup , phone_number ) ;
	cout << "原电话号码是：\n" 
	     << phone_number << endl 
		 << endl 
		 << "分开写是：\n" ;
	extract( phone_number ) ;
	cout << endl 
	     << "去标点以后：\n" ;
	assemble( phone_number_backup ) ;
	
	return 0;
}

void extract( char *phone_number )
{
	char *tokenPtr=strtok( phone_number , "()" ) ;
	cout << tokenPtr << endl ;
	tokenPtr=strtok( phone_number+6 , "-" ) ;
	cout << tokenPtr << endl ;
	cout << strtok( NULL , "" ) << endl ;
}

void assemble( char *phone_number )
{
	cout << strtok( phone_number+6 , "-" ) ;
	cout << strtok( NULL , "" ) << endl ;
}
