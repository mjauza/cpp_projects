#ifndef GUI_H
#define GUI_H
#include "Board.h"

class GUI
{
    public:
        GUI();
        virtual ~GUI();
        void player1_move();
        void player2_move();
        bool check_winner();

        void play_game();

    protected:
        Board board;


    private:
};

#endif // GUI_H
