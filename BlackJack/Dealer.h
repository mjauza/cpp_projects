#pragma once
#include "Card.h"
#include <vector>
class Dealer
{
	public:
		Dealer();
		void add_card(Card c, bool is_visible);
		int get_visible_hand_value();
		void set_card_visible(int i);
	private:
		std::vector<Card> hand;
		std::vector<bool> card_visibility;
};

