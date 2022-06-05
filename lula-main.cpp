#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <set>
#include "primer_hash.h"

int main()
{
    std::vector<std::string> vec;
    std::set<std::string> st;
    std::ifstream file_in("genomas/100000-genomes.txt");
    if(!file_in) {}

    std::string s;
    while(std::getline(file_in, s)) st.insert(s);

    for(std::set<std::string>::iterator it = st.begin(); it != st.end(); it++)
    {
        vec.push_back(*it);
    }
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0,PRIME - 1);
    primer_hash * ph = new primer_hash(distribution, generator, vec);
    ph->buildTable();
    

    return 0;
}