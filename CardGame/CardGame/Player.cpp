#include "Player.h"
#include "Cards.h"
// Private functions 

void Player::SortHand() 
{
	int i, j = 0;
	
	for (i = 1; i < HAND_SIZE; i++)		// insertion sort
	{
		while (j < i) 
		{
			if (hand[i] < hand[j]) 
			{ 
				Swap(i, j); 
			}
			j++;
		}
		j = 0;
	}
}

// Private helper function

void Player::Swap(int i, int j)
{
	struct card temp = hand[i];
	hand[i] = hand[j];
	hand[j] = temp;
	return;
}

// Public Functions

void Player::SetHand(struct card new_hand[HAND_SIZE])
{
	int i;
	for (i = 0; i < HAND_SIZE; i++) {
		hand[i] = new_hand[i];
	}
	SortHand();
	return;
}

