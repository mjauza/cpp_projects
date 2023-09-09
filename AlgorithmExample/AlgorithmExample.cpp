// AlgorithmExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Card.h"
#include <vector>
#include <algorithm>
#include <map>

void sorting_example();
void duplicates_example();
bool hand_has_duplicate_values(std::vector<Card>& hand);
std::vector<Card> get_duplicated_cards(std::vector<Card>& hand);
void get_duplicate_example();

int main()
{
    //sorting_example();
    //duplicates_example();
    get_duplicate_example();
    return 0;

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