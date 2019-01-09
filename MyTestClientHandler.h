#ifndef SECONDPART_MYTESTCLIENTHANDLER_H
#define SECONDPART_MYTESTCLIENTHANDLER_H

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <strings.h>
#include <cstring>
#include "ClientHandler.h"

#define SOCK_READ_ERR "ERROR reading from socket"

class MyTestClientHandler: public ClientHandler {
//needs to be UPDATED
    void handleClient (int socket) {
        char buffer[256];
        bzero(buffer, 256);
        int n;


        n = read(socket, buffer, 255); //read 255 bytes

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        //while client does not send "end", read !
        while (strcmp(buffer, "end")) {
            n = read(socket, buffer, 255);
            while (buffer[0] != '\n') {
                if (n < 0) {
                    perror(SOCK_READ_ERR);
                    exit(1);
                }


            }
            close(socket);
        }

    }

};


#endif //SECONDPART_MYTESTCLIENTHANDLER_H
