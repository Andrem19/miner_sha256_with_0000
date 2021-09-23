//
// Created by 72555 on 9/23/2021.
//

#include "CalcHash.h"

CalcHash::CalcHash(string transactions, int size) {
this->size = size;
this->block_number = rand();
this->transactions = transactions;
this->previous_hash = "876de8756b9678c87";
}

void CalcHash::CalcAndOutput() {
    long int NONCE_LIMIT = 10000000000;
    int zeros = this->size;
    int ident = 0;
    string res;
    string src = this->block_number + this->transactions + this->previous_hash;

    for (int i = 0; i < NONCE_LIMIT; ++i) {
        string res = picosha2::hash256_hex_string(src + to_string(i));
        cout<< res<< endl;

        char* res_char = new char[res.length()];
        strcpy(res_char, res.c_str());

        for (int j = 0; j < zeros; ++j) {
            if(res_char[j] == '0')
            {
                ident++;
            }
            else
            {
                ident = 0;
                break;
            }
        }
        if (ident == zeros) {
            cout<<"code: " << i << endl;
            break;
        }
    }
}
