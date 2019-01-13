#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "MazeMatrix.h"
#include "BFS.h"
#include "Astar.h"
#include "MyClientHandler.h"
#include "DFS.h"
#include "BestFirstSearch.h"
#include "SearchSolver.h"

using namespace std;


int main() {

    // checks for the MazeMatrix Class !
    vector<string> matrix = {"1,2,50,4",
                             "0,6,7,50",
                             "1,10,11,50",
                             "1,11,1,16",
                             "3,3",
                             "0,0"};
    Server *server = new MySerialServer;
    ISearcher *searcher = new BestFirstSearch;
    Solver<Searchable*,vector<MyState*> >* solver = new SearchSolver(searcher);
    CacheManager* cm = new FileCacheManager();

    ClientHandler* ch = new MyClientHandler(solver,cm);
    server->open(12345,ch);

    delete server;
    return 0;
}