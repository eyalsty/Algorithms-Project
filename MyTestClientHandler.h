#ifndef SECONDPART_MYTESTCLIENTHANDLER_H
#define SECONDPART_MYTESTCLIENTHANDLER_H

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <strings.h>
#include <string>
#include <cstring>
#include <iostream>


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

#define SOCK_READ_ERR "ERROR reading from socket"
#define WRITE_ERR "ERROR writing to socket"

class MyTestClientHandler : public ClientHandler {
private:
    Solver<std::string, std::string> *solver;
    CacheManager *cacheManager;

    std::string getLineFromSocket(int socketNum);

public:
    MyTestClientHandler(Solver<std::string, std::string> *s, CacheManager *ch) : solver(s), cacheManager(ch) {};

    void handleClient(int socket) override;


};

#endif