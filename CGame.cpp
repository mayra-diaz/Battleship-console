#include "CGame.h"

void Game::executeGame() {;
    option = 1;
    str name;
    bool show, navyInitialized= false, navyChoosen= false, playersNotCreated= true;
    inputName(name);
    do{
        printMenu();
        switch (option){
            case 1:{
                chooseArenaBoard();
            }
                break;
            case 2:{
                chooseNavy();
                navyChoosen = true;
            }
                break;
        }

        if (playersNotCreated) {
            player1 = new CPlayer(name, board, true, 0);
            player2 = new CPlayer("Enemigo", board, false, generateRandomNavy());
            if (!navyChoosen) navy = generateRandomNavy();
            playersNotCreated = false;
        }

        switch (option){
            case 3:{
                player1->initializeNavy(navy);
                player1->setNavy(true);
                navyInitialized = true;
            }
                break;
            case 4:{
                infoWeapons();
                if (!navyInitialized) {
                    player1->initializeNavy(navy);
                    player1->setNavy(false);
                }
                player2->setNavy(false);
                play();
            }
                break;
        }
    } while (option!=5);
}

integer Game::generateRandomNavy(){
    integer v;
    do{
        generateRandomNumber(v);
    } while (v > 4 || v < 1);
    return v;
}


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
    bool run = true;
    do{
        std::cout << "\nUsted tiene " << player1->getScore() << " puntos.";
        std::cout << "\nSu oponente tiene " << player2->getScore() << " puntos.";
        std::cout << "\nTablero de " << player1->getName();
        player1->printBoard();

        std::cout << "\nTablero enemigo: ";
        player2->printBoard();

        std::cout << "\nTurno de: " << player1->getName();
        player1->attackOtherPlayer(player2, true);
        player2->attackOtherPlayer(player1, false);

        if (player1->getScore() == 16) run = false;
        if (player2->getScore() == 16) run = false;

    }while (run);
}


