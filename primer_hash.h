#ifndef PRIMER_HASH_H
#define PRIMER_HASH_H
#include <iostream>
#include <vector>

class primer_hash
{
    public:
        primer_hash(std::vector<int> _keys);
        virtual ~primer_hash();
    protected:
    private:
        std::vector<int> table;
        std::vector<int> keys;
        std::pair<int,int> genAB(int p);
        int hashT1(int p, int a, int b, int m, int key);
};

#endif