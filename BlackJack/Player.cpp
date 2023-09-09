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

/*
std::tuple<Hand, Hand> get_splited_hands(Hand h)
{

}
*/