#include "CGame.h"
#include "Types-Random.h"

int main(){
    srand(time(nullptr));
    do{
        Game game;
        game.executeGame();
    } while (playAgain());

    return EXIT_SUCCESS;
}
