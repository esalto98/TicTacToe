//
// Created by Erik Salto on 10/9/20.
//
#include "TicTacToe.hxx"

const char* TicTacToe::nums = "012345678";

TicTacToe::TicTacToe() {
    currPlayer = 'X';
    reset();
}



void TicTacToe::reset() {
    for(int i = 0; i < 9; ++i) {
        board[i] = nums[i];
        tiles[i] = false;
    }
    playerX.erase(playerX.begin(),playerX.end());
    playerY.erase(playerY.begin(),playerY.end());
}

void TicTacToe::setPlayer() {
    if(currPlayer == 'X'){
        currPlayer = 'O';
    } else{
        currPlayer = 'X';
    }
}

bool TicTacToe::move(size_t tile) {
    if(tile < 0 || tile > 8){
        std::cout << "\nnot a tile, choose any unused tile (0-9)\n";
        return false;
    }
    if(tiles[tile]){
        std::cout << "\nYou picked a used tile\n";
        return false;
    }

    board[tile] = currPlayer;
    if(currPlayer == 'X')
        playerX.push_back(tile);
    else{
        playerY.push_back(tile);
    }
    tiles[tile] = true;
    return true;
}

char TicTacToe::getPlayer() {
    return currPlayer;
}

bool TicTacToe::win() {
    int moves[8][3] { {0,1,2}, {3,4,5},
                      {6,7,8}, {0,3,6},
                      {1,4,7}, {2,5,8},
                      {0,4,8}, {2,4,6}};

    std::vector<int>* player;

    if(getPlayer() == 'X')
        player = &playerX;
    else
        player = &playerY;

    if(player->size() < 3)
        return false;

    for(auto & move : moves){
        int win = 0;
        for(int j : *player)
            for(int k : move)
                if(j == k)
                    ++win;
        if(win == 3)
            return true;
    }
    return false;
}

std::string TicTacToe::toString() {
    std::string game;
    const std::string LINE = "-+-+-";

    for(size_t i = 0; i < 9; ++i){
        game += board[i];
        if((i == 2) || (i == 5) || (i == 8) ){
            game += '\n';
            if(i != 8){
                game += LINE;
                game += '\n';
            }
        }else
            game += '|';
    }
    return game;
}