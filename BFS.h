#ifndef SECONDPART_BFS_H
#define SECONDPART_BFS_H


#include <queue>
#include <algorithm>
#include "Searcher.h"

class BFS : public Searcher {
public:
    std::vector<MyState *> search(Searchable *searchable) override;
};


#endif