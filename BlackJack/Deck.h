#pragma once
#include "Card.h"
#include <queue>
#include <vector>
class Deck
{
	public:
		Deck();
		void set_deck_for_bj();
		void shuffle_deck();
		Card pull_card();
		 
	private:
		std::vector<Card> deck;
		static std::vector<Card> get_bj_card_deck();

};

