#pragma once
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
#include <string>
#include <map>
class BJGame
{
	public: 
		BJGame(std::string player_name);

		void initial_card_dealing();
		void player_make_move(int action_type, int hand_int);
		void handle_player();
		std::map<int, int> get_player_possible_actions();
		bool player_can_hit(std::map<int, int> possible_actions);
		int get_action_from_player(int hand_int, std::map<int, int> possible_actions);
		int get_hand_int_from_player();
		void handle_dealer();
		std::map<std::string, std::vector<int>> check_winner();
		void play_game();
		void display_player_hands();
		void display_dealer_hand();

	
	private:
		Player player;
		Dealer dealer;
		Deck deck;
		struct {
			int hit = 0;
			int check = 1;
		} actions;

};

