#include "primer_hash.h"

hashT1::hashT1(std::vector<std::string> keys){
    table = std::vector<hashT2>(keys.size());
    buildTable(keys);
}

void hashT1::buildTable(std::vector<std::string> _keys){
    std::vector<int> test(_keys.size(),0);
    std::vector<int> positions;
    
    std::vector<unsigned long long> integers;

    std::vector<std::string>::iterator it = _keys.begin();
    std::vector<std::string>::iterator end = _keys.end();
    
    while (it != end){
        integers.push_back(func::stringToInteger(*it));
        it++;
    }

    std::vector<unsigned long long>::iterator intIt = integers.begin();
    std::vector<unsigned long long>::iterator intEnd = integers.end();

    int tamTest = test.size();
    int pos = 0;
    int sum = tamTest*4;
    while(sum >= tamTest*4){
        ab = func::genAB();

        positions.clear();
        intIt = integers.begin();

        while(intIt != intEnd){
            pos = func::hash(ab,PRIME,tamTest,*intIt);
            positions.push_back(pos);
            test[pos]++;
            intIt++;
        }

        sum = 0;
        for(int i = 0; i < tamTest; i++) 
            sum += pow(test[i],2);
    }
    
    std::vector<std::vector<std::string>>buckets(tamTest);

    for (int i = 0;i < tamTest;i++)
        buckets[positions[i]].push_back(_keys[i]);
    

    for (int i = 0;i < tamTest;i++){
        if (!buckets[i].empty())
            table[i] = hashT2(buckets[i]);
    }
    
}

