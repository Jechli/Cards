#pragma once
#define HAND_SIZE 5
#define RANKS 13
#define SUITS 4
#define DECK_SIZE (RANKS*SUITS)
#define PLAYERS 10
#define MAX_PLAYERS (DECK_SIZE/HAND_SIZE)

// Cards structure
struct card 
{
	char* rank;
	char* suit;
};

// operator overloads
bool operator <(const struct card &left, const struct card &right);
bool operator >(const struct card &left, const struct card &right);
