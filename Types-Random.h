#ifndef POO_I_TYPES_RANDOM_H
#define POO_I_TYPES_RANDOM_H

#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
#include <iostream>


using integer = int;
using carac = char;
using str = std::string;
using integerPair = std::pair<int, int>;
using vectorIntPair = std::vector<integerPair>;

const int boardSize = 10;
const int nBoats = 5;


template <typename T>
void generateRandomNumber(T &v){
    v = rand()%10;
}


#endif //POO_I_TYPES_RANDOM_H
