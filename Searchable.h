#ifndef SECONDPART_SEARCHABLE_H
#define SECONDPART_SEARCHABLE_H

#include <string>
#include <vector>

#include "State.h"

template<class T>
class Searchable {
public:
    //virtual void create(std::vector<std::string> data) = 0;

    virtual bool isGoalState(const State<T> &state) = 0;

    virtual State<T> getInitialState() = 0;

    virtual std::vector<State<T>> getAllPossibleStates(const State<T> &s) = 0;

    virtual ~Searchable() {}
};
#endif