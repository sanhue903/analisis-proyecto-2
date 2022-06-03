#include "functions.h"

std::pair<int,int> func::genAB(int p){
    int a = std::rand()%p;
    int b = std::rand()%p;
    
    return std::make_pair(a,b);
}

int func::hash(std::pair<int,int> ab,int p,int m,long long key){
    return ((ab.first*key + ab.second)%p)%m;
}

long long func::stringToInteger(std::string key){
    long long integer = 0;
    long long aux = 0;
    
    int i = 0;
    int end = key.size();

    while(i != end){
        aux = key[i];
        integer+= aux*(long long)pow(11,i);

        i++;
    }
    std::cout<<integer<<std::endl;

    return integer;
}



