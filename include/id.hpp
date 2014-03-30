#ifndef __ID_H_INCLUDED__
#define __ID_H_INCLUDED__

#include <cstdlib>
#include <set>
#include <climits>
#include <iostream>
using namespace std;

class Id
{
    private:
        static set<long long int> idset;
    public:
        Id();
        ~Id();
        static long long int generateId();
};
#endif
