#ifndef POO_I_CBOARD_H
#define POO_I_CBOARD_H

#include "Types-Random.h"
#include "IOfunctions.h"
#include "CSquare.h"


class CBoard{
private:
    CSquare** sBoard{};

public:
    explicit CBoard(integer x, bool show);
    ~CBoard();

    void changeSquareFromPosition(carac a, integerPair &position);
    carac getSquareFromPositionForAttack(integerPair &position);
    bool getActiveFromPosition(integerPair &position);
    void changeShowFromPosition(integerPair &position, bool show);
    bool occupiedMatrix(vectorIntPair* &vectorPositions, integerPair &initialPosition);
    void setBoat(vectorIntPair* boat, integerPair initialPosition);
    void printBoard();
};

#endif //POO_I_CBOARD_H
