#ifndef SECONDPART_MAZEMATRIX_H
#define SECONDPART_MAZEMATRIX_H

#include <sstream>

#include "Searchable.h"

using namespace std;

struct Id {
    int row;
    int col;

    Id() = default;

    Id(int _row, int _col) {
        row = _row;
        col = _col;
    }

    bool operator==(const Id &other) {
        return this->col == other.col && this->row == other.row;
    }
};

/* so if we will want to change the template argument, we will
 * do it only in one place. */
typedef State<Id> MyState;

class MazeMatrix : public Searchable<Id> {
    vector<vector<MyState>> states;
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