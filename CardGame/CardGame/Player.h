#include "Card.h"

#pragma once

class Player 
{
private:
	int id;
	struct card hand[HAND_SIZE];

public:
	Player(int p_id);
	~Player();
	void SetHand(struct card* new_hand);
	int CalculatePoints();
	struct card* GetHand() { return hand; }
};



