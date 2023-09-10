#include "Player.h"
#include <string>
#include <cassert>

Player::Player()
{
	Hand h = Hand();
	this->hands.push_back(h);
}

Player::Player(std::string name)
{
	this->name = name;
	Hand h = Hand();
	this->hands.push_back(h);
}

void Player::add_card(Card c, int hand_int)
{
	assert(hand_int < this->hands.size());
	this->hands.at(hand_int).add_card(c);
}

void Player::split_hand(int hand_int, int card_value_to_split)
{
	if (hand_int >= this->hands.size()) {
		return;
	}
	Hand& hand = this->hands.at(hand_int);
	bool can_split = Hand::can_split(hand, card_value_to_split);

	if (!can_split) {
		return;
	}
	
	std::vector<Hand> splited_hands = Hand::split_hand(hand, card_value_to_split);

	this->hands.erase(this->hands.begin() + hand_int);
	for (Hand& h : splited_hands) {
		this->hands.push_back(h);
	}	
}