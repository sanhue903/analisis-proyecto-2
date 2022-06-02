#include <iostream>
#include <vector>
#include <utility>
#include "primer_hash.h"

primer_hash::primer_hash(std::vector<int> _keys)
{
    keys = _keys;
}

std::pair<int,int> primer_hash::genAB(int p)
{
    int a = std::rand() % p;
    int b = std::rand() % p;
    
    return std::make_pair(a,b);
}

int primer_hash::hashT1(int p, int a, int b, int m, int key)
{
    return ((a * key + b) % p) % m;
}