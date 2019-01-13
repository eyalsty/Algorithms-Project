
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


using namespace std;


int main() {

    // checks for the MazeMatrix Class !
    vector<string> matrix = {"1,2,50,4",
                             "5,6,7,50",
                             "50,10,11,50",
                             "13,14,15,16",
                             "3,3",
                             "0,0"};
    Server *server = new MySerialServer;
    //ClientHandler *ch = MyClientHandler()
    Searchable *searchable = new MazeMatrix(matrix);
    ISearcher *searcher = new BestFirstSearch;
    vector<MyState *> solution = searcher->search(searchable);
    int n = searcher->getEvaluatedCounter();
    stack<string> directions = fromStatesToStrings(solution);
    while (!directions.empty()) {
        string direction = directions.top();
        directions.pop();
        cout << direction << ", ";
    }

        return 0;
}