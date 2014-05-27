#include "Deck.h"
#include <stdlib.h>
#include <time.h>

#pragma warning( disable : 4244 ) 

// fix: Should create an array with all ranks, array with all suits, and fill accordingly.

// Initialize deck 
Deck::Deck()
{
	int i, j, index = 0; 
	new_card_index = 0;
	char* SUITS_SET[SUITS] = {"S", "H", "C", "D"};
	char* RANKS_SET[RANKS] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	
	for (i = 0; i < RANKS; i++) {			// for all ranks
		for (j = 0; j < SUITS; j++) {       // for all suits
			cards[index].rank = RANKS_SET[i];
			cards[index].suit = SUITS_SET[j];
			index++;
		}
	}
}


// Shuffle the deck randomly
void Deck::Shuffle()
{
	int i, cards_left, rand_num;
	struct card temp_card;

	for (i = 0, cards_left = DECK_SIZE; i < DECK_SIZE; i++, cards_left--) {
		srand(time(NULL));
		rand_num = rand() % cards_left;
		temp_card = cards[i];
		cards[i] = cards[rand_num];
		cards[rand_num] = temp_card;
	}

	return;
}


// Get a new hand from the deck
struct card Deck::DealCard()
{
	struct card temp = cards[new_card_index];
	new_card_index++;
	if (new_card_index >= HAND_SIZE*PLAYERS) { new_card_index = 0; }
	return temp;
}