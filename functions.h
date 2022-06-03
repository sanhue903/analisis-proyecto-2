#ifndef FUNC_H
#define FUNC_H
#include <iostream>
#include <utility>
#include <vector>
#include <math.h>

#define PRIME 13

class func{
    public:
        std::pair<int,int> genAB(int);
        int hash(std::pair<int,int>,int,int,int);
        long long stringToInteger(std::string);

};

#endif