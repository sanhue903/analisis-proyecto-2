#ifndef PRIMER_HASH_H
#define PRIMER_HASH_H
#include <iostream>
#include <string>
#include <random>
#include <vector>

class primer_hash
{
    public:
        primer_hash(std::uniform_int_distribution<int> _distribution, std::default_random_engine _generator, std::vector<std::string> _keys);
        ~primer_hash();
        bool test();
    protected:
    private:
        size_t size;
        int prime;
        std::uniform_int_distribution<int> distribution;
        std::default_random_engine generator;
        std::vector<int> table;
        std::vector<std::string> keys;
        std::pair<int,int> genAB(int p);
        int hashT1(int p, int a, int b, int m, long long key);
        long long stringToInt(std::string key);
};

#endif