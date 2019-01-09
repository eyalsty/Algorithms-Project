#ifndef SECONDPART_STRINGREVERSER_H
#define SECONDPART_STRINGREVERSER_H

#include <iostream>
#include <algorithm>

#include "Solver.h"

using namespace std;

class StringReverser : public Solver<string, string> {
public:
    virtual string solve(const string &p) {
        string solution = p;
        reverse(solution.begin(), solution.end());
        return solution;
    }
};
#endif