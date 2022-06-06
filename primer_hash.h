#ifndef HASHT1_H
#define HASHT1_H
#include "segundo_hash.h"

class hashT1{
    public:
        hashT1(std::vector<std::string>);
        void imprimir();
    private:
        std::pair<int,int> ab;
        std::vector<hashT2*> table;
        void buildTable(std::vector<std::string>);
};

#endif