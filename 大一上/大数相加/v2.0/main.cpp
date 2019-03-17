#include <iostream>
using namespace std ; 

void sumup( int [][ArraySize_max] , int , int ) ;
int cnt=0 ;//记录进位 

void cin_number( int [][ArraySize_max] , int , int ) ;

int main() 
{
	//要加几个大数 
	int how_many ; 
	cout << "你要加几个大数？" ;
	cin >> how_many ; 
	//逐个输入待加数数位,并找出最大数位 
	int ArraySize[how_many+1]={0} ; 
	int search , ArraySize_max ;
    for ( search=1 ; search<=how_many ; search++ )
	{
		cout << "第 " << search << " 个数字的数位：" ;
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
	//加数和被加数以及 加和(第0行) 二维数组 
    int numbers[how_many+1][ArraySize_max]={0} ;
	//输入
	cin_number( numbers , how_many , ArraySize_max ) ; 
	//相加 
    sumup( numbers , how_many , ArraySize_max ) ;
	//输出结果
	int display ;
	if( cnt!=0 )
        cout << cnt ; 
        
    for( display=0 ; display<=ArraySize_max-1 ; display++ )
	    cout << numbers[0][display] ;
	
	return 0 ;
}
//填入每个大数 
void cin_number( int numbers[][ArraySize_max] , int how_many , int ArraySize_max )
{
	cout << "请逐个输入每个数位：\n" ; 
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
//每个大数求和到第0排数组里面 
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
