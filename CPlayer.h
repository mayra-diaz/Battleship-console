#ifndef POO_I_CPLAYER_H
#define POO_I_CPLAYER_H

#include <utility>

#include "Types-Random.h"
#include "CBoard.h"
#include "CNavy.h"
#include "CWeapon.h"
#include "IOfunctions.h"
#include "Types-Random.h"

class CPlayer{
private:
    str name;
    int score;
    CBoard board;
    CNavy navy;

    bool secondAttacked(integerPair &position);

public:

    explicit CPlayer(str nm, int nArena, bool show, int nNavy)
        :name(std::move(nm)), score(0), board(nArena, show), navy(nNavy){};

    str getName(){return name;};

    void setNavy(bool input);

    void printBoard(){board.printBoard();};

    void sumScore(int p){score += p;};
    integer getScore(){return score;};

    void attackOtherPlayer(CPlayer *me, CPlayer *opponent, bool person, bool iCoordinate);
};


#endif //POO_I_CPLAYER_H
