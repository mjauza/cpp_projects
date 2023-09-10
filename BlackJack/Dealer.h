#pragma once
#include "Card.h"
#include <vector>
#include "Hand.h"
class Dealer
{
	public:
		Dealer();
		void add_card(Card c);
		//int get_visible_hand_value();
		//void set_card_visible(int i);
	
		Hand hand;
		//std::vector<bool> card_visibility;
};

