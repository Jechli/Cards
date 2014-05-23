#include "Card.h"

#pragma once
#pragma warning( disable : 4351 ) 

class Player 
{
	int id;
	struct card hand[HAND_SIZE];

public:
	Player(int p_id) : id(p_id), hand() {}
	~Player() {}

	void SetHand(struct card* new_hand);
	int CalculatePoints();
	struct card* GetHand() { return hand; }
};



