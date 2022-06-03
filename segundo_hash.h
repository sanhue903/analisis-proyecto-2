#ifndef HASHT2_H
#define HASHT2_H
#include <iostream>
#include <vector>
#include <utility>
#include "functions.h"

class hashT2{
    public:
        hashT2(std::vector<long long> _keys);

        std::pair<std::pair<int,int>,int> returnTrio();

        void imprimir();
        
    private:
        std::pair<int,int> ab;
        int m;

        std::vector<int> keys;

        void makeTable(std::vector<long long>);

        
        

        
};

#endif