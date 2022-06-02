#ifndef HASHT1_H
#define HASHT1_H
#include <iostream>
#include <vector>

class hashT1
{
    public:
        hashT1(std::vector<int> _keys);
        virtual ~hashT1();
    protected:
    private:
        std::vector<int> table;
        std::vector<int> keys;
        genAB(int p);

};

#endif