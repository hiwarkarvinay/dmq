#ifndef __DISTRIBUTOR_H_INCLUDED__
#define __DISTRIBUTOR_H_INCLUDED__
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <queue>
#include <utility>
#include "id.hpp"
#include "distributor.hpp"
#include <vector>
#include <map>
using namespace std;
class Distributor
{
    private:
        long long int id;
        vector<long long int>  request_queue; // destinations for a msg
        map<long long int,long long int> lookup;  //dest_id,link_id - which dest->on which link
        map<long long int,long long int> service_queue;  //dest_id,link_id-> which dest_id is processed

    public:
        Distributor();
        ~Distributor();
        long long int getDistributorId();
        int getMsgCount();
        void enqueuerequest(long long int);
        void showRequests();
        //void sendMsg(string msg,long long int src_id,vector<long long int> &dest_id);
        //void showDestLink();
};
#endif
