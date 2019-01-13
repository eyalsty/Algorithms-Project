#ifndef SECONDPART_SEARCHER_H
#define SECONDPART_SEARCHER_H


#include "Searchable.h"

class ISearcher {
public:
    virtual std::vector<MyState *> search(Searchable *searchable) = 0;

    virtual int getEvaluatedCounter() = 0;

    virtual std::vector<MyState *> traceBack(MyState *trg) = 0;

    virtual ~ISearcher() {}
};


#endif