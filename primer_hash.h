#ifndef PRIMER_HASH_H
#define PRIMER_HASH_H
#include <iostream>
#include <string>
#include <vector>

class primer_hash
{
    public:
        primer_hash(std::vector<std::string> _keys);
        ~primer_hash();
        bool test();
    protected:
    private:
        size_t size;
        std::vector<int> table;
        std::vector<std::string> keys;
        std::pair<int,int> genAB(int p);
        int hashT1(int p, int a, int b, int m, long long key);
        long long stringToInteger(std::string key);
};

#endif