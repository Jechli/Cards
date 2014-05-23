#include "Player.h"
#include "Card.h"

void Player::SetHand(struct card* new_hand)
{
	int i;
	for (i = 0; i < HAND_SIZE; i++) {
		hand[i] = *(new_hand+i);
	}
	return;
}

int Player::CalculatePoints()
{
	return 0;
}
