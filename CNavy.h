#ifndef POO_I_CNAVY_H
#define POO_I_CNAVY_H

#include "Types-Random.h"
#include "IOfunctions.h"


class CNavy{

private:
    vectorIntPair** navy{};

    vectorIntPair *maximum{};

public:
    explicit CNavy(int x);
    virtual ~CNavy();

    void chooseNavy(integer x);

    auto getBoatsIncrease(){ return navy;};

    auto getMaximum(){return maximum;};
};

#endif //POO_I_CNAVY_H
