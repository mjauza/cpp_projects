#pragma once
#include <vector>
#include "Card.h"
class Hand
{
public:
	Hand();
	std::vector<Card> hand;
	void print_hand();
	static std::vector<Hand> split_hand(Hand& hand, int card_value_to_split);
	static bool can_split(Hand& hand, int card_value_to_split);
	static std::map<int, std::vector<int>> get_duplicated_idxs(Hand& hand);
};

