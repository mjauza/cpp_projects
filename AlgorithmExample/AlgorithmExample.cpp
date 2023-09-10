// AlgorithmExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Card.h"
#include <vector>
#include <algorithm>
#include <map>
#include "Hand.h"

void sorting_example();
void duplicates_example();
bool hand_has_duplicate_values(std::vector<Card>& hand);
std::vector<Card> get_duplicated_cards(std::vector<Card>& hand);
std::map<int, std::vector<int>> get_duplicated_idxs(std::vector<Card>& hand);
void get_duplicate_example();
void erase_duplicates_example();
void hand_split_example();

int main()
{
    //sorting_example();
    //duplicates_example();
    //get_duplicate_example();
    //erase_duplicates_example();
    hand_split_example();
    return 0;

}

void hand_split_example()
{
    Card c4 = Card("D", "A");
    Card c3 = Card("D", "K");
    Card c2 = Card("H", "2");
    Card c1 = Card("S", "Q");

    Hand hand = Hand();
    hand.hand.push_back(c1);
    hand.hand.push_back(c2);
    hand.hand.push_back(c3);
    hand.hand.push_back(c4);

    std::vector<Hand> hand_split = Hand::split_hand( hand, 10);
    int i = 1;
    for (Hand h : hand_split) {
        std::cout << "Hand " << i << ":" << std::endl;
        h.print_hand();
        i++;
    }

}


void sorting_example()
{
    Card c4 = Card("D", "A");
    Card c3 = Card("D", "K");
    Card c2 = Card("H", "2");
    Card c1 = Card("S", "Q");

    std::vector<Card> hand{ c1, c2, c3, c4 };
    std::cout << "Hand before sorting: " << std::endl;
    for (Card c : hand) {
        std::cout << c.to_string() << std::endl;
    }

    std::sort(hand.begin(), hand.end(), Card::compare_by_value);

    std::cout << "Hand after sorting: " << std::endl;
    for (Card c : hand) {
        std::cout << c.to_string() << std::endl;
    }
}

void duplicates_example()
{
    Card c4 = Card("D", "A");
    Card c3 = Card("D", "K");
    Card c2 = Card("H", "K");
    Card c1 = Card("S", "Q");

    std::vector<Card> hand1{ c1, c2, c3, c4 };
    bool has_dup1 = hand_has_duplicate_values(hand1);


    c4 = Card("D", "2");
    c3 = Card("D", "3");
    c2 = Card("H", "4");
    c1 = Card("S", "5");

    std::vector<Card> hand2{ c1, c2, c3, c4 };
    bool has_dup2 = hand_has_duplicate_values(hand2);

    std::cout << "Hand1 has duplicates: " << has_dup1 << std::endl;
    std::cout << "Hand2 has duplicates: " << has_dup2 << std::endl;
}

void get_duplicate_example()
{
    Card c4 = Card("D", "A");
    Card c3 = Card("D", "K");
    Card c2 = Card("H", "K");
    Card c1 = Card("S", "Q");

    std::vector<Card> hand1{ c1, c2, c3, c4 };

    std::vector<Card> hand1_dup = get_duplicated_cards(hand1);

    std::cout << "Duplicates for hand1: " << std::endl;
    for (Card& c : hand1_dup) {
        std::cout << c.to_string() << std::endl;
    }

    c4 = Card("D", "2");
    c3 = Card("D", "3");
    c2 = Card("H", "4");
    c1 = Card("S", "5");

    std::vector<Card> hand2{ c1, c2, c3, c4 };

    std::vector<Card> hand2_dup = get_duplicated_cards(hand2);

    std::cout << "Duplicates for hand2: " << std::endl;
    for (Card& c : hand2_dup) {
        std::cout << c.to_string() << std::endl;
    }
}

bool hand_has_duplicate_values(std::vector<Card>& hand)
{
    std::sort(hand.begin(), hand.end(), Card::compare_by_value);
    return std::adjacent_find(hand.begin(), hand.end(), Card::same_value) != hand.end();
}

std::vector<Card> get_duplicated_cards(std::vector<Card>& hand)
{
    std::vector<Card> duplicates;
    std::map<int, int> m_value_count;
    std::map<int, Card> first_app;

    for (const Card& c : hand)
    {   
        int card_value = c.get_num_value();
        ++m_value_count[card_value];

        if (m_value_count[card_value] == 1) {
            first_app[card_value] = c;
        }
        
        if (m_value_count[card_value] > 1) {
            duplicates.push_back(c);
        }        
    }

    
    std::map<int, int>::iterator it;
    for (it = m_value_count.begin(); it != m_value_count.end(); it++) {
        int card_value = it->first;
        int count = it->second;
        if( count > 1){
            Card& f = first_app[card_value];
            duplicates.push_back(f);
        }
    }
    
    return duplicates;
}

std::map<int, std::vector<int>> get_duplicated_idxs(std::vector<Card>& hand)
{
    std::map<int, std::vector<int>> res;
    
    std::vector<int> duplicates;
    std::map<int, int> m_value_count;
    std::map<int, int> first_app;

    for (int i = 0; i < hand.size(); i++) {
        Card c = hand.at(i);
        int card_value = c.get_num_value();
        ++m_value_count[card_value];
        if (m_value_count[card_value] == 1) {
            first_app[card_value] = i;
        }

        if (m_value_count[card_value] > 1) {
            res[card_value].push_back(i);
            /*
            if (res.find(card_value) == res.end()) {
                res[card_value] = {};
                res[card_value].push_back(i);
            }
            else {
                res[card_value].push_back(i);
            }
            */
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

void erase_duplicates_example()
{
    Card c4 = Card("D", "A");
    Card c3 = Card("D", "K");
    Card c2 = Card("H", "K");
    Card c1 = Card("S", "Q");
    Card c0 = Card("S", "A");

    std::vector<Card> hand1{c0, c1, c2, c3, c4 };

    std::cout << "Hand before erasing" << std::endl;
    for (Card c : hand1) {
        std::cout << c.to_string() << std::endl;
    }

    std::map<int, std::vector<int>> dup_map = get_duplicated_idxs(hand1);


    std::vector<int> idxs_to_erase;
    std::map<int, std::vector<int>>::iterator it;
    for (it = dup_map.begin(); it != dup_map.end(); it++) {
        int card_value = it->first;
        std::vector<int> dup_idxs = it->second;
        for (int i = 1; i < dup_idxs.size(); i++) {
            idxs_to_erase.push_back(dup_idxs.at(i));
        }        
    }

    std::sort(idxs_to_erase.begin(), idxs_to_erase.end());
    for (int i = idxs_to_erase.size() - 1; i >= 0; i--) {
        int idx_to_erase = idxs_to_erase.at(i);
        hand1[idx_to_erase] = hand1.back();
        hand1.pop_back();
    }

    std::cout << "Hand after erasing" << std::endl;
    for (Card c : hand1) {
        std::cout << c.to_string() << std::endl;
    }

}