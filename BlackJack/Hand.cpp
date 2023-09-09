#include "Hand.h"
#include <string>
#include < cassert >
#include <set>
#include <algorithm>
#include <vector>

Hand::Hand()
{

}

void Hand::add_card(Card c)
{
	this->hand.push_back(c);
}

int Hand::get_hand_value()
{
	
	int num_aces = 0;
	int hand_value = 0;
	for (Card c : this->hand) {
		std::string value = c.get_value();
		int num_value = Card::bj_value_mapper[value];
		hand_value += num_value;
		// note ace
		if (num_value == 1) {
			num_aces++;
		}
	}
	// handle excess aces
	if (num_aces > 0) {
		while ((hand_value > 21) && (num_aces > 0)) {
			hand_value -= 10;
			num_aces--;
		}
	}
	assert(hand_value > 0);
	return hand_value;
}


std::tuple<Hand, Hand> Hand::get_splited_hands(Card split_card)
{
	// get duplicates from hand
	// check if split card is in duplcates

	// create 2 new hands
	// copy all elemtns of current hand into one of new ones 
	// remove 1 of split cards from new hand
	// add split card to empty second hand.
}

bool Hand::can_i_split(Card split_card)
{
	std::set<Card> duplicates = Hand::findDuplicates<Card>(this->hand);
	for (Card c : duplicates) {
		if (c.get_value() == split_card.get_value()) {
			return true;
		}
	}
	return true;
}
