#include "GUI.h"
#include <iostream>
#include "Board.h"
GUI::GUI()
{
    //ctor
}

void GUI::play_game()
{
    this -> board = Board();
    // welcome message
    std::cout << "Welcome to tic-tac-toe!" << std::endl;
    std::cout << "Player 1 has x" << std::endl;
    std::cout << "Player 2 has o" << std::endl;

    bool game_over;
    while(true){

        // player one move
        this->player1_move();
        // display borad
        this -> board.print_board();

        // check winner - if true break
        game_over = check_winner();
        if(game_over){
            break;
        }
        // player two move
        this->player2_move();
        this -> board.print_board();
        // check winner - if true break
        game_over = check_winner();
        if(game_over){
            break;
        }
    }

    // goodbye message
    std::cout << "Goodbye!" << std::endl;
}
void GUI::player1_move()
{
    std::cout << "Player 1 has a move" << std::endl;
    while(true){
        int r;
        int c;
        std::cout << "Please input row [1-3]: ";
        std::cin >> r;
        std::cout << "Please input column [1-3]: ";
        std::cin >> c;
        r -= 1;
        c -= 1;
        bool success = this->board.put_tic( r, c);
        if(success){
            break;
        }else{
            std::cout << "Incorrect move positions" << std::endl;
        }
    }
}

void GUI::player2_move()
{
    std::cout << "Player 2 has a move" << std::endl;
    while(true){
        int r;
        int c;
        std::cout << "Please input row [1-3]: ";
        std::cin >> r;
        std::cout << "Please input column [1-3]: ";
        std::cin >> c;
        r -= 1;
        c -= 1;
        bool success = this->board.put_tac( r, c);
        if(success){
            break;
        }else{
            std::cout << "Incorrect move positions" << std::endl;
        }
    }
}

bool GUI::check_winner()
{
    //return true if game over
    int status = this->board.check_winner();
    if(status == -1){
        std::cout << "Player 1 has won!" << std::endl;
        return true;
    }else if(status==1){
        std::cout << "Player 2 has won!" << std::endl;
        return true;
    }else if (status == 0){
        return false;
    }else{
        std::cout << "It's a draw!" << std::endl;
        return true;
    }

}

GUI::~GUI()
{
    //dtor
}
