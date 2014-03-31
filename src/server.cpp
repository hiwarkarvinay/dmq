#include "server.hpp"
#include "user.hpp"
Server::Server()
{
    id = Id::generateId(); 
    server_list.push_back(this);
	vector<User*>& user_list=User::getUserList();
	
	User* ptr = user_list[0];

    for(int i=0;i<user_list.size();++i)
        lookup[(ptr+i)->getUserId()] = rand()%LLONG_MAX;
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

void Server::listServers()
{
    cout<<endl;
    for(int i=0;i<server_list.size();++i) 
        cout<<"Server "<<i<<" has ID : "<<server_list[i]->id<<endl;
    cout<<endl<<endl;;
}

long long int Server::searchLink(long long int dest_id)
{
    for(int i=0;i<server_list.size();++i)
    {
        map<long long int,long long int>::iterator lookup_itr;
        lookup_itr=server_list[i]->lookup.find(dest_id);
        if(lookup_itr!=server_list[i]->lookup.end()) {
            cout<<"Found Link at server\n";
            return lookup_itr->second;
        }
        else {
            cout<<"No Link found at Servers, Destination Not Alive\n";
            return -1;
        }   
    }
}

vector<Server*> Server::server_list;
