#include "Hand.h"
#include <iostream>

Hand::Hand()
{

}

void Hand::print_hand()
{
	for (Card c : this->hand) {
		std::cout << c.to_string() << std::endl;
	}
}

std::vector<Hand> Hand::split_hand(Hand& hand, int card_value_to_split)
{
    std::vector<Hand> res;
    bool can_I_split = can_split(hand, card_value_to_split);
    if(!can_I_split){
        return res;
    }
    std::map<int, std::vector<int>> duplicate_map = get_duplicated_idxs(hand);
    std::vector<int> dup_idxs = duplicate_map[card_value_to_split];
    int idx_to_move_1 = dup_idxs.at(0);
    Card card_move_to_1 = hand.hand.at(idx_to_move_1);
    Hand new_hand1;
    new_hand1.hand.push_back(card_move_to_1);
    Hand new_hand2;
    for (int i = 0; i < hand.hand.size(); i++) {
        if (i == idx_to_move_1) {
            continue;
        }
        Card c_to_move = hand.hand.at(i);
        new_hand2.hand.push_back(c_to_move);
    }

    res.push_back(new_hand1);
    res.push_back(new_hand2);
    return res;
}


std::map<int, std::vector<int>> Hand::get_duplicated_idxs(Hand& hand)
{
    std::map<int, std::vector<int>> res;

    std::vector<int> duplicates;
    std::map<int, int> m_value_count;
    std::map<int, int> first_app;

    for (int i = 0; i < hand.hand.size(); i++) {
        Card c = hand.hand.at(i);
        int card_value = c.get_num_value();
        ++m_value_count[card_value];
        if (m_value_count[card_value] == 1) {
            first_app[card_value] = i;
        }

        if (m_value_count[card_value] > 1) {
            res[card_value].push_back(i);
        }
    }

    std::map<int, int>::iterator it;
    for (it = m_value_count.begin(); it != m_value_count.end(); it++) {
        int card_value = it->first;
        int count = it->second;
        if (count > 1) {
            int idx = first_app[card_value];
            res[card_value].insert(res[card_value].begin(), idx);
        }
    }

    return res;
}


bool Hand::can_split(Hand& hand, int card_value_to_split)
{
    std::map<int, std::vector<int>> duplicate_map = get_duplicated_idxs(hand);
    if (duplicate_map.find(card_value_to_split) == duplicate_map.end()) {
        return false;
    }
    return true;
}