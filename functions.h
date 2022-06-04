#ifndef FUNC_H
#define FUNC_H
#include <iostream>
#include <utility>
#include <vector>
#include <math.h>
#include <functional>

#define PRIME 23
#define AVAILABLE "available"

class func{
    public:
        static std::pair<int,int> genAB(int);
        static int hash(std::pair<int,int>,int,int,unsigned long long);
        static unsigned long long stringToInteger(std::string);
        void deleteDuplicates(std::vector<std::string>*);
    private:
        static unsigned long long pow(int,int);

};

#endif