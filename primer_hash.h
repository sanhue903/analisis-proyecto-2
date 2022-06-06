#ifndef PRIMER_HASH_H
#define PRIMER_HASH_H
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <string>
#include <random>

#define PRIME 514249

class primer_hash
{
    public:
        primer_hash(std::uniform_int_distribution<int> _distribution, std::default_random_engine _generator, std::vector<std::string> _keys);
        ~primer_hash();
        bool buildTable();
        void printTable();
    private:
        std::pair<int,int> _ab;
        std::vector<std::pair<int,int> > ABs;
        std::uniform_int_distribution<int> distribution;
        std::default_random_engine generator;
        std::vector<std::vector<std::string> > table;
        std::vector<std::string> keys;

        std::vector<std::string> buildTable2(std::vector<std::string> str_vr);
        std::pair<int,int> genAB(int p);
        int hashF(int p,std::pair<int,int> ab, int m, std::string key);
        int stringToInt(std::string key);
};

#endif
