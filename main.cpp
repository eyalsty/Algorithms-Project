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

typedef Solver<Searchable *, vector<MyState *> > MySolver;


void getMatrix(vector<string>& matrix, ifstream& file,int& counter){
    string line;
    if(!matrix.empty()){
        matrix.clear();
    }
    while (getline(file, line)) {

        if (line[line.length() - 1] == '\r') {
            line = line.substr(0, line.length() - 1);
        }

        if(line == "$"){
            ++counter;
            break;
        }
        matrix.push_back(line);
    }
}



int main() {
    const char *fileName = "graphs.txt";
    const char* fileName2 = "solution.txt";

    int counter = 0;
    vector<string> matrix;

    ifstream file(fileName);
    ofstream file2(fileName2);
    if (!file || !file2) {
        cout << "ERROR reading from file" << endl;
    }

    while (counter != 10) {

        getMatrix(matrix,file,counter);

        ISearcher *bestFirstSearch = new BestFirstSearch();
        MySolver *solver = new SearchSolver(bestFirstSearch);

        Searchable *searchable = new MazeMatrix(matrix);
        vector<MyState *> solution = solver->solve(searchable);

        int nodeNum = bestFirstSearch->getEvaluatedCounter();
        double minPath = searchable->getGoal()->getMinPath();

        file2 << minPath << ',' << nodeNum << endl;

        delete bestFirstSearch;
        delete solver;
        delete searchable;
    }

    file.close();
    file2.close();
    return 0;
}