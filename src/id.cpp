#include "id.hpp"

Id::Id()
{

}

Id::~Id()
{

}

long long int Id::generateId()
{
    long long int id; 
    set<long long int>::iterator idset_itr;
    do
        id = rand()%LLONG_MAX;
    while(idset.find(id)!=idset.end());
    idset.insert(id);
    return id;
}

set<long long int> Id::idset;
