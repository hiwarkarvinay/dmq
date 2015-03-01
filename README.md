=======
DMQ - Distributed Messaging Queue
=======
###What is it ?

**This project has three main components**
+ User
+ Server
+ Distributor (cache)

Let's say a user A wants to communicate with another user B. 
But to do that, the user A must have the destination address of user B. So this request would go to the server to fetch the destination address of user B.

So each time, the users' request goes to the server.

But if we keep a distributor(aka cahce) in between the users and the server, which caches the addresses of the requested destination, then we can return the cached address from distributor if in future we see the same request.

So to simulate this behavior we maintained a variable cache size and calculated the efficiency of the distributor i.e the cache as  :

![Efficiency=Distributor served requests/Total requests](https://raw.githubusercontent.com/hiwarkarvinay/dmq/final/doc/efficiency.png)

As we increase the cache size, the efficiency increases.

* To give it a try follow

```
$ git clone https://github.com/hiwarkarvinay/dmq.git
$ cd dmq
$ ./dmq.sh --build
$ ./dmq.sh --run no_of_users no_of_servers cache_size
```
Example
```
$ ./dmq.sh --run 25 4 12
```

**Further improvements**

A Time to live (TTL) parameter can be added to each cached entry to update the stale information
