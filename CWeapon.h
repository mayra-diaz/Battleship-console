#ifndef POO_I_CWEAPON_H
#define POO_I_CWEAPON_H

#include "Types-Random.h"

class CWeapon {
private:
    vectorIntPair *attackRange{};

public:
    //constructor
    explicit CWeapon(integer x) {
        attackRange = new vectorIntPair;
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < x; ++j) {
                integerPair pair1 = make_pair(i, j);
                attackRange->emplace_back(pair1);
            }
        }
    }

    //Problemas con el destructor
    //virtual ~CWeapon(){delete []attackRange; attackRange= nullptr;}

    vectorIntPair* getAttackChanges(){return attackRange;};
};

#endif //POO_I_CWEAPON_H
