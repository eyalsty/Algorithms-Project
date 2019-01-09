#ifndef SECONDPART_CLIENTHANDLER_H
#define SECONDPART_CLIENTHANDLER_H

class ClientHandler {

public:
    virtual void handleClient(int socket) = 0;

    virtual ~ClientHandler(){}
};
#endif