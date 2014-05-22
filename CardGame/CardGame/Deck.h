#include "Card.h"

#ifndef DECK_H
#define DECK_H

#define DECK_SIZE 52

class Deck
{
	struct card cards[DECK_SIZE];

public:
	Deck(); // initialize deck
	~Deck(); // destructor
	void Shuffle(); // Shuffle deck randomly
	struct card* GetHand(); // retrieve 5 cards from deck
};

#endif

