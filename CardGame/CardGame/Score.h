#include "Cards.h"
#include "Player.h"

#pragma once

// Scoring system
int CalculatePoints(struct card hand[HAND_SIZE]);

// Compare hands: T if hand1 > hand2, else F
bool CompareHands(struct card &hand1, struct card &hand2);

// sort players
void SortPlayers(Player players[PLAYERS]);