#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <string>
#include <random>
#include "primer_hash.h"

#define PRIME 514249

primer_hash::primer_hash(std::uniform_int_distribution<int> _distribution, std::default_random_engine _generator,std::vector<std::string> _keys)
{
    distribution = _distribution;
    generator = _generator;
    keys = _keys;
    size_t size = keys.size();
    int prime = PRIME;
    table = std::vector<int>(size,0);
}

std::pair<int,int> primer_hash::genAB(int p)
{
    int a = distribution(generator);
    int b = distribution(generator);
    return std::make_pair(a,b);
}

int primer_hash::hashT1(int p, int a, int b, int m,long long key)
{
    return ((a * key + b) % p) % m;
}

bool primer_hash::test()
{
    std::pair<int,int> ab = genAB(prime);
    for(int i = 0; i < table.size(); i++)
    {
        table[hashT1(prime,ab.first,ab.second,table.size(),stringToInt(keys[i]))]++;
    }
    
    /*
    *   Probando si cumple con la sumatoria de C_i al cuadrado menor a 4n.
    */
    int sum = 0;
    for(int i = 0; i < table.size(); i++)
    {
        sum += pow(table[i],2);
        std::cout << table[i] << "\n";
    }
    std::cout << sum << "\n";
    return true;
}

long long primer_hash::stringToInt(std::string key)
{
    size_t sum;
    for (int i = 0; i < key.length(); i++)
    {
        sum += (key[i] * (int)pow(11, i));
    }
    return sum;
}