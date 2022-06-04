#include "segundo_hash.h"

hashT2::hashT2(std::vector<std::string> _keys){
    ab = func::genAB(PRIME);
    m = _keys.size();
    m*= m;
    

    makeTable(_keys);
}


void hashT2::makeTable(std::vector<std::string> _keys){
    std::vector<std::string> aux(m,AVAILABLE);

    std::vector<std::string>::iterator it = _keys.begin();
    std::vector<std::string>::iterator end = _keys.end();

    int pos = 0;
    unsigned long long integer = 0;
    
    //std::vector<std::string>::iterator auxit = aux.begin();
    //std::vector<std::string>::iterator auxend = aux.end();

    while (it != end){
        integer = func::stringToInteger(*it);
        pos = func::hash(ab,PRIME,m,integer);
        //std::cout<<*it + ' '<<pos<<std::endl;

        if (aux[pos] != AVAILABLE){
            it = _keys.begin();
            ab = func::genAB(PRIME);
            std::cout<<" nuevos numeros; "<<ab.first<<' '<<ab.second<<std::endl;
        /*   
            auxit = aux.begin();
            auxend = aux.end();
            std::cout<<"////////////////////////////"<<std::endl;
            while(auxit != auxend){
                std::cout<<*auxit<<std::endl;
                auxit++;         
            }       
        */  
            std::vector<std::string> aux2(m,AVAILABLE);
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
    
    std::vector<std::string>::iterator it = keys.begin();
    std::vector<std::string>::iterator end = keys.end();

    while(it != end){
        std::cout<<*it<<std::endl;
        it++;
    }
}