#ifndef SECONDPART_MAZEMATRIX_H
#define SECONDPART_MAZEMATRIX_H

#include <sstream>

#include "Searchable.h"

using namespace std;

class MazeMatrix : public Searchable {
    vector<vector<MyState> > states;
    Id src;
    Id trg;

    Id getSpecialState(const string &line);

    void saveMatrixRow(const string &row, int rowNum);

public:
    explicit MazeMatrix(vector<string> data);

    virtual vector<MyState> getAllPossibleStates(const State<Id> &s);

    virtual bool isGoalState(const MyState &state) {
        return trg == state.getStateId();
    }

    virtual MyState getInitialState() {
        return states[src.row][src.col];
    }
};

#endif