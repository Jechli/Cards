#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "CppUnitTest.h"
#include "Player.h"
#include "Deck.h"
#include "Score.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	// Create cards to use
	struct card ONE;
	struct card TWO;
	struct card THREE;
	struct card FOUR;
	struct card FIVE;
	struct card hand[HAND_SIZE];


	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Score_for_Royal_Flush)
		{
			 ONE.rank = "A"; ONE.suit = "H";
			 TWO.rank = "K"; TWO.suit = "H";
			 THREE.rank = "Q"; THREE.suit = "H";
			 FOUR.rank = "J"; FOUR.suit = "H";
			 FIVE.rank = "10"; FIVE.suit = "H";
			 hand[0] = ONE; hand[1] = TWO; hand[2] = THREE; hand[3] = FOUR; hand[4] = FIVE;
			 Assert::AreEqual(CalculatePoints(hand), 9);
		}

		TEST_METHOD(Score_for_Straight_Flush)
		{
			 ONE.rank = "J"; ONE.suit = "S";
			 TWO.rank = "10"; TWO.suit = "S";
			 THREE.rank = "9"; THREE.suit = "S";
			 FOUR.rank = "8"; FOUR.suit = "S";
			 FIVE.rank = "7"; FIVE.suit = "S";
			 hand[0] = ONE; hand[1] = TWO; hand[2] = THREE; hand[3] = FOUR; hand[4] = FIVE;
			 Assert::AreEqual(CalculatePoints(hand), 8);
		}

		TEST_METHOD(Score_for_Four_of_a_Kind)
		{
			 ONE.rank = "5"; ONE.suit = "S";
			 TWO.rank = "5"; TWO.suit = "H";
			 THREE.rank = "5"; THREE.suit = "D";
			 FOUR.rank = "5"; FOUR.suit = "C";
			 FIVE.rank = "2"; FIVE.suit = "S";
			 hand[0] = ONE; hand[1] = TWO; hand[2] = THREE; hand[3] = FOUR; hand[4] = FIVE;
			 Assert::AreEqual(CalculatePoints(hand), 7);
		}

		TEST_METHOD(Score_for_Full_House)
		{
			 ONE.rank = "K"; ONE.suit = "S";
			 TWO.rank = "K"; TWO.suit = "H";
			 THREE.rank = "K"; THREE.suit = "C";
			 FOUR.rank = "3"; FOUR.suit = "C";
			 FIVE.rank = "3"; FIVE.suit = "D";
			 hand[0] = ONE; hand[1] = TWO; hand[2] = THREE; hand[3] = FOUR; hand[4] = FIVE;
			 Assert::AreEqual(CalculatePoints(hand), 6);
		}

		TEST_METHOD(Score_for_Flush)
		{
			 ONE.rank = "A"; ONE.suit = "C";
			 TWO.rank = "3"; TWO.suit = "C";
			 THREE.rank = "7"; THREE.suit = "C";
			 FOUR.rank = "8"; FOUR.suit = "C";
			 FIVE.rank = "Q"; FIVE.suit = "C";
			 hand[0] = ONE; hand[1] = TWO; hand[2] = THREE; hand[3] = FOUR; hand[4] = FIVE;
			 Assert::AreEqual(CalculatePoints(hand), 5);
		}

		TEST_METHOD(Score_for_Straight)
		{
			 ONE.rank = "8"; ONE.suit = "S";
			 TWO.rank = "6"; TWO.suit = "H";
			 THREE.rank = "7"; THREE.suit = "C";
			 FOUR.rank = "5"; FOUR.suit = "D";
			 FIVE.rank = "9"; FIVE.suit = "C";
			 hand[0] = ONE; hand[1] = TWO; hand[2] = THREE; hand[3] = FOUR; hand[4] = FIVE;
			 Assert::AreEqual(CalculatePoints(hand), 4);
		}

		TEST_METHOD(Score_for_Three_of_a_Kind)
		{
			 ONE.rank = "8"; ONE.suit = "S";
			 TWO.rank = "6"; TWO.suit = "H";
			 THREE.rank = "8"; THREE.suit = "C";
			 FOUR.rank = "8"; FOUR.suit = "H";
			 FIVE.rank = "9"; FIVE.suit = "D";
			 hand[0] = ONE; hand[1] = TWO; hand[2] = THREE; hand[3] = FOUR; hand[4] = FIVE;
			 Assert::AreEqual(CalculatePoints(hand), 3);
		}

		TEST_METHOD(Score_for_Two_Pairs)
		{
			 ONE.rank = "5"; ONE.suit = "S";
			 TWO.rank = "A"; TWO.suit = "H";
			 THREE.rank = "A"; THREE.suit = "D";
			 FOUR.rank = "3"; FOUR.suit = "S";
			 FIVE.rank = "5"; FIVE.suit = "H";
			 hand[0] = ONE; hand[1] = TWO; hand[2] = THREE; hand[3] = FOUR; hand[4] = FIVE;
			 Assert::AreEqual(CalculatePoints(hand), 2);
		}

		TEST_METHOD(Score_for_One_Pair)
		{
			 ONE.rank = "7"; ONE.suit = "S";
			 TWO.rank = "A"; TWO.suit = "C";
			 THREE.rank = "Q"; THREE.suit = "H";
			 FOUR.rank = "7"; FOUR.suit = "C";
			 FIVE.rank = "5"; FIVE.suit = "H";
			 hand[0] = ONE; hand[1] = TWO; hand[2] = THREE; hand[3] = FOUR; hand[4] = FIVE;
			 Assert::AreEqual(CalculatePoints(hand), 1);
		}

		TEST_METHOD(Score_for_High_Card)
		{
			 ONE.rank = "7"; ONE.suit = "S";
			 TWO.rank = "3"; TWO.suit = "C";
			 THREE.rank = "8"; THREE.suit = "S";
			 FOUR.rank = "Q"; FOUR.suit = "D";
			 FIVE.rank = "A"; FIVE.suit = "H";
			 hand[0] = ONE; hand[1] = TWO; hand[2] = THREE; hand[3] = FOUR; hand[4] = FIVE;
			 Assert::AreEqual(CalculatePoints(hand), 0);
		}

	};
}