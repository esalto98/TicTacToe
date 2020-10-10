#include <iostream>
#include "TicTacToe.hxx"
int main() {

    TicTacToe game;

    int moves = 0;
    int pos;
    bool gameOver = false;

    while(moves < 9 && !gameOver)
    {
        std::cout << game.toString() << std::endl << "Player " << game.getPlayer() << " make a move: ";
        std::cin >> pos;
        ++moves;
        while(!game.move(pos))
            std::cin >> pos;
        if(game.win())
        {
            std::cout << '\n' << game.getPlayer() << " Won!\n";
            gameOver = true;
        }
        game.setPlayer();
        if(moves == 9 && !gameOver)
            std::cout << "\n Its a Tie!\n";

    }
    return 0;
}
