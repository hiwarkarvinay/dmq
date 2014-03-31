#include <cstdio>
#include <iostream>
#include "user.hpp"
#include "server.hpp"
#include "distributor.hpp"
using namespace std;

int main(int agrc, char **argv)
{
    User u[10];
    Server s[10];
    Distributor d;
    
    for(int i=0;i<10;++i)
    {
        vector<long long int> dest;
        for(int j=0;j<2;++j)
            dest.push_back(u[rand()%10].getUserId());
        u[i].sendMsg("Hello",u[i].getUserId(),dest);
        if(i==2)
            u[i].sendMsg("Hello",u[i].getUserId(),dest);

        u[i].requestFromDistributor(dest,d);
    }

    for(int i=0;i<10;++i)  
    {
        cout<<"User : "<<u[i].getUserId()<<" sends to \n";
        u[i].showDestIdList();
        cout<<endl<<endl;
    }

    for(int i=0;i<10;++i)
        cout<<"\nUser "<<i<<" has "<<u[i].getMsgCount()<<" msgs to send.\n";

    d.showRequests();

    int queue_size = d.getRequestCount();
    cout<<"Queue size : "<<queue_size<<endl;
    cout<<endl;
    for(int i=0;i<queue_size;++i) 
        cout<<"Out-going Link for destination "<<d.getDestId(i)<<" is : "<<d.distributorLookup(d.getDestId(i))<<endl;

    return 0;
}
