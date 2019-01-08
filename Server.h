#ifndef SECONDPART_SERVER_H
#define SECONDPART_SERVER_H


namespace server_side {
    class Server {
        void open(int port, ClientHandler c);
        void stop();
    };
}



#endif //SECONDPART_SERVER_H
