#ifndef PRIMER_HASH_H
#define PRIMER_HASH_H
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <string>
#include <random>
#include "segundo_hash.h"

#define PRIME 514249

class primer_hash
{
    public:
        primer_hash(std::uniform_int_distribution<int> _distribution, std::default_random_engine _generator, std::vector<std::string> _keys);
        ~primer_hash();
        bool buildTable();
    protected:
    private:
        int prime;
        std::pair<int,int> _ab;
        std::uniform_int_distribution<int> distribution;
        std::default_random_engine generator;
        std::vector<segundo_hash> table;
        std::vector<std::string> keys;
        std::pair<int,int> genAB(int p);
        int hashT1(int p,std::pair<int,int> ab, int m, unsigned long long key);
        unsigned long long stringToInt(std::string key);
};

#endif