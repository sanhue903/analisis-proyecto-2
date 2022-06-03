#include "functions.h"

std::pair<int,int> func::genAB(int p){
    int a = std::rand()%p;
    int b = std::rand()%p;
    
    return std::make_pair(a,b);
}

int func::hash(std::pair<int,int> ab,int p,int m,int key){
    return ((ab.first*key + ab.second)%p)%m;
}

long long func::stringToInteger(std::string key){
    long long integer = 0;
    std::string::iterator it = key.begin();
    std::string::iterator end = key.end();

    int i = 0;
    while(it != end){
        integer+= (long long)pow(PRIME,i);
    }

    return integer;
}

