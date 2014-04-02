#include <cstdio>
#include <iostream>
#include <sstream>
#include "user.hpp"
#include "server.hpp"
#include "distributor.hpp"
using namespace std;

int main(int agrc, char **argv)
{
    const int user_sz = atoi(argv[1]);
    const int server_sz = atoi(argv[2]);
    Distributor::cache_size = atoi(argv[3]);
    
    User u[user_sz];
    Server s[server_sz];
    
    Distributor d;
   
    vector<User*>& user_list=User::getUserList();
	
	User* ptr = user_list[0];

    for(int i=0;i<user_list.size();++i)
        cout<<"User "<<i<<" has id : "<< (ptr+i)->getUserId()<<endl;

    for(int i=0;i<user_sz;++i)
    {
        vector<long long int> dest;
        for(int j=0;j<rand()%user_sz+1;++j)
            dest.push_back(u[rand()%user_sz].getUserId());
        u[i].sendMsg("Hello",u[i].getUserId(),dest);
        if(i==2)
            u[i].sendMsg("Hello",u[i].getUserId(),dest);

        u[i].requestFromDistributor(dest,d);
    }

    Server::listServers();

    for(int i=0;i<user_sz;++i)  
    {
        cout<<"User : "<<u[i].getUserId()<<" sends to \n";
        u[i].showDestIdList();
        cout<<endl<<endl;
    }

    for(int i=0;i<user_sz;++i)
        cout<<"\nUser "<<i<<" has "<<u[i].getMsgCount()<<" msgs to send.\n";
    cout<<endl<<endl;

    d.showRequests();

    int queue_size = d.getRequestCount();
    cout<<"\nQueue size of distributor : "<<queue_size<<endl;
    cout<<endl;
    for(int i=0;i<queue_size;++i) 
        cout<<"Out-going Link for destination "<<d.getDestId(i)<<" is : "<<d.distributorLookup(d.getDestId(i))<<endl<<endl;

    cout<<"Total Requests      : "<<Distributor::distributor_served_count+Distributor::server_served_count<<endl<<endl;
    cout<<"Server Served       : "<<Distributor::server_served_count<<endl<<endl;
    cout<<"Distributor Served  : "<<Distributor::distributor_served_count<<endl<<endl;

    cout<<"Distributor Served Percentage : "<<double(Distributor::distributor_served_count)/(Distributor::distributor_served_count+Distributor::server_served_count)*100<<endl<<endl;

    return 0;
}
