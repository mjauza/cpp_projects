#include "BJGame.h"
#include <iostream>
#include <map>
#include <string>
#include <map>

BJGame::BJGame(std::string player_name)
{
	this->player = Player(player_name);
	this->deck = Deck();
	this->deck.set_deck_for_bj();
	this->dealer = Dealer();
}

void BJGame::initial_card_dealing() {
	Card p1 = this->deck.pull_card();
	Card p2 = this->deck.pull_card();
	this->player.add_card(p1, 0);
	this->player.add_card(p2, 0);

	Card d1 = this->deck.pull_card();
	Card d2 = this->deck.pull_card();
	this->dealer.add_card(d1);
	this->dealer.add_card(d2);
}

void BJGame::player_make_move(int action_type, int hand_int)
{
	if (action_type == this->actions.hit) {
		Card c = this->deck.pull_card();
		this->player.add_card(c, hand_int);
	}
}

void BJGame::handle_dealer()
{
	int hand_value = this->dealer.hand.get_hand_value();
	while (hand_value < 17) {
		Card c = this->deck.pull_card();
		this->dealer.add_card(c);
		hand_value = this->dealer.hand.get_hand_value();
	}
}

int BJGame::get_action_from_player(int hand_int, std::map<int, int> possible_actions)
{
	int possible_action = possible_actions[hand_int];
	if (possible_action == this->actions.check) {
		return this->actions.check;
	}
	int action = -12;
	while ((action != this->actions.check) && (action != this->actions.hit)) {
		std::cout << "Possible actions: " << std::endl;
		std::cout << this->actions.hit << " - hit " << std::endl;
		std::cout << this->actions.check << " - check " << std::endl;
		std::cout << "Player input your action" << std::endl;
		std::cin >> action;
	}
	return action;
}

int BJGame::get_hand_int_from_player()
{
	int hand_int = -2;
	int max_avalible_hand = this->player.hands.size() - 1;
	while (!((hand_int >= 0) && (hand_int <= max_avalible_hand))) {
		std::cout << "Possible hands: " << std::endl;
		for (int i = 0; i <= max_avalible_hand; i++) {
			std::cout << i << ";";
		}
		std::cout << std::endl;
		std::cout << "PLease input hand to apply action to" << std::endl;
		std::cin >> hand_int;
	}
	return hand_int;
}


std::map<std::string, std::vector<int>> BJGame::check_winner()
{
	std::vector<int> hand_values;
	for(Hand& h : this->player.hands){
		int hand_value = h.get_hand_value();
		hand_values.push_back(hand_value);
	}
	
	int dealer_value = this->dealer.hand.get_hand_value();
	std::vector<int> draw_idxs;
	std::vector<int> plyer_win_idxs;
	std::vector<int> plyer_loss_idxs;
	for (int i = 0; i < hand_values.size(); i++) {
		int player_value = hand_values.at(i);
		if (player_value <= 21) {
			if ((player_value == 21) && (dealer_value == 21)) {
				draw_idxs.push_back(i);
			}
			else if ((player_value > dealer_value) && (dealer_value <= 21)) {
				plyer_win_idxs.push_back(i);
			}
			else if (dealer_value > 21) {
				plyer_win_idxs.push_back(i);
			}
			else {
				plyer_loss_idxs.push_back(i);
			}
		}
		else {
			plyer_loss_idxs.push_back(i);
		}
	}

	std::map<std::string, std::vector<int>> res;
	res["draw"] = draw_idxs;
	res["player_win"] = plyer_win_idxs;
	res["dealer_win"] = plyer_loss_idxs;

	return res;

}

void BJGame::display_player_hands()
{	
	std::cout << "Player hands:" << std::endl;
	int num_hands = this->player.hands.size();
	for (int i = 0; i < num_hands; i++) {
		Hand& h = this->player.hands.at(i);
		std::cout << "Hand " << i << ":" << std::endl;
		h.print_hand();
	}
}

void BJGame::display_dealer_hand()
{
	std::cout << "Dealers hand: " << std::endl;
	this->dealer.hand.print_hand();
}

std::map<int, int> BJGame::get_player_possible_actions()
{
	std::map<int, int> res;
	for (int i = 0; i < this->player.hands.size(); i++) {
		Hand& h = this->player.hands.at(i);
		int hand_value = h.get_hand_value();
		if (hand_value < 21) {
			res[i] = this->actions.hit;
		}
		else {
			res[i] = this->actions.check;
		}
	}
	return res;
}

bool BJGame::player_can_hit(std::map<int, int> possible_actions)
{
	std::map<int, int>::iterator it;
	for (it = possible_actions.begin(); it != possible_actions.end(); it++) {
		int hand_int = it->first;
		int possible_action = it->second;
		if (possible_action == this->actions.hit) {
			return true;
		}
	}
	return false;
}

void BJGame::handle_player()
{
	std::map<int, int> possible_actions = get_player_possible_actions();
	bool can_hit = player_can_hit(possible_actions);

	int hand_int = 0;
	int action = -2;
	while (can_hit) {
		display_player_hands();
		action = get_action_from_player(hand_int, possible_actions);
		if (action == this->actions.check) {
			break;
		}
		else if (action == this->actions.hit) {
			player_make_move(action, hand_int);
		}
		possible_actions = get_player_possible_actions();
		can_hit = player_can_hit(possible_actions);
	}
}

void BJGame::play_game()
{
	std::cout << "Welcome to BJ" << std::endl;
	initial_card_dealing();

	display_dealer_hand();
	handle_player();
	handle_dealer();
	display_dealer_hand();
	display_player_hands();
	std::map<std::string, std::vector<int>> winner_res = check_winner();

	if (winner_res["draw"].size()) {
		std::cout << "draw was on the hands: ";
		for (int i : winner_res["draw"]) {
			std::cout << i << " ; ";
		}
		std::cout << std::endl;
	}

	if (winner_res["player_win"].size()) {
		std::cout << this->player.name + " won on the hands: ";
		for (int i : winner_res["player_win"]) {
			std::cout << i << " ; ";
		}
		std::cout << std::endl;
	}

	if (winner_res["dealer_win"].size()) {
		std::cout << "dealer won on the hands: ";
		for (int i : winner_res["dealer_win"]) {
			std::cout << i << " ; ";
		}
		std::cout << std::endl;
	}

}

