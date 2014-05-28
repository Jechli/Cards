#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Player.h"
#include "Deck.h"
#include "Score.h"

using namespace std;

void PrintHand(Player p);
void PrintPlayers(Player p[PLAYERS]);
void DealCardsToPlayers(Player p[PLAYERS], Deck deck);

int main (void) 
{
	// Print out initial information about the poker game
	cout << "Number of suits: " << SUITS << endl;
	cout << "Number of ranks: " << RANKS << endl;
	cout << "Number of cards in a deck: " << DECK_SIZE << endl;
	cout << "Number of players: " << PLAYERS << endl;
	cout << "Number of cards per hand: " << HAND_SIZE << "\n" << endl;

	Deck deck = Deck();							// Initialize deck
	deck.Shuffle();								// Shuffle deck
	Player poker_players[PLAYERS];				

	DealCardsToPlayers(poker_players, deck);	// Deals cards to players

	cout << "\n" << endl;
	cout << "BEFORE SORTING PLAYERS: \n" << endl;
	PrintPlayers(poker_players);

	SortPlayers(poker_players);					// Sorts players from worst hand to best hand
				
	cout << "\n" << endl;
	cout << "AFTER SORTING PLAYERS: \n" << endl;
	PrintPlayers(poker_players);

	system( "pause" );
	return 0;
}


// Prints out the cards that the player is currently holding
void PrintHand(Player p) 
{
	int i; 
	cout << "Cards " << ": [";
	for (i = 0; i < HAND_SIZE; i++) { 
			cout << " " << p.GetHand()[i].rank << p.GetHand()[i].suit << " ";
	}
	cout << "]" << endl;
	return;
}


// Prints out the player ID, points, and hand of all the players
void PrintPlayers(Player p[PLAYERS]) 
{
	int k;
	for (k = 0; k < PLAYERS; k++) {
		cout << "Player " << p[k].GetID() << ": " << p[k].GetPoints() << " point(s)." 
			<< endl;
		PrintHand(p[k]);
		cout << endl;
	}
}

// Deal hands and calculate points for each players' hand
void DealCardsToPlayers(Player p[PLAYERS], Deck deck) 
{
	int i, j, points;
	struct card new_hand[HAND_SIZE];

	for (i = 0; i < PLAYERS; i++) {
		p[i] = Player(i);	
		for (j = 0; j < HAND_SIZE; j++) {   
			new_hand[j] = deck.DealCard();
		}
		p[i].SetHand(new_hand);
		points = CalculatePoints(new_hand);  
		p[i].SetPoints(points);  
	}
}