#include "Card.h"

#ifndef PLAYER_H
#define PLAYER_H
#define MAX_HAND 5

class Player 
{
private:
	int id;
	struct card hand[MAX_HAND];

public:
	Player(int p_id);
	void SetHand(struct card* new_hand);
	int CalculatePoints();
	struct card* GetHand() { return hand; }
};

#endif