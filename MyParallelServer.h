#ifndef SECONDPART_MYPARALLELSERVER_H
#define SECONDPART_MYPARALLELSERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <pthread.h>
#include <iostream>
#include <queue>

#include "Server.h"

#define SOCK_OPEN_ERR "ERROR opening socket"
#define ACCEPT_ERR "ERROR on accept"
#define BIND_ERR "ERROR on binding"


class MyParallelServer : public server_side::Server{
private:
    bool toStop = false;
    std::queue<pthread_t> threads;

public:
    struct ServerParams {
        int socketID;
        ClientHandler *client;
    };

    //opens new server with the given port and waits for client
    void open(int portNum, ClientHandler *c) override;

    static void *communicateClients(void *arg);

    void stop() override {
        this->toStop = true;
    }

    ~MyParallelServer() {
        while (!threads.empty()) {
            pthread_t trid = threads.front();
            threads.pop();
            pthread_join(trid, nullptr);
        }
    }

};

#endif //SECONDPART_MYPARALLELSERVER_H