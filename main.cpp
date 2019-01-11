#include <iostream>
#include <algorithm>

#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "MazeMatrix.h"

using namespace std;


int main() {
    int port = 12347;
    Server *server = new MySerialServer;
    Solver<std::string, std::string> *solver = new StringReverser;
    CacheManager *ch = new FileCacheManager;
    ClientHandler *c = new MyTestClientHandler(solver, ch);
    server->open(port, c);
    delete server;
    delete ch;

    // checks for the MazeMatrix Class !
    /*vector<string> matrix = {"1,2,3,4",
                             "21,22,23,24",
                             "1,1,1,1",
                             "5,5,5,335",
                             "3,3",
                             "3,3"};
    Searchable<Id>* s = new MazeMatrix(matrix);
    State<Id> node(Id(3,1),21);
    vector<State<Id>> adj = s->getAllPossibleStates(node);*/

    return 0;
}