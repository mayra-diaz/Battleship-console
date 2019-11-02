#ifndef POO_I_CGAME_H
#define POO_I_CGAME_H

#include "Types-Random.h"
#include "CPlayer.h"
#include "IOfunctions.h"


class Game {
private:
    CPlayer *jugador1{};
    CPlayer *jugador2{};
    integer option;
    integer navy;
    integer board;
public:
    explicit Game(){option = 0; navy=1; board = 1; jugador1= nullptr; jugador2= nullptr;};
    ~Game()= default;
    void executeGame();
    void printMenu();
    void chooseArenaBoard();
    void chooseNavy();
    void play();
};

#endif //POO_I_CGAME_H
