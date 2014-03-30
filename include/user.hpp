#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <queue>
#include <utility>
#include "id.hpp"

using namespace std;
class User
{
    private:
        long long int id;
        queue<pair<string, long long int> > msg_queue;
    public:
        User();
        ~User();
        long long int getUserId();
        int getMsgCount();
        void sendMsg(string msg,long long int src_id,long long int dest_id);
};
