#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include "primer_hash.h"

int main()
{
    std::vector<std::string> vec;
    std::ifstream file_in("genomas/100000-genomes.txt");
    if(!file_in) {}

    std::string s;
    while(std::getline(file_in, s)) vec.push_back(s);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0,PRIME - 1);
    primer_hash * ph = new primer_hash(distribution, generator, vec);
    ph->buildTable();

    return 0;
}