#include <iostream>
using namespace std ;
#include <cstdlib>
#include <ctime>

int rollDice() ;

int main ()
{
	int bankBalance =  1000 ;
	int wager ;
	
	while ( bankBalance != 0 )
	{
		cout << "Please give me your wager: " ;
		cin >> wager ;
		
		while ( wager <= 0 )
		{
			cout << "Ilegal wage , please try again : " ;
		    cin >> wager ;
		}

		enum Status { CONTINUE , WON , LOST } ;
	
		int myPoint ;
		Status gameStatus ;
		
		int sumOfDice = rollDice() ;
	    
	    switch ( sumOfDice )
 	   {
 	   		case 7 :
  		  	case 11 :
    		    gameStatus = WON ;
    	  	    break ;
    		case 2 :
    		case 3 :
    		case 12 :
    			gameStatus = LOST ;
    			break ;
    		default :
    			gameStatus = CONTINUE ;
    			myPoint = sumOfDice ;
    			cout << "Point is " << myPoint << endl ;
				break ; 
	}
	
		while ( gameStatus == CONTINUE )
		{
			sumOfDice = rollDice() ;
		
			if ( sumOfDice == myPoint )
			    gameStatus = WON ;
			else
			    if ( sumOfDice == 7 )
				    gameStatus = LOST ; 
		}
	
		if ( gameStatus = WON )
		{
			bankBalance += wager ; 
			if ( bankBalance >= 25000 )
			{
				cout << "Now you have :" << bankBalance << " $ !" << endl 
				     <<"You're quite big. Now's the time to cash in your chips!" << endl ;
			}
			else 
			{
				cout << "Great! You win this round!\n" 
			         << "Now you have :" << bankBalance << " $ !" << endl ;
			}
		}
		else 
		{
			if ( bankBalance-wager <= 0 )
			{
				cout << "Sorry. You busted!" << endl ;
			}
			else 
			{
				bankBalance -= wager ;
				if ( bankBalance <= 250 )
				{
					cout << "Now you have :" << bankBalance << " $" << endl 
					     << "Oh, you're going for broke , huh?" << endl ;
				}
				else 
				{
					cout << "Aw cmon, take a chance!\n" 
				         << "Now you have :" << bankBalance << " $" << endl ;
				}
			}
		}
    }
	return 0 ;
}

int rollDice ()
{
	srand ( time(0) ) ;
	int die1 = 1+rand()%6 ;
	int die2 = 1+rand()%6 ;
	
	int sum = die1+die2 ;
	
	cout << "Player rolled " << die1 << "+" << die2 
	     << "£½" << sum << "..." << endl ;
	return sum ;
}
