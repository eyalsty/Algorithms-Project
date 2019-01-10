#include "MyTestClientHandler.h"

std::string MyTestClientHandler::getLineFromSocket(int socketNum) {
    char buffer[256];
    bzero(buffer, 256);
    int n;

    n = read(socketNum, buffer, 256); //read 256 bytes (1 line)
    if (n < 0) {
        perror(SOCK_READ_ERR);
        exit(1);
    }
    return (std::string) buffer;
}

void MyTestClientHandler::handleClient(int socketNum) {
    std::string result;
    std::string line = getLineFromSocket(socketNum);
    int n;
    while (line != "end") {
        std::cout << "received: " << line << std::endl; //indication for us
        //get solution
        if (this->cacheManager->isSolutionExists(line)) {
            result = cacheManager->getSolutionFor(line);
        } else {
            result = this->solver->solve(line);
            this->cacheManager->saveSolution(line, result);
        }

        /* Send the solution to the client */
        n = write(socketNum, result.c_str(), result.size());
        if (n < 0) {
            perror(WRITE_ERR);
            exit(1);
        }
        std::cout << "result: " << result << std::endl; //indication for us
        //get next line
        line = getLineFromSocket(socketNum);
    }
}