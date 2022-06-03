#include "functions.h"

std::pair<int,int> func::genAB(int p){
    int a = std::rand()%p;
    int b = std::rand()%p;
    
    return std::make_pair(a,b);
}

int func::hash(std::pair<int,int> ab,int p,int m,int key){
    return ((ab.first*key + ab.second)%p)%m;
}

long long func::stringToInterger(std::string key){
    long long interger = 0;
    std::string::iterator it = key.begin();
    std::string::iterator end = key.end();

    int i = 0;
    while(it != end){
        interger+= (long long)pow(PRIME,i);
    }

    return interger;
}

