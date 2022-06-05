#include "primer_hash.h"

primer_hash::primer_hash(std::uniform_int_distribution<int> _distribution, std::default_random_engine _generator,std::vector<std::string> _keys)
{
    table = std::vector<segundo_hash>(keys.size());
    int prime = PRIME;

    distribution = _distribution;
    generator = _generator;
    keys = _keys;
}

std::pair<int,int> primer_hash::genAB(int p)
{
    int a = distribution(generator);
    int b = distribution(generator);
    return std::make_pair(a,b);
}

int primer_hash::hashT1(int p, std::pair<int,int> ab, int m, unsigned long long key)
{
    return ((ab.first * key + ab.second) % p) % m;
}

bool primer_hash::buildTable()
{
    while(true)
    {
        std::vector<int> test(keys.size(),0);
        std::vector<std::vector<std::string> > buckets (_keys.size());
        std::pair<int,int> ab = genAB(prime);
        for(int i = 0; i < test.size(); i++)
        {
            int hash = hashT1(prime,ab,test.size(),stringToInt(keys[i]));
            test[hash]++;
            buckets[hash].push_back(keys[i]);
        }

        int sum = 0;
        for(int i = 0; i < test.size(); i++) 
        {
            sum += pow(test[i],2);
        }

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

unsigned long long primer_hash::stringToInt(std::string key)
{
    size_t sum;
    for(int i = 0; i < key.size(); i++)
    {
        sum += (key[i] * (int)pow(11, i));
    }
    return sum;
}

segundo_hash primer_hash::buildTable2(std::vector<std::string> str_vr)
{
    segundo_hash * sh = new segundo_hash(str_vr);
    sh->makeTable();
    return * sh;
}
