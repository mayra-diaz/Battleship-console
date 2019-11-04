#include "CBoard.h"

//Proove active position for second arena
bool proveSecondArena(int x, int y){
    return (x>2 && x<7) && (y==0 || y==(boardSize-1));
}

bool proveThirdArena(int x, int y){
    return (x>2 && x<7) && (y>2 && y <7);
}


CBoard::CBoard(integer x, bool show) {
    switch (x) {
        //third arena initializer
        case 3:{
            sBoard = new CSquare *[boardSize];
            for (int i = 0; i < boardSize; ++i) {
                sBoard[i] = new CSquare[boardSize];
            }
            for (int i = 0; i < boardSize; ++i) {
                for (int j = 0; j < boardSize; ++j) {
                    sBoard[i][j].setShowAndActive(show, !(proveThirdArena(i, j) || proveThirdArena(j, i)));
                }}
        }
            break;
        //second arena initializer
        case 2:{
            sBoard = new CSquare *[boardSize];
            for (int i = 0; i < boardSize; ++i) {
                sBoard[i] = new CSquare[boardSize];
            }
            for (int i = 0; i < boardSize; ++i) {
                for (int j = 0; j < boardSize; ++j) {
                    sBoard[i][j].setShowAndActive(show, !(proveSecondArena(i, j) || proveSecondArena(j, i)));
                }}
            }
                break;
        //first/deafult arena
        case 1:
        default:{
            sBoard = new CSquare *[boardSize];
            for (int i = 0; i < boardSize; ++i) {
                sBoard[i] = new CSquare[boardSize];
                for (int j = 0; j < boardSize; ++j) {
                    sBoard[i][j].setShow(show);}}
        }
    }
}

void CBoard::printBoard() {
    std::cout << "\n      0      1      2      3      4      5      6      7      8      9";
    //Iterate the square matrix
    for (int i = 0; i < boardSize; ++i) {
        std::cout << "\n" << i << "    ";
        for (int j = 0; j < boardSize; ++j) {
            if (sBoard[i][j].getActive())
            std::cout << "[" << sBoard[i][j].getSquareForPrint() << "]" << "    ";
            else std::cout << "       ";
        }
    }
}

void CBoard::changeSquareFromPosition(carac a, integerPair &position){
    sBoard[position.first][position.second].setSquare(a);
}

carac CBoard::getSquareFromPositionForAttack(integerPair &position){
    return sBoard[position.first][position.second].getSquareForAttack();
}

bool CBoard::occupiedMatrix(vectorIntPair* &vectorPositions, integerPair &initialPosition){
    bool occupied = false;
    for (auto &position: *vectorPositions){
        auto pairPosition = make_pair(position.first + initialPosition.first, position.second + initialPosition.second);
        if (sBoard[pairPosition.first][pairPosition.second].getActive()){
            if (sBoard[pairPosition.first][pairPosition.second].getSquareForAttack() != '~')
                {occupied = true;
                break;}
        } else {
            occupied = true;
            break;}
    }
    return occupied;
}


void CBoard::setBoat(vectorIntPair* boat, integerPair initialPosition){
    int f = initialPosition.first, c = initialPosition.second;
    for (auto &p: *boat){
        sBoard[f + p.first][c + p.second].setSquare('B');}
}

CBoard::~CBoard() {
    for (int i = 0; i <boardSize; ++i) {
        delete [] sBoard[i];
    }
    delete []sBoard; sBoard= nullptr;
}

bool CBoard::getActiveFromPosition(integerPair &position) {
    return sBoard[position.first][position.second].getActive();
}

void CBoard::changeShowFromPosition(integerPair &position, bool show) {
    sBoard[position.first][position.second].setShow(show);
}
