#include "CBoard.h"
#include "IOfunctions.h"

void inputName(str &name){
    cout << "\nIngrese su nombre: ";
    cin >> name;
}

bool playAgain(){
    integer play;
    do {
        cout << "¿Desea reiniciar el juego? \nIngrese 0 para salir y 1 para jugar.\n";
        cin >> play;
    } while (play!= 0 && play!= 1);
    return play;
}

void printNavy(vector<vector<carac>> &navy){
    for (auto &vec: navy){
        cout << "\n";
        for (auto &ch: vec){
            cout << ch << "  ";
        }
    }
}

void printNavies(){
    vector<vector<carac>> navy1 =
            {{'B', ' ', 'B', ' ', 'B', 'B', 'B', ' ', 'B', ' ', 'B', ' '},
             {'B', ' ', 'B', ' ', ' ', 'B', ' ', ' ', 'B', ' ', 'B', 'B'},
             {' ', ' ', ' ', ' ', ' ', 'B', ' ', ' ', 'B', ' ', ' ', ' '},
             {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B', ' ', ' ', ' '}};
    vector<vector<carac>> navy2 =
            {{'B', ' ', 'B', ' ', 'B', ' ', ' ', 'B', 'B', ' ', 'B', ' '},
             {'B', ' ', 'B', ' ', 'B', 'B', ' ', 'B', 'B', ' ', 'B', 'B'},
             {' ', ' ', ' ', ' ', ' ', 'B', ' ', ' ', 'B', ' ', ' ', ' '}};
    vector<vector<carac>> navy3 =
            {{'B', ' ', 'B', ' ', 'B', ' ', ' ', ' ', 'B', ' ', 'B', ' '},
             {'B', ' ', 'B', ' ', 'B', 'B', ' ', 'B', 'B', ' ', 'B', ' '},
             {' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B', ' ', ' ', 'B', ' '},
             {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B', ' '},
             {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B', ' '}};
    vector<vector<carac>> navy4 =
            {{'B', ' ', 'B', ' ', 'B', ' ', 'B', ' ', ' ', ' ', 'B', ' '},
             {'B', ' ', 'B', ' ', 'B', ' ', 'B', 'B', ' ', 'B', 'B', ' '},
             {' ', ' ', ' ', ' ', 'B', ' ', 'B', ' ', ' ', 'B', ' ', ' '},
             {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B', ' ', ' '}};

    cout << "\nFlota 1"; printNavy(navy1);
    cout << "\nFlota 2"; printNavy(navy2);
    cout << "\nFlota 3"; printNavy(navy3);
    cout << "\nFlota 4"; printNavy(navy4);
}

void inputNavy(integer &navy){
    do {
        cout << "\nIngrese la flota que desea utilizar (1-4): ";
        cin >> navy;
    } while (navy < 1 || navy > 4);
}

void printBoards(){
    CBoard board1(1, false);
    cout << "\nArena 1: ";
    board1.printBoard();
    CBoard board2(2, false);
    cout << "\nArena 2: ";
    board2.printBoard();
    CBoard board3(3, false);
    cout << "\nArena 3: ";
    board3.printBoard();
}

void inputBoard(integer& arena){
    do {
        cout << "\nIngrese la arena que desea utilizar (1-2): ";
        cin >> arena;
    } while (arena<1 || arena>3);
}

void inputRow(integer &r){
    do {
        cout << "\nIngrese la fila(0-9): ";
        cin >> r;
    } while (r < 0 || r > 9);
}

void inputColum(integer &c){
    do {
        cout << "Ingrese la columna(0-9): ";
        cin >> c;
    } while (c<0 || c>9);
}

void inputCoordinates(integer &r, integer &c){
    inputRow(r);
    inputColum(c);
}

void inputWeapon(integer &a){
    do {
        cout << "\n1. Bomba     2. Cañon     3. Sonda     4. Bombardeo aereo     5. Mina oculta"
                << "\nIngrese el arma con la que desea atacar: ";
        cin >> a;
    } while (a<1 || a>5);
}

void infoWeapons(){
    cout << "\n1. Bomba: ataca la coordenada indicada."
            << "\n2. Cañon: ataca con un sondeo 2x2 alrededor de coordenada especifica."
            << "\n3. Sonda: ataca con un sondeo 3x3 alrededor de coordenada especifica e "
               "\ninforma cuantos sectores estan ocupados por barcos enemigos."
            << "\n4. Bombardeo aereo: ataca una fila completa."
            << "\n5. Mina oculta: se coloca oculta en su propio sBoard. Si el enemigo la ataca"
                "\nexplotan dos bombas en lugares aleatorios del sBoard enemigo";
}
