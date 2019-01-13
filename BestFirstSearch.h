#ifndef SECONDPART_BESTFIRSTSEARCH_H
#define SECONDPART_BESTFIRSTSEARCH_H

#include <queue>
#include <set>

#include "Searcher.h"

struct comparator {
    bool operator()(MyState *l, MyState *r) {
        return l->getMinPath() > r->getMinPath();
    }
};

typedef std::priority_queue<MyState *, std::vector<MyState *>, comparator>
        My_priority_queue;

class BestFirstSearch : public Searcher {
public:
    std::vector<MyState *> search(Searchable *searchable) override;

    My_priority_queue updateQueue(My_priority_queue open);
};


#endif