#include <iostream>
#include<cstring>
using namespace std ; 

void stringReverse( char [] , int , int ) ;

int main() 
{
	//ԭ��������
	char str[80]={0} ; 
	cout << "���������Ӵ������Ҫ�ĵ�ɶ��Ӵ��\n" ;
	cin.getline( str , 80 ) ;
	//�����û�������
	char str_temp[80]={0} ;
	int copy ;
	for( copy=0 ; copy<=strlen(str)-1 ; copy++ )
	{
		str_temp[copy]=str[copy] ;
	}
	//�ĵ�
	int begin=0 ;
	do
	{
		cout << "\n��������Ҫ����һλ��ʼ�ĵ���" ;
		cin >> begin ; 
 		stringReverse( str_temp , strlen(str_temp) , begin ) ;
    	if( begin<=strlen(str) )
    	{
    		//����ǰ 
		    cout << "\n|______����ǰ______|\n" << str << endl ;
		    //����� 
		    cout << "\n|______�����______|\n" << str_temp << endl ;
		}
		else
			cout << "\n��������Ϲ�㣬����������\n" ;	
	}while( begin>strlen(str) ) ;
	
	return 0 ;
}

void stringReverse( char str[] , int arraysize , int begin )
{
    if( begin>arraysize )
        str[0]=str[0] ;
    else
    {
    	arraysize-=begin-1 ;//ȥ��֮ǰ�� 
		str+=begin-1 ;//ָ�����ڵ� 
		int temp=str[arraysize-1] ;
		str[arraysize-1]=str[0] ;
		str[0]=temp ;
		return stringReverse( str+1 , arraysize-2 , 1 ) ;
	}

}
