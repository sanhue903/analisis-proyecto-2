#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <string>
#include "primer_hash.h"

primer_hash::primer_hash(std::vector<std::string> _keys)
{
    keys = _keys;
    size_t size = keys.size();
    table = std::vector<int>(size,0);
}

std::pair<int,int> primer_hash::genAB(int p)
{
    std::srand(time(NULL));
    int a = std::rand() % p;
    int b = std::rand() % p;
    return std::make_pair(a,b);
}

int primer_hash::hashT1(int p, int a, int b, int m,long long key)
{
    return ((a * key + b) % p) % m;
}

bool primer_hash::test()
{
    std::pair<int,int> ab = genAB(101);
    
    for(int i = 0; i < table.size(); i++)
    {
        table[hashT1(101,ab.first,ab.second,table.size(),stringToInteger(keys[i]))]++;
    }

    /*
    *   Probando si cumple con la sumatoria de C_i al cuadrado menor a 4n.
    */
    int sum = 0;
    for(int i = 0; i < table.size(); i++)
    {
        sum += pow(table[i],2);
        std::cout << table[i] << std::endl;
    }
    std::cout << sum << std::endl;
    return true;
}

long long primer_hash::stringToInteger(std::string key)
{
    size_t sum;
    for (int i = 0; i < key.length(); i++)
    {
        sum += (key[i] * (int)pow(31, i)) % table.size();
    }
    return sum % 100;
}