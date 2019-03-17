#include <iostream>
#include "TimeDate.h"
#include <windows.h>
using namespace std ;

int main() 
{
	TimeDate mytime;
	int year, month, day, hour, minute, second;
	
	cout << "依次输入：年/月/日/时/分/秒\n";
	cin >> year >> month >> day >> hour >> minute >> second; 
	mytime.setTimeDate( year, month, day, hour, minute, second );
	
	int choice=12;
	cout << "12 or 24小时制？(12/24)";
	cin >> choice;
	
	while(1)
	{
		switch( choice )
		{
			case 12:
				mytime.printStandard();
				break;
			case 24:
				mytime.printUniversal();
				break;
		}
		mytime.tick();
		Sleep( 1000 );
		system("cls");
	}
	return 0;
}
