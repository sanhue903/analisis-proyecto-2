#include "primer_hash.h"

primer_hash::primer_hash(std::uniform_int_distribution<int> _distribution, std::default_random_engine _generator,std::vector<std::string> _keys)
{
    table = std::vector<std::vector<std::string> >(_keys.size());
    ABs = std::vector<std::pair<int,int> > (_keys.size());

    distribution = _distribution;
    generator = _generator;
    keys = _keys;
}

bool primer_hash::buildTable()
{
    while(true)
    {
        std::vector<int> test(keys.size(),0);
        std::vector<std::vector<std::string> > buckets (keys.size());
        std::pair<int,int> ab = genAB(PRIME);
        for(int i = 0; i < test.size(); i++)
        {
            int hash = hashF(PRIME,ab,test.size(),keys[i]);
            test[hash]++;
            buckets[hash].push_back(keys[i]);
        }

        int sum = 0;
        for(int i = 0; i < test.size(); i++)  sum += pow(test[i],2);

        // print statement here to see how many times we try to construct first level
        if(sum <= (4 * keys.size()))       
        {
            _ab = ab;
            for(int i = 0; i < buckets.size(); i++)
            {
                table[i] = buildTable2(buckets[i]);
            }
            return true;
        }
    }
}

std::vector<std::string> primer_hash::buildTable2(std::vector<std::string> str_vr)
{
    int bucketSize = str_vr.size() * str_vr.size();
    std::vector<std::string> bucket(bucketSize,"_______");

    if(str_vr.size() == 0) return bucket;
    if(str_vr.size() == 1)
    {
        bucket[0] = str_vr[0];
        return bucket;
    }

    while(true)
    {
        bool flag = true;
        std::pair<int,int> ab = genAB(PRIME);
        std::vector<int> collisions(bucketSize,0);
        for(int i = 0; i < str_vr.size(); i++)
        {
            int hash = hashF(PRIME,ab,bucketSize,str_vr[i]);
            if(collisions[hash])
            {
                collisions[hash]++;
                flag = false;
            }
            else collisions[hash]++;
        }
        
        if(flag)
        {
            for(int i = 0; i < str_vr.size(); i++)
            {
                bucket[hashF(PRIME,ab,bucketSize,str_vr[i])] = str_vr[i];
            }
            break;
        } 
    }
    return bucket;
}

std::pair<int,int> primer_hash::genAB(int p)
{
    int a = distribution(generator);
    int b = distribution(generator);
    return std::make_pair(a,b);
}

int primer_hash::hashF(int p, std::pair<int,int> ab, int m, std::string key)
{
    return abs(((ab.first * stringToInt(key) + ab.second) % p) % m);
}

int primer_hash::stringToInt(std::string key)
{   
    int sum = 0;
    for(int i = 0; i < key.size(); i++)
    {
        char aux = key[i];
        sum = (sum << 2) | ((aux >> 1) & 3);
    }
    return sum;
}

void primer_hash::printTable()
{
    for(int i = 0; i < table.size(); i++)
    {
        std::cout << i << ": ";
        if(table[i].size() == 0)
        {
            std::cout << "Empty";
        }
        for(int j = 0; j < table[i].size(); j++) std::cout << table[i][j] << " ";
        std::cout << std::endl;
    }
}
