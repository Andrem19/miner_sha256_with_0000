#include <iostream>
#include <string>
#include "picosha2.h"
#include "CalcHash.h"

using namespace std;

int main()
{
    srand(time(NULL));

    cout<< "input data you want add to block(string without spaces)"<<endl;
    string transaction;
    cin>>transaction;
    cout<< "input number of zeros you want to add before each hash"<<endl;
    int num;
    cin>>num;
    CalcHash new_block(transaction, num);

    new_block.CalcAndOutput();
    system("pause");
    return 0;
}

