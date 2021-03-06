#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std ;

void Exchange( string[] , int[][3] , int ) ; 
int record ;

int main() 
{
	//人名数组 
	string name[9]={ "Chen" , "Cheng" , "Fang" , "Hu" , "Li" , "Liu" , "Qin" , "Sun" , "Yang" } ;
	//成绩数组 
	int score[9][3]={ {0,96,80}, {0,96,80} , {0,93,74} , {0,96,85} , {0,96,85} , {0,99,92} , {0,89,83} , {0,89,92} , {0,93,99} } ;
	//计算总分
	int sum_y ;
	for( sum_y=0 ; sum_y<=8 ; sum_y++ )
	{
		score[sum_y][0]=score[sum_y][1]+score[sum_y][2] ;
	}
	//排序前成绩输出测试
	cout << "________________排序前________________\n" ;
	int display_y ;
	for( display_y=0 ; display_y<=8 ; display_y++ )
	{
		cout << setw(6) << name[display_y] << setw(10) << score[display_y][1] << setw(10) << score[display_y][2] << setw(10) << score[display_y][0] << endl ;
	}
	cout << endl ;
	//排序
	do
	{
		
		record=0 ;
		int sequence_y ;
		for( sequence_y=0 ; sequence_y+1<=8 ; sequence_y++ )
		{
			if( score[sequence_y][0]<score[sequence_y+1][0] )
			{
                //交换分数和人名 
				Exchange( name , score , sequence_y ) ;
			}
			if( score[sequence_y][0]==score[sequence_y+1][0] )
			{
				if( score[sequence_y][1]<score[sequence_y+1][1] )
				{
                    //交换分数和人名 
				    Exchange( name , score , sequence_y ) ;
				}
			}
		} 
	} while ( record ) ;
	//排序后成绩输出测试 
	cout << endl << "________________排序后________________\n" ;
	for( display_y=0 ; display_y<=8 ; display_y++ )
	{
		cout << setw(6) << name[display_y] << setw(10) << score[display_y][1] << setw(10) << score[display_y][2] << setw(10) << score[display_y][0] << endl ;
	}
	return 0;
}

void Exchange( string name[] , int score[][3] , int sequence_y )
{
	//换人名
	string temp_name ;
	temp_name=name[sequence_y+1] ;
	name[sequence_y+1]=name[sequence_y] ;
	name[sequence_y]=temp_name ;	
	//交换各分 
	int exchange_score_x , temp_score ;
	for( exchange_score_x=0 ; exchange_score_x<=2 ; exchange_score_x++ )
	{
		temp_score=score[sequence_y+1][exchange_score_x] ;
		score[sequence_y+1][exchange_score_x]=score[sequence_y][exchange_score_x] ;
		score[sequence_y][exchange_score_x]=temp_score ;
		record++ ;	
	}

}
