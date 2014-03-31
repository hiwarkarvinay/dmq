#include "distributor.hpp"

Distributor::Distributor()
{
   id = Id::generateId(); 
}

Distributor::~Distributor()
{

}

long long int Distributor::getDistributorId()
{
    return id;
}

int Distributor::getRequestCount()
{
    return request_queue.size();
}

void Distributor::showRequests()
{
    for(int i=0;i<request_queue.size();++i)
        cout<<"Requested Link for Destination : "<<request_queue[i]<<endl;
}

long long int Distributor::distributorLookup(long long int dest_id)
{
    
    lookup[1189641421] = 2014;
    map<long long int,long long int>::iterator lookup_itr;
    lookup_itr=lookup.find(dest_id);
    if(lookup_itr!=lookup.end()) {
//        cout<<"Found";
        return lookup_itr->second;
    }
    else
        return -1;
}

long long int Distributor::getDestId(int i)
{
//    static int i=1;
    long long int dest_id = request_queue[request_queue.size()-i-1];
//    request_queue.pop_back();
  //  ++i;
    return(dest_id);
}

/*void Distributor::showDestLink()
{
    for(int i=0;i<msg_queue.front().second.second.size();++i)
        cout<<"Dest ID : "<<msg_queue.front().second.second[i]<<endl;
}

void Distributor::sendMsg(string msg,long long int src_id,vector<long long int> &dest_id)
{
//    for(int i=0;i<dest_id.size();++i)
        msg_queue.push(make_pair(msg,make_pair(src_id,dest_id)));
}*/


void Distributor::enqueuerequest(long long int dest_id)
{
    request_queue.push_back(dest_id);   
}
