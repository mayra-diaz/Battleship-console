#include "CNavy.h"


CNavy::CNavy(int tFlota){
    switch (tFlota){
        case 1:
        case 2:
        case 3:
        case 4:
            chooseNavy(tFlota);
            break;
        default:
            navy = nullptr;
            maximum = nullptr;
    }
}

void CNavy::chooseNavy(integer x) {
    navy = new vectorIntPair*[nBoats];
    for (int i = 0; i < nBoats; ++i) {
        navy[i] = new vectorIntPair[2];
    }
    maximum = new vectorIntPair[2];

    switch (x){
        //NAVY 2
        case 2: {
            *navy[0] = {{0, 0},
                        {1, 0}};
            *navy[1] = {{0, 0},
                        {1, 0}};

            *navy[2] = {{0, 0},
                        {1, 0}};
            navy[2]->emplace_back(make_pair(1, 1));
            navy[2]->emplace_back(make_pair(2, 1));

            *navy[3] = {{0, 0},
                        {0, 1}};
            navy[3]->emplace_back(make_pair(1, 0));
            navy[3]->emplace_back(make_pair(1, 1));
            navy[3]->emplace_back(make_pair(2, 1));

            *navy[4] = {{0, 0},
                        {1, 0}};
            navy[4]->emplace_back(make_pair(1, 1));

            *maximum = {{1, 0},
                        {1, 0},
                        {2, 1},
                        {2, 1},
                        {1, 1}};
        }break;

            //NAVY 3
        case 3: {
            *navy[0] = {{0, 0},
                        {1, 0}};
            *navy[1] = {{0, 0},
                        {1, 0}};

            *navy[2] = {{0, 0},
                        {1, 0}};
            navy[2]->emplace_back(make_pair(1, 1));

            *navy[3] = {{0, 1},
                        {1, 0}};
            navy[3]->emplace_back(make_pair(1, 1));
            navy[3]->emplace_back(make_pair(2, 0));

            *navy[4] = {{0, 0},
                        {1, 0}};
            navy[4]->emplace_back(make_pair(2, 0));
            navy[4]->emplace_back(make_pair(3, 0));
            navy[4]->emplace_back(make_pair(4, 0));

            *maximum = {{1, 0},
                        {1, 0},
                        {1, 1},
                        {2, 1},
                        {4, 0}};
        }break;

            //NAVY 4
        case 4: {
            *navy[0] = {{0, 0},
                        {1, 0}};
            *navy[1] = {{0, 0},
                        {1, 0}};

            *navy[2] = {{0, 0},
                        {1, 0}};
            navy[2]->emplace_back(make_pair(2, 0));

            *navy[3] = {{0, 0},
                        {1, 0}};
            navy[3]->emplace_back(make_pair(1, 1));
            navy[3]->emplace_back(make_pair(2, 0));

            *navy[4] = {{0, 1},
                        {1, 0}};
            navy[4]->emplace_back(make_pair(1, 1));
            navy[4]->emplace_back(make_pair(2, 0));
            navy[4]->emplace_back(make_pair(3, 0));

            *maximum = {{1, 0},
                        {1, 0},
                        {2, 0},
                        {2, 1},
                        {3, 1}};
        }break;

            //NAVY 1
        case 1:
        default: {
            *navy[0] = {{0, 0},
                        {1, 0}};
            *navy[1] = {{0, 0},
                        {1, 0}};

            *navy[2] = {{0, 0},
                        {0, 1}};
            navy[2]->emplace_back(make_pair(0, 2));
            navy[2]->emplace_back(make_pair(1, 1));
            navy[2]->emplace_back(make_pair(2, 1));

            *navy[3] = {{0, 0},
                        {1, 0}};
            navy[3]->emplace_back(make_pair(2, 0));
            navy[3]->emplace_back(make_pair(3, 0));

            *navy[4] = {{0, 0},
                        {1, 0}};
            navy[4]->emplace_back(make_pair(1, 1));

            *maximum = {{1, 0},
                        {1, 0},
                        {2, 2},
                        {3, 0},
                        {1, 1}};
        }
    }
}

CNavy::~CNavy() {
    for (int i = 0; i <nBoats; ++i) {
        delete[] navy[i];
    }
    delete [] navy; navy = nullptr;
    delete []maximum; maximum = nullptr;
}

