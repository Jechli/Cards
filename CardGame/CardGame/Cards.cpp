#include "Cards.h"

// Private Helper Function
int FindIntValue(char* a);


// Overloading <
// Returns true is left card has a smaller rank than the right card
bool operator <(const struct card &left, const struct card &right) 
{
	int l = FindIntValue(left.rank);
	int r = FindIntValue(right.rank);
	return l < r;	
}


// Overloading -
// It returns the difference in cards between two card rankings
// Example: K - J = 2 cards.
int operator -(const struct card &card1, const struct card &card2)
{
	int arg1 = FindIntValue(card1.rank); 
	int arg2 = FindIntValue(card2.rank);

	return (arg1 - arg2);
}




/*********PRIVATE HELPER FUNCTION**************/

// Finds an int value for each 
int FindIntValue(char* a) 
{
	if (a == "A") { return 14; }
	else if (a == "K") { return 13; }
	else if (a == "Q") { return 12; }
	else if (a == "J") { return 11; }
	else if (a == "10") { return 10; }
	else if (a == "9") { return 9; }
	else if (a == "8") { return 8; }
	else if (a == "7") { return 7; }
	else if (a == "6") { return 6; }
	else if (a == "5") { return 5; }
	else if (a == "4") { return 4; }
	else if (a == "3") { return 3; }
	else { return 2; }
}
