#ifndef HASHT2_H
#define HASHT2_H
#include <iostream>
#include <vector>
#include <utility>
#include "functions.h"

class hashT2{
    public:
        hashT2(std::vector<std::string> _keys);

        std::pair<std::pair<int,int>,int> returnTrio();

        void imprimir();
        
    private:
        std::pair<int,int> ab;
        int m;

        std::vector<std::string> keys;

        void makeTable(std::vector<std::string>);
};

#endif