
#include <iostream>

// Include the implementation of TicTacToeGame class
#include "TicTacToe.cpp"

int main() {
    // Dynamically allocate the TicTacToeGame object
    TicTacToeGame* p_game = new TicTacToeGame();

    // Play the game
    p_game->play();

    // Deallocate the memory associated with the object
    delete p_game;

    return 0;
}
