#include "Cards.h"

#pragma once
#pragma warning( disable : 4351 ) 

class Player 
{
private:

	int id;
	struct card hand[HAND_SIZE];
	int points;
	//char* highest_rank; // just added

	void SortHand();		
	void Swap(int i, int j); // helper function for SortHand()

public:

	Player(int p_id) : id(p_id), hand(), points(0) {}
	~Player() {}
	void SetHand(struct card new_hand[HAND_SIZE]);
	struct card* GetHand() { return hand; }
	int GetPoints() { return points; }
	int GetID() { return id; }
	//void SetHighestRank(char* rank); // implement
};



