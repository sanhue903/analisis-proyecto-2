#ifndef HASHT2_H
#define HASHT2_H
#include <iostream>
#include <vector>

class hashT2{
    public:
        hashT2(std::vector<int> _keys,int);
        ~hashT2();

    private:
        std::vector<int> table;
        std::vector<int> keys;

};

#endif