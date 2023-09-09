#include "Deck.h"
#include "Card.h"
#include <map>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
Deck::Deck()
{

}

void Deck::set_deck_for_bj()
{	
	// get un mixed deck
	std::vector<Card> deck =  get_bj_card_deck();
	// mix deck;
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(deck), std::end(deck), rng);
	// assign
	this->deck = deck;
}

void Deck::shuffle_deck()
{
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(this->deck), std::end(this->deck), rng);
}

Card Deck::pull_card()
{
	Card c = this->deck.back();
	this->deck.pop_back();
	return c;
}

std::vector<Card> Deck::get_bj_card_deck()
{
	std::vector<Card> res;
	std::map<std::string, int>::iterator it_value;

	for (it_value = Card::bj_value_mapper.begin(); it_value != Card::bj_value_mapper.end(); it_value++) {
		std::string value = it_value->first;
		Card c1 = Card(Card::colors.cross, value);
		Card c2 = Card(Card::colors.diamond, value);
		Card c3 = Card(Card::colors.heart, value);
		Card c4 = Card(Card::colors.spade, value);
		res.push_back(c1);
		res.push_back(c2);
		res.push_back(c3);
		res.push_back(c4);
	}
	return res;
}