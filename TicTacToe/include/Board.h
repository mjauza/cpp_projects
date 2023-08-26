#ifndef BOARD_H
#define BOARD_H
#include <array>
#include <string>
class Board
{
    public:
        Board();
        void print_board();
        std::string get_symbol(int num);
        bool put_tic(int r, int c);
        bool put_tac(int r, int c);
        int check_winner();
        virtual ~Board();

    protected:
        std::array<std::array<int, 3> , 3> board;

    private:
};

#endif // BOARD_H
