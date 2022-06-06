#include "primer_hash.h"

primer_hash::primer_hash(std::uniform_int_distribution<int> _distribution, std::default_random_engine _generator,std::vector<std::string> _keys)
{
    table = std::vector<std::vector<std::string> >(_keys.size());
    ABs = std::vector<std::pair<int,int> > (_keys.size());

    distribution = _distribution;
    generator = _generator;
    keys = _keys;

    avgTries2 = 0;
    tries1 = 0;
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

        tries1++;
        if(sum <= (4 * keys.size()))       
        {
            _ab = ab;
            for(int i = 0; i < buckets.size(); i++)
            {
                std::pair<std::vector<std::string>, std::pair<int,int> > pr = buildTable2(buckets[i]);
                table[i] = pr.first;
                ABs[i] = pr.second;
            }
            return true;
        }
    }
}

std::pair<std::vector<std::string>,std::pair<int,int> > primer_hash::buildTable2(std::vector<std::string> str_vr)
{
    int avg = 1;
    int bucketSize = str_vr.size() * str_vr.size();
    std::vector<std::string> bucket(bucketSize,"_______");

    if(str_vr.size() == 0)           // Caso donde esta vacio, no es necesario calcular un ab
    {
        avgTries2 += avg;
        return make_pair(bucket,std::make_pair(0,0));
    }
    if(str_vr.size() == 1)          // Caso donde solo hay 1 elemento, el tamano es 1 por tanto no se calcula ab
    {
        bucket[0] = str_vr[0];
        avgTries2 += avg;
        return make_pair(bucket,std::make_pair(0,0));
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
                avgTries2 += avg;
            }
            return std::make_pair(bucket,ab);
        }
        avg++;
    }
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
    std::cout << "Tabla 1 creada despues de " << tries1 << " intentos" << std::endl;
    std::cout << "Promedio de intentos de creacion de tabla 2: " << (double)avgTries2/table.size() << " intentos" << std::endl;
    
}

std::string primer_hash::find(std::string s)
{
    int h1 = hashF(PRIME,_ab,table.size(),s);
    if(table[h1].size() == 0)
    {
        std::cout << "No se encuentra" << std::endl;
        return "";
    }
    if(table[h1].size() == 1)
    {
        std::cout << "Encontrado: " << table[h1][0] << " en posicion " << h1 << " " << 0 << std::endl;
        return table[h1][0];
    }
    else
    {
        int h2 = hashF(PRIME,ABs[h1],table[h1].size(),s);
        std::cout << "Encontrado: " << table[h1][h2] << " en posicion " << h1 << " " << h2 << std::endl;
        return table[h1][h2];
    }
}


