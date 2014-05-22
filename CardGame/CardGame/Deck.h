#include "Card.h"

#ifndef DECK_H
#define DECK_H

#define DECK_SIZE 52

class Deck
{
private:
	struct card cards[DECK_SIZE];
	Deck() {}

public:
	Deck(); // initialize deck
	void Shuffle(); // Shuffle deck randomly
	struct card* retrieveHand(); // retrieve 5 cards from deck
};

#endif