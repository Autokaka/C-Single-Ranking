#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std ;

//初始化数组
void initialize_array( char * , int ) ; 
//每一次乌龟的可能操作
int tortoise_possibility( char * ) ;
//每一次兔子的可能操作
int hare_possibility( char * ) ; 
//终点判断/越界判断 
void final_check( char * , char * , char * ) ;
bool flag=false ; 
//标记当前位置
void mark( char * , char * ) ; 

int main()
{
	//生成赛道 
	const int race_length=70 ;
	char race[race_length] ;
	//初始化数组 
	initialize_array( race , race_length ) ;
	//定义龟兔指针到赛道初始位置 
	char *tortoise=race , *hare=race ; 
	//游戏开始
	srand(time(0)) ;
	cout << "BANG !!!!!\nAND THEY'RE OFF !!!!!\n" ;
	while( flag!=true ) 
	{
		//每一次乌龟的可能操作
		int movement_T=tortoise_possibility(tortoise) ;
		if( tortoise+movement_T<=race )
		    tortoise=race ;
		else
		    tortoise+=movement_T ;
		//每一次兔子的可能操作
		int movement_H=hare_possibility(hare) ;
		if( hare+movement_H<=race )
		    hare=race ;
		else
		    hare+=movement_H ;
		//终点判断/越界判断 
		final_check( tortoise , hare , race ) ;
		//判断并且决定是否标记当前位置 
		if( flag!=true )
		{
			mark( tortoise , hare ) ; 
			if( *tortoise=='X' )//撞到一块去了
			{
				char *search=race ;
				for( search ; search<tortoise ; search++ )
					cout << *search ;
				cout << "OUCH!!!\n" ;
			} 
			else//没撞到一块
			    cout << race << endl ;
		}
		//再次初始化数组  
		initialize_array( race , race_length ) ;
	}
	return 0;
}

//初始化数组
void initialize_array( char *race , int race_length )
{
	int init ;
	for( init=0 ; init<race_length ; init++ )
		*(race+init)=' ' ;
}

//每一次乌龟的可能操作
int tortoise_possibility( char *tortoise ) 
{
	int t_possi=1+rand()%10 , movement_T=0 ;
	
	switch( t_possi )
	{
		//50% 向右移动3个方格 
		case 1 :
		case 2 :
		case 3 :
		case 4 :
		case 5 :
			movement_T+=3 ;
			break ;
		//20% 向左移动6个方格 
		case 6 :
		case 7 :
			movement_T-=6 ;
			break ;
		//30% 向右移动1个方格 
		case 8 :
		case 9 :
		case 10 :
			++movement_T ;
			break ;
	}
	return movement_T ;
}

//每一次兔子的可能操作
int hare_possibility( char *hare )
{
	int h_possi=1+rand()%10 , movement_H=0 ;
	
	switch( h_possi )
	{
		//不动 
		case 1 :
		case 2 :
			break ;
		//向右移动9个方格 
		case 3 :
		case 4 :
			movement_H+=9 ;
			break ;
		//向左移动12个方格 
		case 5 :
			movement_H-=12 ;
			break ;
		//向右移动1个方格 
		case 6 :
		case 7 :
		case 8 :
			++movement_H ;
			break ;
		//向右移动2个方格 
		case 9 :
		case 10 :
			movement_H+=2 ;
			break ;
	}
	return movement_H ;
}

//终点判断/越界判断 
void final_check( char *tortoise , char *hare , char *race )
{
	if( tortoise>=(race+strlen(race)-1) || hare>=(race+strlen(race)-1) )//其中任意一个到达终点 
	{
		if( tortoise>=(race+strlen(race)-1) && hare>=(race+strlen(race)-1) )//都已经到达终点，平局 
		    cout << "It's a tie.\n" ;
		else if( tortoise>=(race+strlen(race)-1) && hare<(race+strlen(race)-1) )//不是平局，且乌龟胜出
		    cout << "TORTOISE WINS!!! YAY!!!\n" ; 
		else
		    cout << "HARE WINS. YUCH.\n" ;
		
		flag=true ;
	}
}

//标记当前位置
void mark( char *tortoise , char *hare )
{
	if( tortoise==hare )//两个到了一个位置 
	    *tortoise='X' ;
	else//没在一个位置 
    {
    	*tortoise='T' ;
    	*hare='H' ;
	}
} 
