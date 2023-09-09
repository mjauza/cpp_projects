#pragma once
#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
class BJGame
{
	public: 
		BJGame(Player player);

		void initial_card_dealing();
		void handle_player(int action_type);
		void handle_dealer(int action_type);
		bool check_winner();
		void play_game();

	
	private:
		Player player;
		Dealer dealer;
		Deck deck;
		struct {
			int hit = 0;
			int check = 1;
		} actions;

};

