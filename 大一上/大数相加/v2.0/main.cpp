#include <iostream>
using namespace std ; 

void sumup( int [][ArraySize_max] , int , int ) ;
int cnt=0 ;//��¼��λ 

void cin_number( int [][ArraySize_max] , int , int ) ;

int main() 
{
	//Ҫ�Ӽ������� 
	int how_many ; 
	cout << "��Ҫ�Ӽ���������" ;
	cin >> how_many ; 
	//��������������λ,���ҳ������λ 
	int ArraySize[how_many+1]={0} ; 
	int search , ArraySize_max ;
    for ( search=1 ; search<=how_many ; search++ )
	{
		cout << "�� " << search << " �����ֵ���λ��" ;
		cin >> ArraySize[search] ;
		ArraySize_max=ArraySize[search] ;
		if( search-1>=1 ) 
		{
		    if( ArraySize[search]<ArraySize[search-1] )
		    {
		    	ArraySize_max=ArraySize[search-1] ;
			}
		}
	} 
	//�����ͱ������Լ� �Ӻ�(��0��) ��ά���� 
    int numbers[how_many+1][ArraySize_max]={0} ;
	//����
	cin_number( numbers , how_many , ArraySize_max ) ; 
	//��� 
    sumup( numbers , how_many , ArraySize_max ) ;
	//������
	int display ;
	if( cnt!=0 )
        cout << cnt ; 
        
    for( display=0 ; display<=ArraySize_max-1 ; display++ )
	    cout << numbers[0][display] ;
	
	return 0 ;
}
//����ÿ������ 
void cin_number( int numbers[][ArraySize_max] , int how_many , int ArraySize_max )
{
	cout << "���������ÿ����λ��\n" ; 
	int cin_y ;
	for( cin_y=1 ; cin_y<=how_many ; cin_y++ )
	{
		int cin_x ;
		for( cin_x ; cin_x<=ArraySize_max-1 ; cin_x++ )
		{
			cin >> numbers[cin_y][cin_x] ;
		}
	}
}
//ÿ��������͵���0���������� 
void sumup( int numbers[][ArraySize_max] , int how_many , int ArraySize_max )
{
    int sum_x ;
    for( sum_x=ArraySize_max-1 ; sum_x>=0 ; sum_x-- )
    {
    	int sum_y ;
    	for( sum_y=1 ; sum_y<=how_many ; sum_y++ )
    	{
    		cnt+=numbers[sum_y][sum_x] ;
    		numbers[0][sum_x]=cnt%10 ;
			cnt/=10 ;
		}
	}
}
