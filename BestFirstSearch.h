#ifndef SECONDPART_BESTFIRSTSEARCH_H
#define SECONDPART_BESTFIRSTSEARCH_H

#include "Searchable.h"
#include "Searcher.h"

class BestFirstSearch: public Searcher {
    std::vector<MyState> search (Searchable * searchable) override ;
};



#endif //SECONDPART_BESTFIRSTSEARCH_H
