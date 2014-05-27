#include "Cards.h"
#include "Player.h"

#pragma once

class Deck
{
	int new_card_index;				// index of a new card in the deck
	struct card cards[DECK_SIZE];

public:
	Deck();							// constructor
	~Deck() {}						// deconstructor

	void Shuffle();					// Shuffle deck randomly
	struct card DealCard();		// Deal a new hand 
};


