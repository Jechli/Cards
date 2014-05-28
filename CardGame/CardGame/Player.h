#include "Cards.h"

#pragma once
#pragma warning( disable : 4351 ) 

class Player 
{
private:

	int id;
	struct card hand[HAND_SIZE];
	int points;

	void SortHand();		// Sort player's hand in order from lowest rank to highest rank	
	

public:

	Player() {}
	Player(int p_id) : id(p_id), hand(), points(0) {}
	~Player() {}
	struct card* GetHand() { return hand; }  
	void SetHand(struct card new_hand[HAND_SIZE]);
	int GetPoints() { return points; }	
	void SetPoints(int i) { points = i; }
	int GetID() { return id; }	
};



