#include "functions.h"

std::pair<int,int> func::genAB(int p){
    int a = std::rand()%p;
    int b = std::rand()%p;
    
    return std::make_pair(a,b);
}

int func::hash(std::pair<int,int> ab,int p,int m,unsigned long long key){
    unsigned long long pos = (unsigned long long)(ab.first*key + ab.second);
    std::cout<<pos<<std::endl;
    pos = (pos%p)%m;
    return pos;
}

unsigned long long func::stringToInteger(std::string key){
    
    unsigned long long integer = 0;
    /*unsigned long long aux = 0;
    
    int i = 0;
    int end = key.size();

    while(i != end){
        aux = key[i];
        integer+= aux*func::pow(3,i);

        i++;
    }
    */

    std::hash<std::string> hasher;
    integer = hasher(key);
    
    return integer;
}

unsigned long long func::pow(int _base,int exp){
    if (exp == 0) 
        return 1;

    unsigned long long base = _base;
    for (int i = 0;i < exp;i++)
        base*= base;
    

    return base;
}
