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
#include "MyParallelServer.h"

using namespace std;


int main(int argc, char* argv[]) {
   int port = stoi(argv[1]);
   Server* server= new MyParallelServer();

   ISearcher* astar = new Astar();
   Solver<Searchable*,vector<MyState*> >* solver = new SearchSolver(astar);
   CacheManager* cm = new FileCacheManager();

   ClientHandler* clientHandler = new MyClientHandler(solver,cm);
   server->open(port,clientHandler);

   delete server;
   delete astar;
   delete solver;
   delete cm;
   delete clientHandler;


    return 0;
}