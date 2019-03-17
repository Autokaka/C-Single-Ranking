#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std ;

//��ʼ������
void initialize_array( char * , int ) ; 
//ÿһ���ڹ�Ŀ��ܲ���
int tortoise_possibility( char * ) ;
//ÿһ�����ӵĿ��ܲ���
int hare_possibility( char * ) ; 
//�յ��ж�/Խ���ж� 
void final_check( char * , char * , char * ) ;
bool flag=false ; 
//��ǵ�ǰλ��
void mark( char * , char * ) ; 

int main()
{
	//�������� 
	const int race_length=70 ;
	char race[race_length] ;
	//��ʼ������ 
	initialize_array( race , race_length ) ;
	//�������ָ�뵽������ʼλ�� 
	char *tortoise=race , *hare=race ; 
	//��Ϸ��ʼ
	srand(time(0)) ;
	cout << "BANG !!!!!\nAND THEY'RE OFF !!!!!\n" ;
	while( flag!=true ) 
	{
		//ÿһ���ڹ�Ŀ��ܲ���
		int movement_T=tortoise_possibility(tortoise) ;
		if( tortoise+movement_T<=race )
		    tortoise=race ;
		else
		    tortoise+=movement_T ;
		//ÿһ�����ӵĿ��ܲ���
		int movement_H=hare_possibility(hare) ;
		if( hare+movement_H<=race )
		    hare=race ;
		else
		    hare+=movement_H ;
		//�յ��ж�/Խ���ж� 
		final_check( tortoise , hare , race ) ;
		//�жϲ��Ҿ����Ƿ��ǵ�ǰλ�� 
		if( flag!=true )
		{
			mark( tortoise , hare ) ; 
			if( *tortoise=='X' )//ײ��һ��ȥ��
			{
				char *search=race ;
				for( search ; search<tortoise ; search++ )
					cout << *search ;
				cout << "OUCH!!!\n" ;
			} 
			else//ûײ��һ��
			    cout << race << endl ;
		}
		//�ٴγ�ʼ������  
		initialize_array( race , race_length ) ;
	}
	return 0;
}

//��ʼ������
void initialize_array( char *race , int race_length )
{
	int init ;
	for( init=0 ; init<race_length ; init++ )
		*(race+init)=' ' ;
}

//ÿһ���ڹ�Ŀ��ܲ���
int tortoise_possibility( char *tortoise ) 
{
	int t_possi=1+rand()%10 , movement_T=0 ;
	
	switch( t_possi )
	{
		//50% �����ƶ�3������ 
		case 1 :
		case 2 :
		case 3 :
		case 4 :
		case 5 :
			movement_T+=3 ;
			break ;
		//20% �����ƶ�6������ 
		case 6 :
		case 7 :
			movement_T-=6 ;
			break ;
		//30% �����ƶ�1������ 
		case 8 :
		case 9 :
		case 10 :
			++movement_T ;
			break ;
	}
	return movement_T ;
}

//ÿһ�����ӵĿ��ܲ���
int hare_possibility( char *hare )
{
	int h_possi=1+rand()%10 , movement_H=0 ;
	
	switch( h_possi )
	{
		//���� 
		case 1 :
		case 2 :
			break ;
		//�����ƶ�9������ 
		case 3 :
		case 4 :
			movement_H+=9 ;
			break ;
		//�����ƶ�12������ 
		case 5 :
			movement_H-=12 ;
			break ;
		//�����ƶ�1������ 
		case 6 :
		case 7 :
		case 8 :
			++movement_H ;
			break ;
		//�����ƶ�2������ 
		case 9 :
		case 10 :
			movement_H+=2 ;
			break ;
	}
	return movement_H ;
}

//�յ��ж�/Խ���ж� 
void final_check( char *tortoise , char *hare , char *race )
{
	if( tortoise>=(race+strlen(race)-1) || hare>=(race+strlen(race)-1) )//��������һ�������յ� 
	{
		if( tortoise>=(race+strlen(race)-1) && hare>=(race+strlen(race)-1) )//���Ѿ������յ㣬ƽ�� 
		    cout << "It's a tie.\n" ;
		else if( tortoise>=(race+strlen(race)-1) && hare<(race+strlen(race)-1) )//����ƽ�֣����ڹ�ʤ��
		    cout << "TORTOISE WINS!!! YAY!!!\n" ; 
		else
		    cout << "HARE WINS. YUCH.\n" ;
		
		flag=true ;
	}
}

//��ǵ�ǰλ��
void mark( char *tortoise , char *hare )
{
	if( tortoise==hare )//��������һ��λ�� 
	    *tortoise='X' ;
	else//û��һ��λ�� 
    {
    	*tortoise='T' ;
    	*hare='H' ;
	}
} 
