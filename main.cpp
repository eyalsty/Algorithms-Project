#include <iostream>
#include <algorithm>

#include "StringReverser.h"
#include "FileCacheManager.h"

using namespace std;


int main() {
    string problem = "AAA";
    string solution = problem;
    reverse(solution.begin(), solution.end());
    CacheManager *cm = new FileCacheManager;
    if (cm->isSolutionExists(problem)) {
        cout << cm->getSolutionFor(problem) << endl;
    } else {
        cout << "NOT!" << endl;
        cm->SaveSolution(problem,solution);
    }
    if (cm->isSolutionExists("WOW")) {
        cout << cm->getSolutionFor("WOW") << endl;
    } else {
        cout << "NOT!" << endl;
        cm->SaveSolution("WOW","WWWOOOWWW");
    }
    delete cm;
    return 0;
}