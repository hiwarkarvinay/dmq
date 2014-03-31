#ifndef __SERVER_H_INCLUDED__
#define __SERVER_H_INCLUDED__
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <queue>
#include <utility>
#include "id.hpp"
#include <map>
#include <vector>
using namespace std;
class Server
{
    private:
        long long int id;
        vector<long long int> request_queue;
        map<long long int,long long int> lookup;
        queue<pair<string, pair<long long int,long long int> > > msg_queue;
        static vector<Server*> server_list;
    public:
        Server();
        ~Server();
        long long int getServerId();
        int getMsgCount();
        void sendMsg(string msg,long long int src_id,vector<long long int> &dest_id);
        static long long int searchLink(long long int dest_id);
        static void listServers();
};
#endif
