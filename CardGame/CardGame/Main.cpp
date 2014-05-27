#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Player.h"
#include "Deck.h"
#include "Score.h"
using namespace std;

void PrintHand(Player p);

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

		for (j = 0; j < HAND_SIZE; j++) {    // OKAY
			new_hand[j] = deck.DealCard();
		}

		poker_players[i].SetHand(new_hand);	// OKAY, sortHand OKAY!!
		points = CalculatePoints(new_hand);  // SOME NOT TESTED
		poker_players[i].SetPoints(points);  // OKAY
	}

	cout << "BEFORE: \n" << endl;
	for (i = 0; i < PLAYERS; i++) {
		cout << poker_players[i].GetID() << ": " << poker_players[i].GetPoints() << " points." 
			<< endl;
		PrintHand(poker_players[i]);
		cout << endl;
	}

	SortPlayers(poker_players);

	cout << "AFTER: \n" << endl;
	for (i = 0; i < PLAYERS; i++) {
		cout << poker_players[i].GetID() << ": " << poker_players[i].GetPoints() << " points." 
			<< endl;
		PrintHand(poker_players[i]);
		cout << endl;
	}
	system( "pause" );
	return 0;
}


void PrintHand(Player p) 
{
	int i; 
	cout << "Cards " << ": [";
	for (i = 0; i < HAND_SIZE; i++) { 
			cout << "-" << p.GetHand()[i].rank << p.GetHand()[i].suit << "-";
	}
	cout << "]" << endl;
	return;
}