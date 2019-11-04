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
    CBoard *board;
    CNavy *navy;

    bool changeAttackedSquare(integerPair &position, CPlayer *opponent);

    void getWeapon(bool person, integer &op) const;

public:

    explicit CPlayer(str nm, int nArena, bool show, int nNavy)
        :name(std::move(nm)), score(0), board(nullptr), navy(nullptr)
        {navy = new CNavy(nNavy); board = new CBoard(nArena, show);};

    virtual ~CPlayer(){
        delete board; board = nullptr;
        delete navy; navy = nullptr;
    }

    void initializeNavy(integer number){ navy->chooseNavy(number);};

    str getName(){return name;};

    void setNavy(bool input);

    void printBoard(){board->printBoard();};
    void sumScore(int p){score += p;};

    integer getScore(){return score;};

    void attackOtherPlayer(CPlayer *opponent, bool person);

    void getInitialPositionForAttack(bool person, integer weapon, integerPair &initialP) const;
};


#endif //POO_I_CPLAYER_H
