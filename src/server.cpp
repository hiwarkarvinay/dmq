#include "server.hpp"

Server::Server()
{
   id = Id::generateId(); 
}

Server::~Server()
{

}

long long int Server::getServerId()
{
    return id;
}

int Server::getMsgCount()
{
    return msg_queue.size();
}

void Server::sendMsg(string msg,long long int src_id,vector<long long int> &dest_id)
{
    for(int i=0;i<dest_id.size();++i)
        msg_queue.push(make_pair(msg,make_pair(src_id,dest_id[i])));
}
