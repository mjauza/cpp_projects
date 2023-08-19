#include "Board.h"
#include <iostream>
#include <string>
Board::Board()
{
    //ctor
}

std::string Board::get_symbol(int num){
    if(num == -1){
        return "x";
    }else if (num == 1){
        return "0";
    }else{
        return " ";
    }

}

bool Board::put_tic(int r, int c)
{
    if( (r < 0) || (r > 2)){
        return false;
    }
    if( (c < 0) || (c > 2)){
        return false;
    }

    int curr_num = this->board[r][c];
    if(curr_num == 1){
        return false;
    }else{
        this->board[r][c] = -1;
        return true;
    }
}

bool Board::put_tac(int r, int c)
{
    if( (r < 0) || (r > 2)){
        return false;
    }
    if( (c < 0) || (c > 2)){
        return false;
    }
    int curr_num = this->board[r][c];
    if(curr_num == -1){
        return false;
    }else{
        this->board[r][c] = 1;
        return true;
    }
}

int Board::check_winner()
{
    // check full rows
    for(int r=0; r<3; r++){
        int row_sum = 0;
        for(int c=0; c<3; c++){
            row_sum += this->board[r][c];
        }
        if(row_sum == -3){
            return -1;
        }
        if(row_sum == 3){
            return 1;
        }
    }

    //check full columns
    for(int c=0; c<3; c++){
        int col_sum = 0;
        for(int r=0; r<3; r++){
            col_sum += this->board[r][c];
        }
        if(col_sum == -3){
            return -1;
        }
        if(col_sum == 3){
            return 1;
        }
    }

    // check diagonals
    int diag1 = this->board[0][0] + this->board[1][1] + this->board[2][2];
    if(diag1 == -3){
        return -1;
    }
    if(diag1 == 3){
        return 1;
    }

    int diag2 = this->board[0][2] + this->board[1][1] + this->board[2][0];
    if(diag2 == -3){
        return -1;
    }
    if(diag2 == 3){
        return 1;
    }

    // check if board is full

    for(int r=0; r<3; r++){
        for(int c=0; c<3; c++){
            if(this->board[r][c] == 0){
                // game in progress
                return 0;
            }
        }
    }
    // draw
    return 2;
}

void Board::print_board()
{
    for(int r = 0; r<3; r++){
        std::cout << "-------" << std::endl;
        for(int c = 0; c<3; c++){
            if(c == 0){
                std::cout << "|";
            }
            int val = this->board[r][c];
            std::string sym = get_symbol(val);
            std::cout << sym << "|";
        }
        std::cout << std::endl;
    }
    std::cout << "-------" << std::endl;
}

Board::~Board()
{
    //dtor
}
