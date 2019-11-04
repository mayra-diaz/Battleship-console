#ifndef POO_I_CGAME_H
#define POO_I_CGAME_H

#include "Types-Random.h"
#include "CPlayer.h"
#include "IOfunctions.h"


class Game {
private:
    CPlayer *player1{};
    CPlayer *player2{};
    integer option;
    integer navy;
    integer board;
    integer generateRandomNavy();
public:
    explicit Game(){option = 0; navy=0; board = 1; player1= nullptr; player2= nullptr;};
    virtual ~Game(){delete player1; player1= nullptr; delete player2; player2= nullptr;};

    void executeGame();
    void printMenu();
    void chooseArenaBoard();
    void chooseNavy();
    void play();
};

#endif //POO_I_CGAME_H
