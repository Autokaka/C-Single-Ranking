#include <iostream>
using namespace std ;

int main ()
{
	int type ;//员工类型
	double salary ; 
	double t ;//工作时长
	double w ;//销售毛利  
	int n ;//产品件数
	double m ;//每件产品的固定金额 
	int command ;
	cout << "按下任意按键以开始..." ;  
	while ( ( type = cin.get() ) != EOF )
    {
		cout << "请输入员工类型(1.经理 2.小时工 3.佣金工 4.计件工)" ; 
		cin >> type ; 
		switch ( type )
		{
			case 1 :
			    cout << "请输入固定工资：" ;
				cin >> salary ; 
				break ;
			case 2 :
				cout << "请输入工作时长：" ;
				cin >> t ;
				cout << "请输入固定小时工资：" ;
				cin >> salary ;
				if ( t <= 40 ) 
				{
					salary = salary*t ;
				}
				else 
				{
				salary = 40*t+(salary-40)*1.5*salary ;
				}
				break ;
			case 3 :
				cout << "请输入销售毛利：" ;
				cin >> w ;
				salary = 250+.057*w ; 
				break ;
		    case 4 : 
		        cout << "请输入该员工生产的产品件数和每件产品的固定金额：" ;
		        cin >> n >> m ;
		        salary = n*m ;
	            break ;
	    }
		cout << "该员工本周的工资总额为" << salary << endl 
		     << "是否进入下一员工？(按任意键继续或者按ctrl+Z退出...)" ;
		cin >> command ;
		if ( ( command = cin.get() ) != EOF ) 
		continue ;
		else
		break ;
    }
    return 0 ;
} 
