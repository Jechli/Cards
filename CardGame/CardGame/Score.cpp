#include "Score.h"
#include <stdlib.h>

// helper functions
bool Repeats(struct card hand[HAND_SIZE]);
bool Triple(struct card hand[HAND_SIZE]) ;
bool SameSuit(struct card hand[HAND_SIZE]);
int Pairs(struct card hand[HAND_SIZE]);
bool IsSequence(struct card hand[HAND_SIZE]);
bool IsRoyal(struct card &first_card);
int HighestCard(struct card hand[HAND_SIZE]);
void InsertionSort(struct card hand[HAND_SIZE]);

// Scoring system
int CalculatePoints(struct card hand[HAND_SIZE]) {

	InsertionSort(hand);
	struct card first = hand[0];
	struct card second = hand[1];
	struct card third = hand[2];
	struct card fourth = hand[3];
	struct card fifth = hand[4];
	
	if (Repeats(hand))					// hands with rank repeats
	{
		if (Triple(hand)) 
		{
			if (Pairs(hand) == 1) { return 6; }	// full house
			else { return 3; }					// 3 of kind
		}

		else 
		{
			int pairs = Pairs(hand);
			if (pairs == 1) { return 1; }			// one pair
			else if (pairs == 2) { return 2; }		// two pairs
			else if (pairs == 4) { return 7; }		// 4 of a kind
		}
	}

	else								// hands with no rank repeats
	{
		if (SameSuit(hand)) 
		{
			if (IsSequence(hand)) 
			{
				if (IsRoyal(hand[0])) { return 9; }	// royal
				else { return 8; }					// straight flush
			}
			else { return 5; }						// flush
		}
		else 
		{
			if (IsSequence(hand)) { return 4; }		// straight
			else { return 0; }						// high
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
	for (i = 1; i < HAND_SIZE; i++)		// insertion sort
	{
		points = player[i].GetPoints();
		temp = player[i];
		for (j = i - 1; j >=0 && points <= player[j].GetPoints(); j--)
		{
			if (points == player[j].GetPoints()) {
				if (CompareHands(player[j].GetHand(), temp.GetHand(), points)) { player[j+1] = player[j]; }
			}
			else { player[j+1] = player[j]; }
		}
		player[j+1] = temp;
	}
}

// ---------------------------HELPER FUNCTIONS------------------------------//


// True if hand has more than 1 card of the same rank
bool Repeats(struct card hand[HAND_SIZE]) 
{
	int i = 1;
	while (i < HAND_SIZE) {
		if (hand[i-1].rank == hand[i].rank) { return true; }
		i++;
	}
	return false;
}


// Returns 0 if not triple, otherwise the char of the highest rank of the triple
// can compare middle with side cards
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


// same suit?
bool SameSuit(struct card hand[HAND_SIZE]) 
{
	int i;
	for (i = 1; i < HAND_SIZE; i++) {
		if (hand[i-1].suit != hand[i].suit) { return false; }
	}
	return true;
}


// pairs? 1 = 1 pair, 2 = 2 pairs, 4 = 4 of kind, 0 = no pairs // need to fix this.... =.="
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


// is it a sequence?
bool IsSequence(struct card hand[HAND_SIZE]) 
{
	int i;
	for (i = 1; i < HAND_SIZE; i++) {
		if ((hand[i] - hand[i-1]) != 1) { return false; }
	}
	return true;
}


// royal? This assume sequence and suits are all checked. 
bool IsRoyal(struct card &first_card) 
{
	if (first_card.rank == "10") { return true; }
	else { return false; }
}


// find highest card for one or two pairs
int HighestCard(struct card hand[HAND_SIZE]) 
{
	InsertionSort(hand);
	int i;
	for (i = HAND_SIZE-1; i > 0; i--) {
		if (hand[i].rank == hand[i-1].rank) { return i; }
	}
	return 0; // should not reach this
}

// insertion sort
void InsertionSort(struct card hand[HAND_SIZE])
{
	int i, j;
	struct card temp;
	
	for (i = 1; i < HAND_SIZE; i++)		// insertion sort
	{
		temp = hand[i];
		for (j = i - 1; j >=0 && temp < hand[j]; j--)
		{
			hand[j+1] = hand[j];
		}
		hand[j+1] = temp;
	}
}
