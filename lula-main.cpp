#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "primer_hash.h"

int main()
{
    std::vector<std::string> vec;
    std::ifstream file_in("genomas/100-genomes.txt");
    if(!file_in) {}

    std::string s;
    while(std::getline(file_in, s))
    {
        vec.push_back(s);
    }

    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }

    primer_hash * ph = new primer_hash(vec);
    ph->test();

    return 0;
}