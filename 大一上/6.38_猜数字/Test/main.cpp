#include <iostream>
using namespace std ;
#include <cstdlib>
#include <ctime>

int Judge( int , int ) ;

int main ()
{
	while ( cin.get() != EOF )
	{
		int x ;
		int guess ;
		cout << "I have a number between 1 and 1000.\n" 
		     << "Can you guess my number ?\n" 
		     << "Please type your first guess.\n" ;
		srand ( time(0) ) ;
    	x = 1+rand()%1000 ;
    	/*cout << x ;*/
    	cin >> guess ; 
    
    	enum Status { RIGHT , HIGH , LOW } ;
    	Status gameStatus ;
    
        if ( guess == x )
    	{
    		gameStatus = RIGHT ;
    		cout << "Exellent! You guessed the number!\n" ;
    		
			cout << "Wanna continue£¿Enter to continue, Ctrl+Z to exit... \n" ; 
			if ( cin.get() == EOF ) 
    		    break ;
    		else 
			    continue ;
		}
		
    	while ( cin.get() != EOF )
		{		
			if ( guess > x )
    		{
    			gameStatus = HIGH ;
				cout << "Too high. Try again.\n" ;
				
				cout << "Wanna continue£¿Enter to continue, Ctrl+Z to exit... \n" ; 
				if ( cin.get() == EOF ) 
    			    break ;
    			else
    			{
    			    cout << "Revise: " ;
    			    cin >> guess ;
    		    }
			}
			
			if ( guess < x )
			{
				gameStatus = LOW ;
				cout << "Too low. Try again.\n" ;
				
				cout << "Wanna continue£¿Enter to continue, Ctrl+Z to exit... \n" ; 
				if ( cin.get() == EOF ) 
    			    break ;
    			else
    			{
    			    cout << "Revise: " ;
				    cin >> guess ;
			    }
			}
		} 
	} 
} 
