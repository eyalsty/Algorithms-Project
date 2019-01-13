#include "MySerialServer.h"

void *MySerialServer::communicateClients(void *arg) {
    auto *params = (ServerParams *) arg;
    int serverSocket, clientSocket, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    /* First call to socket() function */
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket < 0) {
        perror(SOCK_OPEN_ERR);
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(params->port);

    /* Now bind the host address using bind() call.*/
    if (bind(serverSocket, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror(BIND_ERR);
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(serverSocket, 5);
    clilen = sizeof(cli_addr);

    while (!params->server->toStop) {    //while function stop() wasn't called
        std::cout << "wait for new client" << std::endl;

//        timeval timeout;
//        timeout.tv_sec = 15;
//        timeout.tv_usec = 0;
//
//        setsockopt(serverSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));


        /* Accept actual connection from the client */
        clientSocket = accept(serverSocket, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
        std::cout << "connection established" << std::endl;

        if (clientSocket < 0)	{
            if (errno == EWOULDBLOCK)	{
                std::cout << "timeout!" << std::endl;
                //exit(2);
                continue;
            }	else	{
                perror(ACCEPT_ERR);
                exit(3);
            }
        }
        params->client->handleClient(clientSocket);
        close(clientSocket);
        //params->server->stop();
    }
    //there are pointers in struct params , maybe need deletion !!
    delete params;
}

void MySerialServer::open(int portNum, ClientHandler *c) {
    auto *params = new ServerParams;
    params->port = portNum;
    params->client = c;
    params->server = this;
    pthread_t trid;
    pthread_create(&trid, nullptr, communicateClients,
                   params);
    this->thread = trid;
}