//
// Created by Erik Salto on 10/8/20.
//
#include <cstdlib>
#include <iostream>
#include <vector>
#ifndef TICTACTOE_TICTACTOE_HXX
#define TICTACTOE_TICTACTOE_HXX


class TicTacToe {



public:
    TicTacToe();
    void reset();
    static const char* nums;
    void setPlayer();
    bool move(size_t place);
    char getPlayer();
    bool win();
    std::string toString();



protected:
    char board[9];
    bool tiles[9];
    std::vector<int>playerX;
    std::vector<int>playerY;
    char currPlayer;




};


#endif //TICTACTOE_TICTACTOE_HXX
