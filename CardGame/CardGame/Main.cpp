#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Player.h"
#include "Deck.h"
#include "Score.h"
using namespace std;

int main (void) 
{
	Deck deck = Deck(); // OKAY
	deck.Shuffle();	// OKAY
	Player poker_players[PLAYERS];	// OKAY
	int i;
	for (i = 0; i < PLAYERS; i++) {
		poker_players[i] = Player(i);	// OKAY
	}
	cout << "Hi" << endl;
	system( "pause" );
	return 0;
}