#ifndef SECONDPART_DFS_H
#define SECONDPART_DFS_H

#include "Searchable.h"
#include "Searcher.h"

#include <stack>

class DFS : public Searcher {
    std::stack<MyState *> stack;
    int evaluatedNodes;

public:
    DFS() : evaluatedNodes(0) {}

    std::vector<MyState*> search(Searchable *graph) override;

    std::vector<MyState*> traceBack(MyState *node) override;

    int getEvaluatedCounter() override {
        return evaluatedNodes;
    }
};
#endif