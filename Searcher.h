#ifndef SECONDPART_ISEARCHER_H
#define SECONDPART_ISEARCHER_H

#include "ISearcher.h"

class Searcher : public ISearcher {
protected:
    int evaluatedNodes;

public:
    Searcher() : evaluatedNodes(0) {}

    std::vector<MyState *> traceBack(MyState *node) override;

    int getEvaluatedCounter() override {
        return evaluatedNodes;
    }

};

#endif //SECONDPART_SEARCHER_H
