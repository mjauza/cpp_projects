#include <iostream>
#include "Board.h"
#include "GUI.h"
using namespace std;

int main()
{
    /*
    Board board = Board();
    board.put_tac(0,0);
    board.put_tic(1,1);
    board.print_board();
    */
    GUI game = GUI();
    game.play_game();
    return 0;
}
