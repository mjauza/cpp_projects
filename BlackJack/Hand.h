#pragma once
#include "Card.h"
#include <vector>
#include <tuple>
#include <set>
class Hand
{
public:
	Hand();
	void add_card(Card c);
	int get_hand_value();
	bool can_i_split(Card split_card);
	std::tuple<Hand, Hand> get_splited_hands(Card split_card);
	template<typename T>
	static std::set<T> findDuplicates(std::vector<T> vec);
private:
	std::vector<Card> hand;
	
};

template<typename T>
std::set<T> Hand::findDuplicates(std::vector<T> vec)        // no-ref, no-const
{
	std::set<int> duplicates;
	std::sort(vec.begin(), vec.end());
	std::set<int> distinct(vec.begin(), vec.end());
	std::set_difference(vec.begin(), vec.end(), distinct.begin(), distinct.end(),
		std::inserter(duplicates, duplicates.end()));
	return duplicates;
}