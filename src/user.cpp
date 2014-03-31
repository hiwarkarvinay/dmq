#include "user.hpp"

User::User()
{
   id = Id::generateId(); 
   user_list.push_back(this);
}

User::~User()
{

}

long long int User::getUserId()
{
    return id;
}

int User::getMsgCount()
{
    return msg_queue.size();
}

void User::showDestIdList()
{
    for(int i=0;i<msg_queue.front().second.second.size();++i)
        cout<<"Dest ID : "<<msg_queue.front().second.second[i]<<endl;
}

void User::sendMsg(string msg,long long int src_id,vector<long long int> &dest_id)
{
//    for(int i=0;i<dest_id.size();++i)
        msg_queue.push(make_pair(msg,make_pair(src_id,dest_id)));
}

void User::requestFromDistributor(vector<long long int> &dest_id,Distributor &dist)
{
    for(int i=0;i<dest_id.size();++i)
        dist.enqueuerequest(dest_id[i]);    
}
vector<User*>& User::getUserList()
{
    return User::user_list;
}

vector<User*> User::user_list;
