#include "Cards.h"
#include "Player.h"

#pragma once

// Scoring system
int CalculatePoints(struct card hand[HAND_SIZE]);

// Compare hands: T if hand1 > hand2, else F
bool CompareHands(struct card hand1[HAND_SIZE], struct card hand2[HAND_SIZE], int points);

// sort players
void SortPlayers(Player players[PLAYERS]);