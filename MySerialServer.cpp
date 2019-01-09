
#include "MySerialServer.h"

int openSocket(int portNum) {
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror(SOCK_OPEN_ERR);
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portNum);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    return newsockfd;
}

void *MySerialServer::waitForClients(void *arg) {
    auto *params = (ServerParams *) arg;
    while (!params->server->toStop) { //while function stop() wasnt called

        int newSock = openSocket(params->port);//open socket and wait for client
        //client was connected
        params->client->handleClient(newSock);

}

void MySerialServer::open(int portNum, ClientHandler *c) {
    auto *params = new ServerParams;
    params->port = portNum;
    params->client = c;
    params->server = this;
    pthread_t trid;
    pthread_create(&trid, nullptr, waitForClients,
                   params);
    this->thread = trid;


}