#pragma once
#define HAND_SIZE 5
#define RANKS 13
#define SUITS 4
#define DECK_SIZE (RANKS*SUITS)
#define PLAYERS 10
#define MAX_PLAYERS (DECK_SIZE/HAND_SIZE)


struct card 
{
	char* rank;
	char* suit;
};


// Overloading '<' and '-'
bool operator <(const struct card &left, const struct card &right);	// Returns true if left rank < right rank
int operator -(const struct card &card1, const struct card &card2);	// Returns the difference between ranks in terms of cards