#include "Cards.h"

// operator overloads
bool operator <(const struct card &left, const struct card &right) 
{
	if (left.rank == right.rank) { return false; }
	else if (left.rank == "A") { return false; }
	else if (left.rank == "K" && right.rank != "A") { return false; }
	else if (left.rank == "Q" && (right.rank != "A" || right.rank != "K")) { return false; }
	else if (left.rank == "J" && (right.rank != "A" || right.rank != "K" || right.rank != "Q")) 
		{ return false; }
	else if (right.rank == "A") { return true; }
	else if (right.rank == "K" && left.rank != "A") { return true; }
	else if (right.rank == "Q" && (left.rank != "A" || left.rank != "K")) { return true; }
	else if (right.rank == "J" && (left.rank != "A" || left.rank != "K" || left.rank != "Q")) 
		{ return true; }
	else if ((int) left.rank >= (int) right.rank) { return false; }
	else { return true; }
}

int operator-(const struct card &card1, const struct card &card2)
{
	int arg1, arg2;

	if (card1.rank == "A") { arg1 = 14; }
	else if (card1.rank == "K") { arg1 = 13; }
	else if (card1.rank == "Q") { arg1 = 12; }
	else if (card1.rank == "J") { arg1 = 11; }
	else { arg1 = (int) card1.rank; }
	
	if (card2.rank == "A") { arg2 = 14; }
	else if (card2.rank == "K") { arg2 = 13; }
	else if (card2.rank == "Q") { arg2 = 12; }
	else if (card2.rank == "J") { arg2 = 11; }
	else { arg2 = (int) card2.rank; }

	return (arg1 - arg2);
}
