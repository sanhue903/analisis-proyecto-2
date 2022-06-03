#include "segundo_hash.h"

hashT2::hashT2(std::vector<long long> _keys){
    ab = func::genAB(PRIME);
    m = _keys.size();
    

    makeTable(_keys);
}


void hashT2::makeTable(std::vector<long long> _keys){
    std::vector<int> aux(m,0);

    std::vector<long long>::iterator it = _keys.begin();
    std::vector<long long>::iterator end = _keys.end();

    int pos = 0;
    while (it != end){
        pos = func::hash(ab,PRIME,m,*it);
        std::cout<<pos<<std::endl;

        if (aux[pos] != 0){
            it = _keys.begin();
            ab = func::genAB(PRIME);
            std::cout<<" nuevos numeros; "<<ab.first<<' '<<ab.second<<std::endl;

            std::vector<int> aux2(m,0);
            aux = aux2;
             
            continue;
        }
               
        aux[pos] = *it;
        it++;
    }

    keys = aux;
}

std::pair<std::pair<int,int>,int> hashT2::returnTrio(){
    std::pair<std::pair<int,int>,int> trio(ab,m);
    return trio; 
}

void hashT2::imprimir(){
    
    std::vector<int>::iterator it = keys.begin();
    std::vector<int>::iterator end = keys.end();

    while(it != end){
        std::cout<<*it<<std::endl;
        it++;
    }
}