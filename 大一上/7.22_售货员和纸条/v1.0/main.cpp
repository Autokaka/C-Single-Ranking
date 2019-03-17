#include <iostream>
#include <iomanip>
using namespace std ;

int main() 
{
	//生成二维数组 
	int array[6][5]={0} ;
	//读入 
	int days ;
	for( days=1 ; days<=30 ; days++ ) 
	{
		cout << "\n#第 " << days << " 天#\n" ; 
		int lie ;
		for( lie=1 ; lie<=4 ; lie++ )
	    {
			cout << "第 " << lie << " 位售货员：\n" ; 
			int hang ;
			for( hang=1 ; hang<=5 ; hang++ )
			{
				cout << "产品" << hang << "：" ; 
				cin >> array[hang][lie] ;
				array[hang][lie]+=array[hang][lie] ;
			}
		}
	}
	//求每种产品的总额 
	int process1_hang ; 
	for( process1_hang=1 ; process1_hang<=5 ; process1_hang++ )
	{
		int process1_lie ;
	    for( process1_lie=1 ; process1_lie<=4 ; process1_lie++ ) 
	    {
		    array[process1_hang][0]+=array[process1_hang][process1_lie] ;
	    }
	} 
	//求每个销售员的销售总额 
	int process2_lie ; 
	for( process2_lie=1 ; process2_lie<=4 ; process2_lie++ )
	{
		int process2_hang ;
	    for( process2_hang=1 ; process2_hang<=5 ; process2_hang++ ) 
	    {
		    array[0][process2_lie]+=array[process2_hang][process2_lie] ;
	    }
	} 
	//输出
	cout << "售货员" << setw(9) << "甲" << setw(7) << "乙" << setw(7) << "丙" << setw(7) << "丁" << setw(13) << "产品总额" << endl ;
	int display_hang ;
	for( display_hang=1 ; display_hang<=5 ; display_hang++ ) 
	{
		cout << "产品" << display_hang << setw(9) ; 
		int display_lie ;
		for( display_lie=1 ; display_lie<=4 ; display_lie++ )
		{
			cout << array[display_hang][display_lie] << setw(7) ;
			if( display_lie==4 )
			{
				cout << array[display_hang][0] << endl ; 
			} 
		}
		if( display_hang==5 )
		{
			cout << "产品总收益" << setw(4) ;
			int sum_lie ;
			for( sum_lie=1 ; sum_lie<=4 ; sum_lie++ )
			{
				cout << array[0][sum_lie] << setw(7) ; 
			}
		} 
	}
	return 0 ;
}
