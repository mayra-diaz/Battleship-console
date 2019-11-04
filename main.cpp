#include "CGame.h"

int main(){

    do{
        Game game;
        game.executeGame();
    } while (playAgain());

    return EXIT_SUCCESS;
}