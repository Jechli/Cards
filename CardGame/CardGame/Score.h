#include "Cards.h"
#include "Player.h"

#pragma once

// Scoring system: calculates points for a given hand's value
int CalculatePoints(struct card hand[HAND_SIZE]);


// Compare hands if their values are the same.
// Returns true if hand1 > hand2
bool CompareHands(struct card hand1[HAND_SIZE], struct card hand2[HAND_SIZE], int points);


// Sort players' rankings from lowest to highest using insertion sort
void SortPlayers(Player player[PLAYERS]);