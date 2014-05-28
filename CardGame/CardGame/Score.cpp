#include "Score.h"
#include <stdlib.h>

// Private helper functions 
bool Repeats(struct card hand[HAND_SIZE]);			
bool Triple(struct card hand[HAND_SIZE]) ;			
bool SameSuit(struct card hand[HAND_SIZE]);			
int Pairs(struct card hand[HAND_SIZE]);								
bool IsSequence(struct card hand[HAND_SIZE]);		
bool IsRoyal(struct card &first_card);				
int HighestCard(struct card hand[HAND_SIZE]);		
void InsertionSort(struct card hand[HAND_SIZE]);	


// -----------------------PUBLIC FUNCTIONS------------------------------//


// Scoring system: calculates points for a given hand
int CalculatePoints(struct card hand[HAND_SIZE]) {

	InsertionSort(hand);
	struct card first = hand[0];
	struct card second = hand[1];
	struct card third = hand[2];
	struct card fourth = hand[3];
	struct card fifth = hand[4];
	
	if (Repeats(hand))									// Check hand for cards with repeated ranks
	{
		if (Triple(hand))								// Check if it contains 3 of a kind
		{
			if (Pairs(hand) == 1) { return 6; }			// FULL HOUSE
			else { return 3; }							// 3 OF A KIND
		}

		else 
		{
			int pairs = Pairs(hand);					// Check for pairs
			if (pairs == 1) { return 1; }				// ONE PAIR
			else if (pairs == 2) { return 2; }			// TWO PAIRS
			else if (pairs == 4) { return 7; }			// 4 OF A KIND
		}
	}

	else												// Hands without repeated ranks
	{
		if (SameSuit(hand))								// Check if all cards have the same suit
		{
			if (IsSequence(hand))						// Check if hand is a straight
			{
				if (IsRoyal(hand[0])) { return 9; }		// ROYAL FLUSH
				else { return 8; }						// STRAIGHT FLUSH
			}
			else { return 5; }							// FLUSH
		}
		else 
		{
			if (IsSequence(hand)) { return 4; }			// STRAIGHT
			else { return 0; }							// HIGH CARD
		}
	} 

	return 0;
}


// Compare hands: T if hand1 > hand2, else F
bool CompareHands(struct card hand1[HAND_SIZE], struct card hand2[HAND_SIZE], int points)
{
	InsertionSort(hand1);
	InsertionSort(hand2);
	if (points == 1 || points == 2) { 
		// one pair, two pairs
		return hand2[HighestCard(hand2)] < hand1[HighestCard(hand1)];
	}
	else if (points == 3 || points == 6 || points == 7) {                // 3 of kind, full house, 4 of kind
		return hand2[2] < hand1[2];					                     // middle card has to be part of the triple or quadruple
	}	
	else {                                                               // straight flush, straight, flush, high card, royal
		return (hand2[HAND_SIZE-1] < hand1[HAND_SIZE-1]);
	}
}


// sort players
void SortPlayers(Player player[PLAYERS])  // insertion sort
{
	int i, j, points;
	Player temp;
	for (i = 1; i < PLAYERS; i++)		// insertion sort
	{
		points = player[i].GetPoints();
		temp = player[i];
		for (j = i - 1; j >=0 && points <= player[j].GetPoints(); j--)
		{
			if (points == player[j].GetPoints()) {
				if (CompareHands(player[j].GetHand(), temp.GetHand(), points)) { player[j+1] = player[j]; }
				else { break; }
			}
			else { player[j+1] = player[j]; }
		}
		player[j+1] = temp;
	}
}


// -----------------------PRIVATE HELPER FUNCTIONS------------------------------//


// Returns true if hand holds multiple cards of a rank
bool Repeats(struct card hand[HAND_SIZE]) 
{
	int i = 1;
	while (i < HAND_SIZE) {
		if (hand[i-1].rank == hand[i].rank) { return true; }
		i++;
	}
	return false;
}


// Returns true if hand holds 3 cards of a rank
bool Triple(struct card hand[HAND_SIZE]) 
{
	char* middle_rank = hand[2].rank; // middle card
	// left
	if (middle_rank == hand[1].rank) {
		if (middle_rank == hand[3].rank && (middle_rank != hand[4].rank && middle_rank != hand[0].rank)) { 
			return true;
		}
		else if (middle_rank == hand[0].rank && middle_rank != hand[3].rank) { return true; }
		else { return false; }
	}
	// right
	else if (middle_rank == hand[3].rank) {
		if (middle_rank == hand[1].rank && (middle_rank != hand[4].rank && middle_rank != hand[0].rank)) { 
			return true;
		}
		else if (middle_rank == hand[4].rank && middle_rank != hand[1].rank) { return true; }
		else { return false; }
	}
	// neither
	else { return false; }
}


// Returns true if all cards in hand have the same suit
bool SameSuit(struct card hand[HAND_SIZE]) 
{
	int i;
	for (i = 1; i < HAND_SIZE; i++) {
		if (hand[i-1].suit != hand[i].suit) { return false; }
	}
	return true;
}


// If hand contains one pair: return 1
//					two pairs: return 2
//					four of a kind: return 4
int Pairs(struct card hand[HAND_SIZE]) 
{
	int i, count = 0, values = 0;
	char* current_rank = hand[0].rank;
	for (i = 1; i < HAND_SIZE; i++) {
		if (hand[i-1].rank == hand[i].rank) {
			if (hand[i].rank != current_rank) { 
				current_rank = hand[i].rank;
				values++;
				count+=2;
			}
			else if (count == 0) { count+=2; values++; }
			else { count++; }
		}
		else {
			if (count == 3) { count = 0; values--;}
		}
	}
	if (values < 1) { values = 1; }
	if (count == 2) { return 1; }
	else { return (count / values); }

}


// Returns true if hand contains a straight
bool IsSequence(struct card hand[HAND_SIZE]) 
{
	int i;
	for (i = 1; i < HAND_SIZE; i++) {
		if ((hand[i] - hand[i-1]) != 1) { return false; }
	}
	return true;
}


// Returns true if hand is a royal flush. 
// This assumes that a straight and flush is true for the hand. 
bool IsRoyal(struct card &first_card) 
{
	if (first_card.rank == "10") { return true; }
	else { return false; }
}


// Returns the index in the hand of the highest card ranking for pairs.
int HighestCard(struct card hand[HAND_SIZE]) 
{
	InsertionSort(hand);
	int i;
	for (i = HAND_SIZE-1; i > 0; i--) {
		if (hand[i].rank == hand[i-1].rank) { return i; }
	}
	return 0; // should not reach this
}


// Sorts the cards of a hand in order from smallest to largest ranking using insertion sort
void InsertionSort(struct card hand[HAND_SIZE])
{
	int i, j;
	struct card temp;
	
	for (i = 1; i < HAND_SIZE; i++)		
	{
		temp = hand[i];
		for (j = i - 1; j >=0 && temp < hand[j]; j--)
		{
			hand[j+1] = hand[j];
		}
		hand[j+1] = temp;
	}
}