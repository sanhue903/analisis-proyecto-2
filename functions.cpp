#include "functions.h"

std::pair<int,int> func::genAB(){
    int a = std::rand()%PRIME;
    int b = std::rand()%PRIME;
    
    return std::make_pair(a,b);
}

int func::hash(std::pair<int,int> ab,int p,int m,unsigned long long key){
    unsigned long long pos = (unsigned long long)(ab.first*key + ab.second);
    pos = (unsigned long long)(pos%p)%m;
    return (int)pos;
}

unsigned long long func::stringToInteger(std::string key){
    
    unsigned long long integer = 0;
    unsigned long long aux = 0;
    int aux2 = 0;
    
    int i = 0;
    int end = key.size();
    while(i != end){
        aux = key[i];
        switch(key[i]){
            case 'A':
                aux2 = 0;
                break;
            case 'C':
                aux2 = 1;
                break;
            case 'G':
                aux2 = 2;
                break;
            case 'T':
                aux2 = 3;
                break;
        }
        
        integer+= aux*func::pow(aux2,i);

        i++;
    }
    
    //maximo unsigned long long  = 18446744073709551615
    //rango de numeros generados = 307788308742004804
    return integer;
}

unsigned long long func::pow(int _base,int exp){
    if (exp == 0) 
        return 1;

    unsigned long long base = _base;
    for (int i = 0;i < exp;i++)
        base*= _base;
    

    return base;
}
