#include <iostream>
#include<cstring>
using namespace std ; 

bool checkPal( char [] , int ) ;

int main() 
{
	//��������
	char str[80]={0} ;
	cout << "���������Ӵ������Ҫ�ж�ɶӴ��\n" ;
	cin.getline( str , 80 ) ;
	//���鴦��
	int process , cnt=0 ;//�������ĸ���ֵĴ��� 
	char str_temp[80]={0} ;//�������� 
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
	//��鲢������Ӧ
    cout << "\n�������������Ϣ\n" << str ;
	if( checkPal( str_temp , strlen(str_temp) ) )
		cout << "\n�ǻ���" ; 
	else
	    cout << "\n���ǻ���" ;
	
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
