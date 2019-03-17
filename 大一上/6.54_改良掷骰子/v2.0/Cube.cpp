#include <iostream>
using namespace std ;
#include <cstdlib>
#include <ctime>

#include "Cube.h"

int  Cube :: rollDice ()
{
	srand ( time(0) ) ;
	int die1 = 1+rand()%6 ;
	int die2 = 1+rand()%6 ;
	
	int sum = die1+die2 ;
	
	cout << "Player rolled " << die1 << "+" << die2 
	     << "£½" << sum << "..." << endl ;
	return sum ;
}


