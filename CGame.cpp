#include "CGame.h"

// explicit CPlayer(str nm, int nArena, bool show, int nNavy)
//  :name(std::move(nm)), score(0), board(nArena, show), navy(nNavy){}
integer generateRandomNavy();

void Game::executeGame() {;
    option = 1;
    str name;
    bool show, nn= false;
    inputName(name);
    do{
        printMenu();
        if (option==1){
            chooseArenaBoard();}

        else if (option==2){
            chooseNavy();}

        else {
            jugador1 = new CPlayer(name, board, true, navy);
            jugador2 = new CPlayer("Enemigo", board, false, generateRandomNavy());
            if (option==3){
                jugador1->setNavy(true);
                nn = true;}
            if (option==4){
                infoWeapons();
                if (!nn) jugador1->setNavy(false);
                jugador2->setNavy(false);
                play();
            }
        }
    } while (option!=5);
}

integer generateRandomNavy(){
    integer navy;
    do{
        generateRandomNumber(navy);
    } while (navy>4 || navy<0);
    return navy;
}

//CPlayer(str nm, int nArena, bool show, int nNavy)

void Game::printMenu(){
    do{
        cout << "\nMenu Principal"
             << "\n1. Seleccionar el escenario de combate"
             << "\n2. Seleccionar la flota"
             << "\n3. Colocar de flota"
             << "\n4. Jugar"
             << "\n5. Salir";
        cout << "\nIngrese la opcion que desea: ";
        cin >> option;
    } while (option < 1 || option > 5);
}

void Game::chooseArenaBoard() {
    printBoards();
    inputBoard(board);
}

void Game::chooseNavy() {
    printNavies();
    inputNavy(navy);
}

//CPlayer *me, CPlayer *opponent, bool iWeapon, bool iCoordinate
void Game::play() {
    do{
        std::cout << "\nTablero de " << jugador1->getName();
        jugador1->printBoard();

        std::cout << "\nTurno de: " << jugador1->getName()
                    << "\nTablero enemigo: ";
        jugador2->printBoard();
        jugador1->attackOtherPlayer(jugador1, jugador2, true, true);

        jugador2->attackOtherPlayer(jugador2, jugador1, false, false);

    }while (jugador1->getScore()!=16 || jugador2->getScore()!=16);
}


