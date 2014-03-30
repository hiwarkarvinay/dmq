#ifndef __USER_H_INCLUDED__
#define __USER_H_INCLUDED__
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <queue>
#include <utility>
#include "id.hpp"
#include "distributor.hpp"
#include <vector>
using namespace std;
class User
{
    private:
        long long int id;
        queue<pair<string, pair<long long int,vector<long long int> > > > msg_queue;
    public:
        User();
        ~User();
        long long int getUserId();
        int getMsgCount();
        void sendMsg(string msg,long long int src_id,vector<long long int> &dest_id);
        void requestFromDistributor(vector<long long int> &dest_id,Distributor &dist);
        void showDestIdList();
};
#endif
