#ifndef SECONDPART_SEARCHABLE_H
#define SECONDPART_SEARCHABLE_H

#include <string>
#include <vector>

#include "State.h"

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

/* so if we will want to change the template argument (note that now its Id),
 * we will need to do it only in one place. */
typedef State<Id> MyState;

class Searchable {
public:

    virtual bool isGoalState(const MyState &state) = 0;

    virtual MyState* getInitialState() = 0;

    virtual std::vector<MyState*> getAllPossibleStates(const MyState &s) = 0;

    virtual ~Searchable() {}
};
#endif