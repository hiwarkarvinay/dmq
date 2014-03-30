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
