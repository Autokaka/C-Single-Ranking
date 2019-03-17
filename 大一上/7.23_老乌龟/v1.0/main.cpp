#include <iostream>
#include <cstdlib>
using namespace std ; 

int main() 
{
	//设定方向的枚举 
	enum Drection { RIGHT , DOWN , LEFT , UP } ;
	Drection turtleDirection=RIGHT ;
	//设定笔尖朝向枚举
	enum Pen { PEN_UP , PEN_DOWN } ;
	Pen turtlePen=PEN_UP ; 
	//指令数组
	int command[15]={2,5,12,3,5,12,3,5,12,3,5,12,1,6,9} ;
	//奔跑用20x20数组 
	int floor[20][20]={0} ; 
	///指令执行细节
	int content , x_position=0 , y_position=0 ;
	for( content=0 ; content<=14 ; content++ )
	{
		switch( command[content] )
		{
			case 1 :
				turtlePen=PEN_UP ;
				break ;
			case 2 :
				turtlePen=PEN_DOWN ;
				break ;
			case 3 :
				switch( turtleDirection )
				{
					case RIGHT :
						turtleDirection=DOWN ;
						break ;
					case DOWN :
						turtleDirection=LEFT ;
						break ;
					case LEFT :
						turtleDirection=UP ;
						break ;
					case UP :
						turtleDirection=RIGHT ;
						break ;
				}
				break ;
			case 4 :
				switch( turtleDirection )
				{
					case RIGHT :
						turtleDirection=UP ;
						break ;
					case DOWN :
						turtleDirection=RIGHT ;
						break ;
					case LEFT :
						turtleDirection=DOWN ;
						break ;
					case UP :
						turtleDirection=LEFT ;
						break ;
				}
				break ;
			case 5 :
				content++ ;
				int star ;
				for( star=1 ; star<=command[content] ; star++ )
				{
					switch( turtlePen ) 
					{
						case PEN_UP ://不画
					        switch( turtleDirection )
					        {
					    	    case RIGHT :
					    	    	if(x_position+1>19)
					        		{
					        			cout << "超出边界，请重新设定指令..." ; 
									}
									else
					                {
					                	x_position++ ;
									}
						        	break ;
					            case DOWN :
					            	if(y_position+1>19)
					        		{
					        			cout << "超出边界，请重新设定指令..." ; 
									}
									else
								    {
								    	y_position++ ;
									}
					    	    	break ;
					        	case LEFT :
					        		if(x_position-1<0)
					        		{
					        			cout << "超出边界，请重新设定指令..." ; 
									}
									else
									{
										x_position-- ;
									}
						        	break ;
					    	    case UP :
					    	    	if(y_position-1<0)
					        		{
					        			cout << "超出边界，请重新设定指令..." ; 
									}
									else
									{
										y_position-- ;
									}
						        	break ;	
					        }
					        break ;
					    case PEN_DOWN ://画
					        switch( turtleDirection )
					        {
					        	case RIGHT :
					        		if(x_position+1>19)
					        		{
					        			cout << "超出边界，请重新设定指令..." ; 
									}
									else
									{
					              		floor[x_position][y_position]=1 ;
					            		floor[x_position+1][y_position]=1 ;
					             		x_position++ ;
									}
					        		break ;									
					            case DOWN :
					            	if(y_position+1>19)
					        		{
					        			cout << "超出边界，请重新设定指令..." ; 
									}
									else
									{
					        			floor[x_position][y_position]=1 ;
					        			floor[x_position][y_position+1]=1 ;
					        			y_position++ ;									
									}
									break ;
					        	case LEFT :
					            	if(x_position-1<0)
					        		{
					        			cout << "超出边界，请重新设定指令..." ; 
									}
									else
									{
					        			floor[x_position][y_position]=1 ;
					        			floor[x_position-1][y_position]=1 ;
					        			x_position-- ;										
									}
					        		break ;
					        	case UP :
					        		if(y_position-1<0)
					        		{
					        			cout << "超出边界，请重新设定指令..." ; 
									}
									else
									{
					        			floor[x_position][y_position]=1 ;
					        			floor[x_position][y_position-1]=1 ;
					        			y_position-- ;
									}
					        		break ;	
					        }	
					}
				}
			    break ;
			case 6 :
				int y ;
				for( y=0 ; y<=19 ; y++ )
				{
					int x ;
					for( x=0 ; x<=19 ; x++ )
					{
						if( floor[x][y]==0 )
						{
							cout << "  " ;
						}
						else
						{
							cout << "* " ;
						}
						if( x==19 )
						{
							cout << endl ;
						}
					}
				}
				break ;
			case 9 :
				break ;
		}
		if( command[content]==9 )
		    break ;
	} 
    
	return 0;
}
