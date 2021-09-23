//
// Created by 72555 on 9/23/2021.
//
#include <string>
#include <iostream>
#include "picosha2.h"
using namespace std;
#ifndef SHA256_CALCHASH_H
#define SHA256_CALCHASH_H


class CalcHash {
public:
    int size;
    string block_number;
    string transactions;
    string previous_hash;
    CalcHash(string transactions, int size);

    void CalcAndOutput();

};


#endif //SHA256_CALCHASH_H
