#include "CPlayer.h"

void getInitialPosition(bool input, integerPair &iP, integerPair &range, int x);
void getInitialPositionFromRandom(integerPair &iP, integerPair &range);
void getInitialPositionFromInput(integerPair &iP, integerPair &range, int x);

void CPlayer::setNavy(bool input= false) {
    integerPair initialPosition;
    bool occupied;
    auto boatsIncrease = navy->getBoatsIncrease();
    int cont = 0;

    for (auto &m: *navy->getMaximum()) {
        do {
            occupied = true;
            getInitialPosition(input, initialPosition, m, cont+1);
            if(!(board->occupiedMatrix(boatsIncrease[cont], initialPosition))) {
                board->setBoat(boatsIncrease[cont], initialPosition);
                cont++;
                occupied = false;
            }
        } while (occupied);
    }
}


void CPlayer::attackOtherPlayer(CPlayer *opponent, bool person) {
    integer weaponNumber;
    integerPair initialP;

    getWeapon(person, weaponNumber);
    getInitialPositionForAttack(person, weaponNumber, initialP);

    switch (weaponNumber){
        case 1:
        case 2:
        case 3:{
            CWeapon weapon(weaponNumber);
            vectorIntPair * attackRange;
            integerPair tempPair;
            attackRange = weapon.getAttackChanges();
            switch (weaponNumber) {
                case 1:
                case 2: {
                    for (auto &attack: *attackRange) {
                        tempPair = make_pair(initialP.first + attack.first, initialP.second + attack.second);
                        opponent->changeAttackedSquare(tempPair, this);
                    }
                }
                case 3:{
                    for (auto &attack: *attackRange) {
                        tempPair = make_pair(initialP.first + attack.first, initialP.second + attack.second);
                        if (opponent->board->getActiveFromPosition(tempPair))
                            opponent->board->changeShowFromPosition(tempPair, true);

                    }
                }
            }
        }
            break;
        case 4:{
            integerPair tempPair;
            if (tempPair.first) {
                for (int i = 0; i <boardSize; ++i) {
                    tempPair = make_pair(initialP.first, i);
                    opponent->changeAttackedSquare(tempPair, this);}
            } else {
                for (int i = 0; i <boardSize; ++i) {
                    tempPair = make_pair(i, initialP.second);
                    opponent->changeAttackedSquare(tempPair, this);}
            }
        }
            break;
        case 5:{
            board->changeSquareFromPosition('M', initialP);
        }
    }
}


bool CPlayer::changeAttackedSquare(integerPair &position, CPlayer *opponent) {
    carac ch = board->getSquareFromPositionForAttack(position);
    switch (ch){
        case 'B':
            board->changeSquareFromPosition('X', position);
            opponent->sumScore(1);
            break;
        case 'F':
        case 'X':
            break;
        case 'M':{
            integer rand1, rand2;

            generateRandomNumber(rand1); generateRandomNumber(rand2);
            integerPair firstAttack = make_pair(rand1, rand2);

            generateRandomNumber(rand1); generateRandomNumber(rand2);
            integerPair secondAttack = make_pair(rand1, rand2);

            opponent->changeAttackedSquare(firstAttack, this);
            opponent->changeAttackedSquare(secondAttack, this);}
        case '~':
        default:
            board->changeSquareFromPosition('F', position);
            break;
    }
}

void CPlayer::getInitialPositionForAttack(bool person, integer weapon, integerPair &initialP) const {
    integerPair range;
    switch (weapon){
        case 1:
        case 5:{
            range = make_pair(0, 0);
            getInitialPosition(person, initialP, range, 1);}
            break;
        case 2:{
            range = make_pair(1, 1);
            getInitialPosition(person, initialP, range, 1);}
            break;
        case 3:{
            range=make_pair(2, 2);
            getInitialPosition(person, initialP, range, 1);}
            break;
        case 4:{
            carac input = 'f';
            integer v;
            if (person) chooseRowOrColum(input);
            else generateRandomNumber(v);
            if (input == 'f'){
                inputRow(v);
                initialP = make_pair(v, 0);
            } else {
                inputColum(v);
                initialP = make_pair(0, v);
            }
        }
            break;
    }
}


void CPlayer::getWeapon(bool person, integer &op) const {
    if (person) inputWeapon(op);
    else {
        do{
            generateRandomNumber(op);
        } while (op < 0 || op > 5);
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


