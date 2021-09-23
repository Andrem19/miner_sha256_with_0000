#include <iostream>
#include <string>
#include "picosha2.h"

using namespace std;

void CalcAndOutput(const string& block_number, const string& transactions, const string& previous_hash ){
    long int NONCE_LIMIT = 10000000000;
    int zeros = 4;
    int ident = 0;
    string res;
    string src = block_number + transactions + previous_hash;

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

int main()
{
    string block_number = "24";
    string transactions = "76123fcc2141";
    string previous_hash = "876de8756b9678c87";


        CalcAndOutput(block_number, transactions, previous_hash);

    return 0;
}

