#include "Deck.h"
#include "Card.h"
#include <stdlib.h>

// Initialize deck
Deck::Deck()
{
	int i, index = 0;
	char* rk; 
	
	for (i = 1; i < 14; i++, index+4) {

		// get the rank
		if (i == 1) { rk = "A"; }
		else if (i == 11) { rk = "J"; }
		else if (i == 12) { rk = "Q"; }
		else if (i == 13) { rk = "K"; }
		else {
			*rk = (char) i;
		}

		// fill up rank with 4 suits
		cards[index].rank = rk;
		cards[index].suit = "D";		// diamonds
		cards[index+1].rank = rk;
		cards[index+1].suit = "S";		// spades
		cards[index+2].rank = rk;
		cards[index+2].suit = "H";		// hearts
		cards[index+3].rank = rk;
		cards[index+3].suit = "C";		// clubs

	}
}


// Deconstructor
Deck::~Deck()
{
}


// Shuffle the deck randomly
// Implementation of Fisher-Yates algorithm
void Deck::Shuffle()
{
}


// Get a new hand from the deck
void Deck::DealHand(struct card* hand)
{
	int i;

	for (i = 0; i < 5; i++) {
		*(hand+i) = cards[new_card_index];
		new_card_index++;
	}

	return;
}