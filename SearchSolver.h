#ifndef SECONDPART_SEARCHSOLVER_H
#define SECONDPART_SEARCHSOLVER_H


#include "Searcher.h"
#include "Solver.h"
#include "Searchable.h"

class SearchSolver : public Solver<Searchable *, std::vector<MyState*>> {
private:
    Searcher *searcher;
public:
    std::vector<MyState*> solve(Searchable *const &searchable) {
        return this->searcher->search(searchable);
    }

    ~SearchSolver() {

    }
};

#endif