#include <iostream>
#include <algorithm>

#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "MazeMatrix.h"

using namespace std;


int main() {
    /*int port = 12347;
    Server *server = new MySerialServer;
    Solver<std::string, std::string> *solver = new StringReverser;
    CacheManager *ch = new FileCacheManager;
    ClientHandler *c = new MyTestClientHandler(solver, ch);
    server->open(port, c);
    delete server;
    delete ch;*/

    // checks for the MazeMatrix Class !
    vector<string> matrix = {"1,2,3,4",
                             "5,6,7,8",
                             "9,10,11,12",
                             "13,14,15,16",
                             "0,0",
                             "3,3"};
    Searchable *s = new MazeMatrix(matrix);
    State<Id> node(Id(3, 1), 21);
    State<Id> init = s->getInitialState();
    State<Id> goal(Id(3, 3), 16);
    bool t = s->isGoalState(goal);
    vector<State<Id> > v = s->getAllPossibleStates(State<Id>(Id(2, 2), 11));
    delete s;
    return 0;
}