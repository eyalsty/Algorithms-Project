#ifndef SECONDPART_MYSERIALSERVER_H
#define SECONDPART_MYSERIALSERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <pthread.h>
#include <iostream>

#include "Server.h"

#define SOCK_OPEN_ERR "ERROR opening socket"
#define ACCEPT_ERR "ERROR on accept"
#define BIND_ERR "ERROR on binding"

using namespace server_side;

class MySerialServer : public Server {
private:
    bool toStop = false;
    pthread_t thread;

public:
    struct ServerParams {
        int port;
        ClientHandler *client;
        MySerialServer *server;
    };

    //opens new server with the given port and waits for client
    void open(int portNum, ClientHandler *c);

    static void *communicateClients(void *arg);

    void stop() {
        this->toStop = true;
    }

    ~MySerialServer() {
        pthread_join(thread, nullptr);
    }
};
#endif