#ifndef SECONDPART_MAZEMATRIX_H
#define SECONDPART_MAZEMATRIX_H

#include <sstream>

#include "Searchable.h"

using namespace std;

class MazeMatrix : public Searchable {
    vector<vector<MyState *> > states;
    Id src;
    Id trg;

    Id getSpecialState(const string &line);

    void saveMatrixRow(const string &row, int rowNum);

public:
    explicit MazeMatrix(vector<string> data);

    vector<MyState *> getAllPossibleStates(const MyState &s) override;

    bool isGoalState(const MyState &state) override {
        return trg == state.getStateId();
    }

    MyState *getInitialState() override {
        return states[src.row][src.col];
    }

    MyState *getGoal() override {
        return states[trg.row][trg.col];
    }

    ~MazeMatrix() override {
        auto it = states.begin();
        for (; it != states.end(); ++it) {
            auto inner = it->begin();
            for (; inner != it->end(); ++inner) {
                delete *inner;
            }
        }
    }
};

#endif