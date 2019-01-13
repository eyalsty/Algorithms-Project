#include "MazeMatrix.h"

MazeMatrix::MazeMatrix(vector<string> data) {
    auto itBegin = data.begin();
    auto itEnd = --data.end();  // iterator for the last element.

    // setting source & target states id.
    trg = getSpecialState(*itEnd);
    --itEnd;
    src = getSpecialState(*itEnd);

    // setting the nodes\states of the matrix.
    for (int rowNum = 0; itBegin != itEnd; ++itBegin, ++rowNum) {
        saveMatrixRow(*itBegin, rowNum);
    }
}

Id MazeMatrix::getSpecialState(const string &line) {
    stringstream ss(line);
    int row, col;
    char comma;

    // creating the special State ID.
    ss >> row >> comma >> col;
    Id id(row, col);

    return id;
}

void MazeMatrix::saveMatrixRow(const string &row, int rowNum) {
    int colNum = 0;
    double cost;
    vector<MyState *> stateLine;
    stringstream ss(row);

    while (ss >> cost) {
        // getting a specific state. its Id is its index.
        Id id(rowNum, colNum);
        MyState *s = new MyState(id, cost);

        // saving the node in its correct row.
        stateLine.push_back(s);
        if (ss.peek() == ',') {
            ss.ignore();
        }
        ++colNum;
    }
    // saving the row in the State matrix.
    states.push_back(stateLine);
}

bool MazeMatrix::isStateNotInf(int row, int col) {
    return states[row][col]->getEdgeCost() != INF;
}

vector<MyState *> MazeMatrix::getAllPossibleStates(const MyState &s) {
    vector<MyState *> adj;
    Id sId = s.getStateId();
    // number of cols and rows of the maze matrix.
    int colsNum = states.at(0).size();
    int rowsNum = states.size();

    // checks for limits, and add adj accordingly.
    if (sId.row > 0 && isStateNotInf(sId.row - 1, sId.col)) {
        adj.push_back(states[sId.row - 1][sId.col]);
    }
    if (sId.row < rowsNum - 1 && isStateNotInf(sId.row + 1, sId.col)) {
        adj.push_back(states[sId.row + 1][sId.col]);
    }
    if (sId.col > 0 && isStateNotInf(sId.row, sId.col - 1)) {
        adj.push_back(states[sId.row][sId.col - 1]);
    }
    if (sId.col < colsNum - 1 && isStateNotInf(sId.row, sId.col + 1)) {
        adj.push_back(states[sId.row][sId.col + 1]);
    }
    return adj;
}