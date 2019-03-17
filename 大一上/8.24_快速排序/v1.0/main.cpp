#include <iostream>
#include <cstring>
using namespace std ;

//排序函数 
void quickSort( int * , int , int ) ;

//分区函数 
int partition( int * , int , int ) ; 
int r2l , l2r ;

//交换函数 
void swap( int * , int * ) ;

//主函数 
int main()
{
	//生成数组
	cout << "你需要排多少个数？\n" ;
	int arraysize=0 ;
	cin >> arraysize ;
	int storage[arraysize]={0} ;
	cout << "你要排列哪些数？\n" ;
	int fill ;
	for( fill=0 ; fill<arraysize ; fill++ )
	    cin >> storage[fill] ;
	//数组首尾元素编号 
	int begin=0 , end=arraysize-1 ;
	//排序 
	quickSort( storage , begin , end ) ;
	//输出结果
	int display ;
	for( display=0 ; display<arraysize ; display++ )
	    cout << storage[display] << " " ; 
	
	return 0;
}


//交换函数 
void swap( int *a , int *b )
{
	int temp=*a ;
	*a=*b ;
	*b=temp ;
}

//分区函数_返回界限值 
int partition( int *storage , int begin , int end )
{
	
	//从右往左找更小 
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
	    
	
	//从左往右找更大 
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

//排序函数 
void quickSort( int *storage , int begin , int end )
{
    if ( end-begin>=1 )//区间长度>0 
    {
    	int cutline=partition( storage , begin , end ) ;//寻找界限 
    	if( cutline==end||cutline==begin )//cutline到边界了 
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
