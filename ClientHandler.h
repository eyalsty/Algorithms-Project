#ifndef SECONDPART_CLIENTHANDLER_H
#define SECONDPART_CLIENTHANDLER_H

class ClientHandler {

public:
    virtual void handleClient(int socket) = 0;

};


#endif //SECONDPART_CLIENTHANDLER_H
