#include "segundo_hash.h"

hashT2::hashT2(std::vector<std::string> _keys){
    ab = func::genAB(PRIME);

    m = _keys.size();
    m*= m;
    
    makeTable(_keys);
}


void hashT2::makeTable(std::vector<std::string> _keys){
    std::vector<std::string> aux(m,AVAILABLE);
    std::vector<unsigned long long> integers;

    std::vector<std::string>::iterator it = _keys.begin();
    std::vector<std::string>::iterator end = _keys.end();
    
    while (it != end){
        integers.push_back(func::stringToInteger(*it));
        it++;
    }

    std::vector<unsigned long long>::iterator intIt = integers.begin();
    it = _keys.begin();
    
    unsigned long long integer = 0;
    int pos = 0;
    
    while (it != end){
        integer = *intIt;
        pos = func::hash(ab,PRIME,m,integer);
        std::cout<<*it + ' '<<pos<<std::endl;

        if (aux[pos] != AVAILABLE){
            it = _keys.begin();
            intIt = integers.begin();

            std::vector<std::string> aux2(m,AVAILABLE);
            aux = aux2;

            ab = func::genAB(PRIME);
            std::cout<<" nuevos numeros; "<<ab.first<<' '<<ab.second<<std::endl;
                     
            continue;
        }
               
        aux[pos] = *it;
        it++;
        intIt++;
    }

    keys = aux;
}

int hashT2::search(std::string key){
    return func::hash(ab,PRIME,m,func::stringToInteger(key));
}

void hashT2::imprimir(){
    
    std::vector<std::string>::iterator it = keys.begin();
    std::vector<std::string>::iterator end = keys.end();

    while(it != end){
        std::cout<<*it<<std::endl;
        it++;
    }
}