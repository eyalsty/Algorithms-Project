#ifndef SECONDPART_BFS_H
#define SECONDPART_BFS_H


#include <queue>
#include <algorithm>
#include "Searchable.h"
#include "Searcher.h"

class BFS : public Searcher {
private:
    int evaluatedCounter = 0;
public:
    std::vector<MyState *> search(Searchable *searchable) override;

    int getEvaluatedCounter() override;

    std::vector<MyState *> traceBack(MyState *trg) override;


};


#endif