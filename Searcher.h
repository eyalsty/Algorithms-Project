#ifndef SECONDPART_ISEARCHER_H
#define SECONDPART_ISEARCHER_H

#include "ISearcher.h"

class Searcher : public ISearcher {

public:
    int evaluatedNodes;
    Searcher() : evaluatedNodes(0) {}

    std::vector<MyState *> traceBack(MyState *node) override;

    int getEvaluatedCounter() override {
        return evaluatedNodes;
    }

};

#endif //SECONDPART_SEARCHER_H
