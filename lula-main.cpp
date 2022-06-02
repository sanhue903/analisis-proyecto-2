#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> vec;

    std::ifstream file_in("100-genomes.txt");
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
}