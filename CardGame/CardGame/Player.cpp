#include "Player.h"
#include "Cards.h"

// PRIVATE 

void Player::SortHand() 
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


// PUBLIC

void Player::SetHand(struct card new_hand[HAND_SIZE])
{
	int i;
	for (i = 0; i < HAND_SIZE; i++) {
		hand[i] = new_hand[i];
	}
	SortHand();
	return;
}

