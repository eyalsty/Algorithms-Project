#include <iostream>
#include <algorithm>

#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"

using namespace std;


int main() {
    int port = 12347;
    Server * server = new MySerialServer;
    Solver<std::string,std::string> *solver = new StringReverser;
    CacheManager *ch = new FileCacheManager;
    ClientHandler *c = new MyTestClientHandler(solver,ch);
    server->open(port, c);
    delete server;
    delete ch;
    return 0;
}