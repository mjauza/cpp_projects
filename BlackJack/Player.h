#pragma once
#include <string>
#include "Card.h"
#include <vector>
#include "Hand.h"
#include <tuple>
class Player
{
	public:
		Player();
		Player(std::string name);
		void add_card(Card c, int hand_int);
		void split_hand(int hand_int, int card_value_to_split);
		
		//void double_down();
		

	
		std::vector<Hand> hands;		
		std::string name;

};

