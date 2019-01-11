#ifndef SECONDPART_SEARCHSOLVER_H
#define SECONDPART_SEARCHSOLVER_H


#include "Searcher.h"
#include "Solver.h"
#include "Searchable.h"

class SearchSolver:public Solver< Searchable*, std::vector<State<MyState>>> {
private:
    Searcher* searcher;
public:
    std::vector<State<MyState>> solve(Searchable * searchable) {
        return this->searcher->search(searchable);
    }


};
#endif