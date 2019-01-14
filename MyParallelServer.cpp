#include "MyParallelServer.h"

void MyParallelServer::open(int portNum, ClientHandler *c) {

////////////////////////////OPEN SERVER SOCKET//////////////////////
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
    serv_addr.sin_port = htons(portNum);

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
    ////////////////////////////////////////////////////////////////////////////

    //////////////////////WAIT ENDLESSLY FOR FIRST CLIENT/////////////////////////////////
    std::cout << "wait for first client" << std::endl;
    /* Accept actual connection from the client */
    clientSocket = accept(serverSocket, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    std::cout << "first connection established" << std::endl;
    ////////////////////////////////////////////////////////////////////////////

    //////////////////// START LOOP : OPEN NEW THREAD FOR CLIENT HANDLING. SET TIMEOUT, AND WAIT FOR NEW CLIENT///////
    while (!this->toStop) {    //while function stop() wasn't called
        auto *params = new ServerParams;
        params->socketID = clientSocket;
        params->client = c;

        pthread_t trid;
        pthread_create(&trid, nullptr, communicateClients,
                       params);
        this->threads.push(trid);

        timeval timeout;
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;

        setsockopt(serverSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));


        /////////////////////WAIT FOR NEW CLIENT//////////////////////////////
        std::cout << "wait for new client" << std::endl;
        clientSocket = accept(serverSocket, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
        if (clientSocket < 0)	{
            if (errno == EWOULDBLOCK)	{
                std::cout << "timeout!" << std::endl;
                break;
            }	else	{
                perror(ACCEPT_ERR);
                exit(3);
            }
        }
        std::cout << "new connection established" << std::endl;
        //WHILE CONNECTING - WAIT INFINITY
        timeout.tv_sec = 0;
        timeout.tv_usec = 0;

        setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
    }
    close(serverSocket);
}


void *MyParallelServer::communicateClients(void *arg) {
    auto *params = (ServerParams *) arg;
    params->client->handleClient(params->socketID);
    close(params->socketID);
    delete params; //there are pointers in struct params , maybe need deletion !!
}