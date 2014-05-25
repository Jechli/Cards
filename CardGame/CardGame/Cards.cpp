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
	else if ((int) left.rank >= (int) right.rank) { return false; }
	else { return true; }
}
