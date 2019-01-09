#ifndef SECONDPART_SERVER_H
#define SECONDPART_SERVER_H

#include "ClientHandler.h"

namespace server_side {
    class Server {
    public:
        virtual void open(int portNum, ClientHandler *c) = 0;

        virtual void stop() = 0;

        virtual ~Server(){}
    };
}
#endif