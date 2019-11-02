#ifndef POO_I_CWEAPON_H
#define POO_I_CWEAPON_H

#include "Types-Random.h"

class CWeapon {
private:
    vectorIntPair *attackRange{};
    integerPair range;
public:
    //constructor
    explicit CWeapon(integer x) {
        switch (x) {
            case 1:
            case 2:
            case 3:
                attackRange = new vectorIntPair;
                for (int i = 0; i < x; ++i) {
                    for (int j = 0; j < x; ++j) {
                        integerPair pair1 = make_pair(i, j);
                        attackRange->emplace_back(pair1);
                    }
                }
                range = make_pair(x, x);
                break;
            default:
                GENERIC_ERRORCHECK_INITIALIZER;
        }
    }

    vectorIntPair* getAttackChanges(){return attackRange;};
    integerPair getMaximunRange(){ return range;};
};

#endif //POO_I_CWEAPON_H
