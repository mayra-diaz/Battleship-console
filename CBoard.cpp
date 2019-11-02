#include "CBoard.h"

//Proove active position for second arena
bool proveSecondArena(int x, int y){
    return (x==3 || x==4 || x==5 || x==6) && (y==0 || y==(boardSize-1));
}


CBoard::CBoard(integer x, bool show) {
    switch (x) {
        //second arena initializer
        case 2:
            sBoard = new CSquare *[boardSize];
            for (int i = 0; i < boardSize; ++i) {
                sBoard[i] = new CSquare[boardSize];
            }
            for (int i = 0; i < boardSize; ++i) {
                for (int j = 0; j < boardSize; ++j) {
                    sBoard[i][j].setShowAndActive(show, !(proveSecondArena(i, j) || proveSecondArena(j, i)));
                }
            }
            break;
            //first/deafult arena
        case 1:
        default:
            sBoard = new CSquare *[boardSize];
            for (int i = 0; i < boardSize; ++i) {
                sBoard[i] = new CSquare[boardSize];
                for (int j = 0; j < boardSize; ++j) {
                    sBoard[i][j].setShow(show);}
            }
    }
}

void CBoard::printBoard() {
    std::cout << "\n     0    1    2    3    4    5    6    7    8    9";
    //Iterate the square matrix
    for (int i = 0; i < boardSize; ++i) {
        std::cout << "\n" << i << "    ";
        for (int j = 0; j < boardSize; ++j) {
            std::cout << sBoard[i][j].getSquareForPrint() << "    "; }
    }
}

void CBoard::changeSquareFromPosition(carac a, integerPair &position){
    sBoard[position.first][position.second].setSquare(a);
}

carac CBoard::getSquareFromPositionForAttack(integerPair &position){
    return sBoard[position.first][position.second].getSquareForAttack();
}

bool CBoard::occupiedMatrix(vectorIntPair* &vectorPositions, integerPair &initialPosition){
    for (auto &position: *vectorPositions){
        auto pairPosition = make_pair(position.first + initialPosition.first, position.second + initialPosition.second);
        return occupiedSquare(pairPosition);
    }
}

bool CBoard::occupiedSquare(integerPair &position){
    if (sBoard[position.first][position.second].getSquareForPrint() == '*'){
        std::cout << "Hola";
    }
    return (sBoard[position.first][position.second].getSquareForPrint() != '~');
}

void CBoard::setBoat(vectorIntPair* boat, integerPair initialPosition){
    int f = initialPosition.first, c = initialPosition.second;
    for (auto &p: *boat){
        sBoard[f + p.first][c + p.second].setSquare('B');
    }
}