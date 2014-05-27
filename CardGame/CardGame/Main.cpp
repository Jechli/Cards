#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Player.h"
#include "Deck.h"
#include "Score.h"
using namespace std;

int main (void) 
{
	// need something to check that there are enough cards to players
	Deck deck = Deck(); // OKAY
	deck.Shuffle();	// OKAY
	Player poker_players[PLAYERS];	// OKAY

	int i, j, points;
	struct card new_hand[HAND_SIZE];
	for (i = 0; i < PLAYERS; i++) {
		poker_players[i] = Player(i);	// OKAY
		for (j = 0; j < HAND_SIZE; j++) {
			new_hand[j] = deck.DealCard();
		}
		poker_players[i].SetHand(new_hand);	// OKAY, sortHand OKAY!!
		points = CalculatePoints(new_hand);
		poker_players[i].SetPoints(points);
	}



	// TODO just need to sort players!!!

	cout << poker_players[7].GetID() << endl; // this is how you print....
	system( "pause" );
	return 0;
}