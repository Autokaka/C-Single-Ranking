#include <iostream>
#include <cstring>
using namespace std ;

//������ 
void quickSort( int * , int , int ) ;

//�������� 
int partition( int * , int , int ) ; 
int r2l , l2r ;

//�������� 
void swap( int * , int * ) ;

//������ 
int main()
{
	//��������
	cout << "����Ҫ�Ŷ��ٸ�����\n" ;
	int arraysize=0 ;
	cin >> arraysize ;
	int storage[arraysize]={0} ;
	cout << "��Ҫ������Щ����\n" ;
	int fill ;
	for( fill=0 ; fill<arraysize ; fill++ )
	    cin >> storage[fill] ;
	//������βԪ�ر�� 
	int begin=0 , end=arraysize-1 ;
	//���� 
	quickSort( storage , begin , end ) ;
	//������
	int display ;
	for( display=0 ; display<arraysize ; display++ )
	    cout << storage[display] << " " ; 
	
	return 0;
}


//�������� 
void swap( int *a , int *b )
{
	int temp=*a ;
	*a=*b ;
	*b=temp ;
}

//��������_���ؽ���ֵ 
int partition( int *storage , int begin , int end )
{
	
	//���������Ҹ�С 
    for( r2l=end ; r2l>=begin ; r2l-- )
    {
    	if( *(storage+r2l) < *(storage+begin) )
    	{
    		swap( (storage+begin) , (storage+r2l) ) ;
    		break ;
		}
		if( r2l==begin )
		    return r2l ;
	}
	    
	
	//���������Ҹ��� 
	for( l2r=begin ; l2r<=r2l ; l2r++ )
	{
		if( *(storage+l2r)>*(storage+r2l) )
		{
		    swap( (storage+l2r) , (storage+r2l) ) ;
			break ;
		}
		if( l2r==r2l )
		    return l2r ;
	}
	if( l2r!=r2l )
	    partition( storage , l2r , r2l ) ;
}

//������ 
void quickSort( int *storage , int begin , int end )
{
    if ( end-begin>=1 )//���䳤��>0 
    {
    	int cutline=partition( storage , begin , end ) ;//Ѱ�ҽ��� 
    	if( cutline==end||cutline==begin )//cutline���߽��� 
    	{
    		if( cutline==end )
    		    quickSort( storage , begin , cutline-1 ) ;
    		else
    		    quickSort( storage , cutline+1 , end ) ;
		}  
    	else
    	{
    		quickSort( storage , begin , cutline-1 ) ;
    	    quickSort( storage , cutline+1 , end ) ;
		}
	}
}
