#include <iostream>
#include <algorithm>

#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "MazeMatrix.h"
#include "BFS.h"

using namespace std;


int main() {


    // checks for the MazeMatrix Class !
    vector<string> matrix = {"1,2,3,4",
                             "5,6,7,8",
                             "9,10,11,12",
                             "13,14,15,16",
                             "0,0",
                             "3,3"};
    Searchable *searchable = new MazeMatrix(matrix);
    Searcher *searcher = new BFS;
    vector<MyState*> solution = searcher->search(searchable);
    int n = searcher->getEvaluatedCounter();

    return 0;
}