#include "CPlayer.h"

void getInitialPosition(bool input, integerPair &iP, integerPair &range, int x);
void getInitialPositionFromRandom(integerPair &iP, integerPair &range);
void getInitialPositionFromInput(integerPair &iP, integerPair &range, int x);

void CPlayer::setNavy(bool input= false) {
    integerPair initialPosition;
    bool occupied;

    auto boatsIncrease = navy.getBoatsIncrease();
    int cont = 0;

    for (auto &m: *navy.getMaximum()) {
        do {
            occupied = true;
            getInitialPosition(input, initialPosition, m, cont+1);
            if(!(board.occupiedMatrix(boatsIncrease[cont], initialPosition))) {
                board.setBoat(boatsIncrease[cont], initialPosition);
                cont++;
                occupied = false;
            }
        } while (occupied);
    }
}


bool CPlayer::secondAttacked(integerPair &position) {
    carac ch = board.getSquareFromPositionForAttack(position);
    switch (ch){
        case 'B':
            board.changeSquareFromPosition('X', position);
            break;
        case 'F':
        case 'X':
            break;
        case 'M':
        case '~':
        default:
            board.changeSquareFromPosition('F', position);
            break;
    }
}

void CPlayer::attackOtherPlayer(CPlayer *me, CPlayer *opponent, bool person, bool iCoordinate){
    integerPair initialP;
    integer op;

    if (person) inputWeapon(op);
    else {
        do{
            generateRandomNumber(op);
        } while (op < 0 || op > 5);
    }

    switch (op){
        case 5: {
            integerPair max = make_pair(0, 0);
            bool c= true;
            getInitialPosition(person, initialP, max, 1);
            do {
                if (!(me->board.occupiedSquare(initialP))) {
                    me->board.changeSquareFromPosition('M', initialP);
                    c= false;}
            } while (c);
        }break;
        case 4: {
            integer row;
            inputRow(row);
            for (int i = 0; i < boardSize; ++i) {
                initialP = make_pair(row, i);
                if (opponent->board.getSquareFromPositionForAttack(initialP) == 'M') {
                    integer rand1, rand2;
                    generateRandomNumber(rand1); generateRandomNumber(rand2);
                    integerPair firstAttack = make_pair(rand1, rand2);

                    generateRandomNumber(rand1); generateRandomNumber(rand2);
                    integerPair secondAttack = make_pair(rand1, rand2);

                    me->secondAttacked(firstAttack);
                    me->secondAttacked(secondAttack);
                    break;
                } else
                    opponent->secondAttacked(initialP);
            }
        }break;
        case 1:
        case 2:
        case 3:
        default: {
            CWeapon bomb(op);
            integerPair maximumBomb = bomb.getMaximunRange();
            vectorIntPair * bombAttackRange = bomb.getAttackChanges();

            getInitialPosition(iCoordinate, initialP, maximumBomb, 1);

            for (auto &increase: *bombAttackRange) {
                initialP = make_pair(initialP.first + increase.first, initialP.second + increase.second);
                auto ch = opponent->board.getSquareFromPositionForAttack(initialP);
                switch (ch) {
                    case 'B':
                        opponent->board.changeSquareFromPosition('X', initialP);
                        me->sumScore(1);
                        break;
                    case 'M': {
                        integer rand1, rand2;
                        generateRandomNumber(rand1); generateRandomNumber(rand2);
                        integerPair firstAttack = make_pair(rand1, rand2);

                        generateRandomNumber(rand1); generateRandomNumber(rand2);
                        integerPair secondAttack = make_pair(rand1, rand2);

                        me->secondAttacked(firstAttack);
                        me->secondAttacked(secondAttack);
                        break;
                    }
                    case 'F':
                    case 'X':
                        break;
                    case '~':
                        opponent->board.changeSquareFromPosition('F', initialP);
                        break;
                }
            }
        }break;
    }
}


void getInitialPosition(bool input, integerPair &iP, integerPair &range, int x){
    if (input)  getInitialPositionFromInput(iP, range, x);
    else getInitialPositionFromRandom(iP, range);
}

void getInitialPositionFromRandom(integerPair &iP, integerPair &range){
    do {
        generateRandomNumber(iP.first);
        generateRandomNumber(iP.second);
    } while (((iP.first + range.first) > 9) || ((iP.second + range.second) > 9));
}

void getInitialPositionFromInput(integerPair &iP, integerPair &range, int x) {
    do {
        std::cout << "\nCoordenada " << x;
        inputCoordinates(iP.first, iP.second);
    } while (((iP.first + range.first) > 9) || ((iP.second + range.second) > 9));
}


