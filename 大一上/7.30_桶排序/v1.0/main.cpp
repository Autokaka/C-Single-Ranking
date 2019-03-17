#include <iostream>
using namespace std ;

void bucketSort( int [] , int ) ; 

int main() 
{
	//�����������
	int arraysize=6 ;
	int storage[arraysize]={97,26,38,76,32,48} ;
	bucketSort( storage , arraysize ) ; 
	//������ 
	int display ;
	for( display=0 ; display<arraysize ; display++ )
		cout << storage[display] << " " ;
	return 0 ;
}

void bucketSort( int storage[] , int arraysize )
{
	//Ͱ���� 
	int bucket[10][arraysize]={0} ;
	//������ 
	int cnt[10]={0} ;
	//���������λȷ��ѭ������ 
	int level ;//������ 
	for( level=10 ; cnt[0]!=arraysize ; level*=10 )
	{
		//���������� 
		int zero ;
		for( zero=0 ; zero<10 ;zero++ )
			cnt[zero]=0 ;
	    //�洢���鵼�뵽Ͱ
		int storage_x , each ;//ÿ����λ
		for( storage_x=0 ; storage_x<arraysize ; storage_x++ )
		{
		    each=(storage[storage_x]/(level/10))%10 ;
		    bucket[each][cnt[each]++]=storage[storage_x] ;
		}
	    //Ͱ���ش洢����
		int bucket_y , mark=0;
		for( bucket_y=0 ; bucket_y<10 ; bucket_y++ )
		{
			int count_bucket_x ;
			for( count_bucket_x=0 ; count_bucket_x<cnt[bucket_y] ; count_bucket_x++ )
			{
				if( mark>=arraysize )
				    break ;
				else
				    storage[mark++]=bucket[bucket_y][count_bucket_x] ;
			}
		}
	}
}
