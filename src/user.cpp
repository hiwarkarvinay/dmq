#include "user.hpp"

User::User()
{
   id = Id::generateId(); 
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

void User::sendMsg(string msg,long long int src_id,long long int dest_id)
{
    msg_queue.push(make_pair(msg,dest_id));
}
