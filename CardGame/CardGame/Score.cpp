#include "Score.h"
#include <stdlib.h>

// Scoring system
int CalculatePoints(struct card hand[HAND_SIZE]) {
	
	return 0;
}

// Compare hands: T if hand1 > hand2, else F
bool CompareHands(struct card hand1[HAND_SIZE], struct card hand2[HAND_SIZE]);

// sort players
void SortPlayers(Player players[PLAYERS]);


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
bool Triple(struct card hand[HAND_SIZE]) 
{
	int i, count = 0;

	for (i = 1; i < HAND_SIZE; i++) {
		if (hand[i-1].rank == hand[i].rank) { 
			count++;
			i++;
		}
		else if ((hand[i-1].rank != hand[i].rank) && count == 3) {
			return true;
		}
		else {
			count = 0;
			i++;
		}
	}

	if (count == 3) { return true; }
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


// pairs? 1 = 1 pair, 2 = 2 pairs, 4 = 4 of kind, 0 = no pairs
int Pairs(struct card hand[HAND_SIZE]) 
{
	int i, count = 0, values = 0;
	char* current_rank = hand[0].rank;
	for (i = 1; i < HAND_SIZE; i++) {
		if (hand[i-1].rank == hand[i].rank) {
			if (hand[i].rank != current_rank) { 
				current_rank = hand[i].rank;
				values++;
			}
			if (count == 0) { count+=2; values++; }
			else { count++; }
		}
	}
	free(current_rank);
	return (count / values);

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
