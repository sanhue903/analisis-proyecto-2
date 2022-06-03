#ifndef FUNC_H
#define FUNC_H
#include <iostream>
#include <utility>
#include <vector>
#include <math.h>

#define PRIME 31

class func{
    public:
        static std::pair<int,int> genAB(int);
        static int hash(std::pair<int,int>,int,int,long long);
        static long long stringToInteger(std::string);
        void deleteDuplicates(std::vector<std::string>*);

};

#endif