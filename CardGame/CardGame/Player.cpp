#include "Player.h"
#include "Cards.h"

void Player::SortHand() {

}

void Player::SetHand(struct card* new_hand)
{
	int i;
	for (i = 0; i < HAND_SIZE; i++) {
		hand[i] = *(new_hand+i);
	}
	return;
}

