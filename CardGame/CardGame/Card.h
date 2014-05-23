#pragma once
#define HAND_SIZE 5
#define RANKS 13
#define SUITS 4
#define DECK_SIZE (RANKS*SUITS)

// Cards structure
struct card 
{
	char* rank;
	char* suit;
};