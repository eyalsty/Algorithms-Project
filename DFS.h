#ifndef SECONDPART_DFS_H
#define SECONDPART_DFS_H

#include "Searcher.h"

#include <stack>

class DFS : public Searcher {
    std::stack<MyState *> stack;

public:
    std::vector<MyState*> search(Searchable *graph) override;

};
#endif