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

int Distributor::getMsgCount()
{
    return request_queue.size();
}

void Distributor::showRequests()
{
    for(int i=0;i<request_queue.size();++i)
        cout<<"Requested Link for Destination : "<<request_queue[i]<<endl;
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
