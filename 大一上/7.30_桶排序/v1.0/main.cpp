#include <iostream>
using namespace std ;

void bucketSort( int [] , int ) ; 

int main() 
{
	//待排序的数组
	int arraysize=6 ;
	int storage[arraysize]={97,26,38,76,32,48} ;
	bucketSort( storage , arraysize ) ; 
	//输出结果 
	int display ;
	for( display=0 ; display<arraysize ; display++ )
		cout << storage[display] << " " ;
	return 0 ;
}

void bucketSort( int storage[] , int arraysize )
{
	//桶数组 
	int bucket[10][arraysize]={0} ;
	//计数器 
	int cnt[10]={0} ;
	//根据最大数位确定循环次数 
	int level ;//数量级 
	for( level=10 ; cnt[0]!=arraysize ; level*=10 )
	{
		//计数器清零 
		int zero ;
		for( zero=0 ; zero<10 ;zero++ )
			cnt[zero]=0 ;
	    //存储数组导入到桶
		int storage_x , each ;//每个数位
		for( storage_x=0 ; storage_x<arraysize ; storage_x++ )
		{
		    each=(storage[storage_x]/(level/10))%10 ;
		    bucket[each][cnt[each]++]=storage[storage_x] ;
		}
	    //桶返回存储数组
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
