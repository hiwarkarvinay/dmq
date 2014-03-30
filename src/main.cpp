#include <cstdio>
#include <iostream>
#include "user.hpp"
using namespace std;

int main(int agrc, char **argv)
{
    User u[10];

    for(int i=0;i<10;++i)
    {
        long long int id = u[i].getUserId();
        cout<<"ID of user is : "<<id<<endl;
        u[0].sendMsg("hi",id,id);
    }

    cout<<"Msg count : "<<u[0].getMsgCount();

    return 0;
}
