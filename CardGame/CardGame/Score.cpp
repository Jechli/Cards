#include "Score.h"

// Scoring system
int CalculatePoints(struct card hand[HAND_SIZE]) {
	
	return 0;
}

// Compare hands: T if hand1 > hand2, else F
bool CompareHands(struct card hand1[HAND_SIZE], struct card hand2[HAND_SIZE]);

// sort players
void SortPlayers(Player players[PLAYERS]);

// helper functions, private

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

// Returns 0 if not triple, otherwise the char of the highest rank
char* Triple(struct card hand[HAND_SIZE]) 
{
	int i, count = 0;
	char* rank = hand[0].rank;
	while (i < HAND_SIZE) {
		if (hand[i-1].rank == hand[i].rank) { 
			count++;
			i++;
		}
		else if ((hand[i-1].rank != hand[i].rank) && count == 3) {
			return rank;
		}
		else {
			rank = hand[i].rank;
			i++;
		}
	}
	if (count == 3) { return rank; }
	else { return "0"; }
}

// same suit?
// pairs?
// sequence?
// royal?
