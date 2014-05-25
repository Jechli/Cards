#include "Deck.h"
#include <stdlib.h>
#include <time.h>

#pragma warning( disable : 4244 ) 

// fix: Should create an array with all ranks, array with all suits, and fill accordingly.

// Initialize deck
Deck::Deck()
{
	int i, index = 0;
	char* rk; 

	new_card_index = 0;
	
	for (i = 1; i < 14; i++, index+4) { // for all ranks, create 4 suits

		// get the rank
		if (i == 1) { rk = "A"; }
		else if (i == 11) { rk = "J"; }
		else if (i == 12) { rk = "Q"; }
		else if (i == 13) { rk = "K"; }
		else {
			*rk = (char) i;
		}

		// fill up rank with 4 suits
		cards[index]->rank = rk;
		cards[index]->suit = "D";		// diamonds
		cards[index+1]->rank = rk;
		cards[index+1]->suit = "S";		// spades
		cards[index+2]->rank = rk;
		cards[index+2]->suit = "H";		// hearts
		cards[index+3]->rank = rk;
		cards[index+3]->suit = "C";		// clubs

	}

	free(rk);
}


// Shuffle the deck randomly
void Deck::Shuffle()
{
	int i, cards_left, rand_num;
	struct card temp_card;

	for (i = 0, cards_left = DECK_SIZE-1; i < DECK_SIZE; i++, cards_left--) {
		srand(time(NULL));
		rand_num = rand() % cards_left;
		temp_card = *(cards[i]);
		*(cards[i]) = *(cards[rand_num]);
		*(cards[rand_num]) = temp_card;
	}

	return;
}


// Get a new hand from the deck
void Deck::DealHand(struct card* hand)
{
	int i;

	for (i = 0; i < HAND_SIZE; i++) {
		*(hand+i) = *(cards[new_card_index]);
		new_card_index++;
	}

	return;
}