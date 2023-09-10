#pragma once
#include "Card.h"
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
#include <iterator>
class Hand
{
public:
	Hand();
	void add_card(Card c);
	int get_hand_value();
	static bool can_split(Hand& hand, int card_value_to_split);
	static std::vector<Hand> split_hand(Hand& hand, int card_value_to_split);
	static std::map<int, std::vector<int>> get_duplicated_idxs(Hand& hand);
	template<typename T>
	static std::set<T> findDuplicates(std::vector<T> vec);
	void print_hand();
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