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
		void split_hand();
		
		void double_down();
		

	private:
		std::vector<Hand> hands;		
		std::string name;

};

